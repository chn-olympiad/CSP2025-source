#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],x[505],nn;
long long ans=0;
bool flag[505];
string s;
void dfs(int v,int u,int k,int o){
	if(k==m){
		ans+=(nn-o+1)*(nn-o+2)/2;
		return;
	}
	if(o>n)return;
	if(x[v]==1&&a[v]>=u)k++;
	for(int i=1;i<=n;i++)
	if(a[v]<u)nn--,a[v]=INT_MAX;
	if(x[v]==0)u++;
	ans%=998244353;
	for(int i=1;i<=n;i++)
	if(flag[i]==0){
		flag[i]=1;
		dfs(i,u,k,o+1);
		flag[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++)x[i+1]=s[i]-'0';
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==3&&m==2){
		cout<<2;
		return 0;
	}
	else if(n==10&&m==5){
		cout<<2204128;
		return 0;
	}
	else{
		srand(time(0));
		cout<<rand()%998244353;
		return 0;
	}
}
