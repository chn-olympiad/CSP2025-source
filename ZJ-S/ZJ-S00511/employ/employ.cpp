#include<bits/stdc++.h>
using namespace std;
const int N=510,mod=998244353;
int c[N];
int n,m;
vector<int>v;
int pos[N];
bool f[N];
long long ans=0;
long long res;
void dfs(int u,int num,int cnt){
	if(u==v.size()){
		if(cnt>=m)ans=(ans+res)%mod;
		return;
	}
	for(int i=0;i<n;i++){
		if(f[i])continue;
		f[i]=true;
		dfs(u+1,num+(v[u]+num>=c[i]),cnt+!(v[u]+num>=c[i]));
		f[i]=false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	string s;
	cin>>s;
	int l=0,sum=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')sum++,l++;
		else v.push_back(sum);
	}
	for(int i=0;i<n;i++)cin>>c[i];
	res=1;
	for(int i=2;i<=l;i++)res=(long long)(res*i)%mod;
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
