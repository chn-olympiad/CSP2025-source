#include<bits/stdc++.h>
using namespace std;
long long ans=0;
long long mans=0;
int n,t;
const int MAXN=1e5+5;
struct student{
	int a1;
	int a2;
	int a3;
}st[MAXN];
void dfs(int m,int c1,int c2,int c3){
	if(c1>(n>>1)||c2>(n>>1)||c3>(n>>1)){
		return ;
	}
	if(m>n){
		mans=max(mans,ans);
	}
	ans+=(long long)st[m].a1;
	dfs(m+1,c1+1,c2,c3);
	ans-=(long long)st[m].a1;
	

	ans+=(long long)st[m].a2;
	dfs(m+1,c1,c2+1,c3);
	ans-=(long long)st[m].a2;
	

	ans+=(long long)st[m].a3;
	dfs(m+1,c1,c2,c3+1);
	ans-=(long long)st[m].a3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>st[i].a1>>st[i].a2>>st[i].a3 ;
		}
		dfs(1,0,0,0);
		cout<<mans<<endl;
		mans=0;
		ans=0;
		memset(st,0,sizeof(st));
	}
	return 0;
}
