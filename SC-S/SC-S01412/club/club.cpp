#include <bits/stdc++.h>
using namespace std;
const int maxn=114514;
int a[maxn][4],f[maxn],s[4],ans,flag=0,n,T;//表示第
bool cmp(int x,int y){
	return x>y;
}
void dfs(int x,int val){
	if(x==n){
		for(int i=1;i<=3;i++){
			if(s[i]>=n/2) continue;
			ans=max(ans,val+a[x][i]);
			/*if(val+a[x][i]>ans){
				ans=val+a[x][i];
				printf("xsdggdf(%d) %d\n",i,ans);
			}*/
			//printf("%d of %d:%d\n",x,i,val+a[x][i]);
		}
		return;
	}
	for(int i=1;i<=3;i++){
		if(s[i]>=n/2) continue;
		s[i]++;
		//printf("%d of %d : %d\n",x,i,val+a[x][i]);
		dfs(x+1,val+a[x][i]);
		s[i]--;
	}
}
void work(){
	memset(s,0,sizeof(s));
	ans=-1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
		if(a[i][2]!=0 || a[i][3]!=0) flag=1;
	}
	if(flag==0){
		for(int i=1;i<=n;i++) f[i]=a[i][1];
		sort(f+1,f+n+1,cmp);
		ans++;
		for(int i=1;i<=n/2;i++) ans+=f[i];
		printf("%d\n",ans);
		return;
	}
	if(n<=200){
		dfs(1,0);
		printf("%d\n",ans);
		return;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--) work();
	return 0;
}