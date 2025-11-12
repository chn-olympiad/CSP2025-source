#include<bits/stdc++.h>
#define maxn 505
#define mod 998244353
using namespace std;
int m,n,c[maxn];string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	unsigned long long ans=1;
	for(int i=1;i<=n;i++) ans=(ans*i)%mod;
	cout<<ans;
} 
