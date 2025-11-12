#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long ans,n,a[505],h[505],m;
string s;
long long f,l;
bool v[505];
long long p(int x){
	long long res=1;
	for(int i=1;i<=x;i++)res=res*i%mod;
	return res;
}
void dfs(int c,int t){
//	cout<<c<<t<<"\n";
	if(t>=m){
	//	cout<<n-c+1<<" ";
		ans+=p(n-c+1);
		ans%=mod;
		return ;
	}
	if(c==n+1||h[c]>t)return;
	for(int i=1;i<=n;i++){
		if(v[i])continue;
		v[i]=1;
		if((s[c-1]=='0')||(c-1-t>=a[i]))dfs(c+1,t);
		else dfs(c+1,t+1);
		v[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<n;i++)if(s[i]=='0')f++;
	h[n+1]=m;
	for(int i=n;i>=1;i--){
		h[i]=h[i+1]-1+(s[i-1]=='0');
	}for(int i=n;i>=1;i--){
		if(!a[i])l++;
	}
	if(n-f<m){
		cout<<0;
		return 0;
	}
	if(m==n){
		if(f!=0||l==0)cout<<0;
		else cout<<p(n);
		return 0;
	}
	dfs(1,0);
	cout<<ans%mod;
	return 0;
}