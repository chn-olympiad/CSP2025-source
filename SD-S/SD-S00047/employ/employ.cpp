#include<bits/stdc++.h>
using namespace std;
long long m,n,a[509],st[509],su=0;
char s[509];
void dfs(int x,int r,int j){
	if(x>n){
		if(j>=m)su++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(st[i]==1)continue;
		else if(r>=a[i]||s[x-1]=='0'){
			st[i]=1;
			dfs(x+1,r+1,j);
			st[i]=0;
		}
		else{
			st[i]=1;
			dfs(x+1,r,j+1);
			st[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	scanf("%s",s);
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,0);
	cout<<su;
	return 0;
}

