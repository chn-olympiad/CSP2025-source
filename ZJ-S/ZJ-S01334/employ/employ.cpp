#include<bits/stdc++.h>
#define N 505
using namespace std;
int n,m,ans,s[N],c[N],v[N];
void dfs(int x,int y){
	for(int i=1;i<=n;i++){
		if(x==n){
			if(y>=m)ans++;
			return;
		}
		if(v[i])continue;
		v[i]=1;
		dfs(x+1,y+(c[i]>s[i]));
		v[i]=0;
	}
}
int main(){
 	freopen("employ.in","r",stdin);
 	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		s[i+1]=s[i]+'1'-x;
		cout<<s[i];
	}
	cout<<"\n";
	for(int i=1;i<=m;i++)scanf("%d",&c[i]);
	sort(c+1,c+n+1);
	dfs(0,0);
	cout<<ans;
}