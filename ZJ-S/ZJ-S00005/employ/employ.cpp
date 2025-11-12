#include<bits/stdc++.h>
using namespace std;
const int N=505,MOD=998244353;
int n,m,c[N],c1[N],sum;
bool vis[N];
char s[N],s1[N];
bool check(){
	int x=0,l=0;
	for(int i=1;i<=n;i++){
		if(s1[i]=='1' and x<c1[i]) l++;
		else x++;
	}
	if(l>=m) return true;
	else return false;
}
void dfs(int x){
	if(x==n+1 and check()==true) sum++;
	for(int i=1;i<=n;i++){
		if(vis[i]==false){
			vis[i]=true;
			c1[x]=c[i],s1[x]=s[i];
			dfs(x+1);
			vis[i]=false;
			c1[x]=0,s1[x]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<sum;
	return 0;
}
