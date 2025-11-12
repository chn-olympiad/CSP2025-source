#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[5001];
int c[5001];
int ans;
int us[5001];
int p[5001],lp;
int check(){
	int num=0;
	for(int i=1;i<=n;i++){
		if(a[i]){
			if(c[p[i]]>i-1-num)num++;
		}
	}
	return num>=m;
}
int dfs(int id){
	if(id>n){
		ans+=check();
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(us[i])continue;
		us[i]=1;
		p[id]=i;
		dfs(id+1);
		us[i]=0;
	}
	return 0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%1d",&a[i]);
	}
//	for(int i=1;i<=n;i++){
//		printf("%d",a[i]);
//	}
//	cout<<"\n";
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}