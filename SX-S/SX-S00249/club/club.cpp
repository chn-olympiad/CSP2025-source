#include<bits/stdc++.h>
using namespace std;
int T,n,ta,tb,cnt,ans,s[3];
struct node{
	int x,y,z;
}a[100010];
bool cmp(node p,node q){
	return p.x>q.x;
}
void dfs(int k){
	if(k==n+1){
		ans=max(ans,cnt);
		return;
	}
	for(int i=1;i<=3;i++){
		if(s[i]<n/2){
			if(i==1){
				cnt+=a[k].x;
				s[i]++;
				dfs(k+1);
				s[i]--;
				cnt-=a[k].x;
			}
			if(i==2){
				cnt+=a[k].y;
				s[i]++;
				dfs(k+1);
				s[i]--;
				cnt-=a[k].y;
			}
			if(i==3){
				cnt+=a[k].z;
				s[i]++;
				dfs(k+1);
				s[i]--;
				cnt-=a[k].z;
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%d",&n);
		ta=tb=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].y==0) ta++;
			if(a[i].z==0) tb++;
		}
		if(ta==tb&&ta==n){
			ans=0;
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++) ans+=a[i].x;
			printf("%d\n",ans);
			continue;
		}
		ans=cnt=0;
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}