#include<bits/stdc++.h>
using namespace std;
const int maxn=5e2+5;
const int mod=998244353;
int n,m,s[maxn],c[maxn];
long long ans=1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char a;cin>>a;
		s[i]=a-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];c[i]++;
	}
	sort(c+1,c+n+1);
	int del=0,res=0; 
	for(int i=1;i<=n;i++){
		if(c[i]<i-del){
			c[i]=-1;del++;
		}else res++;
	}
	for(int i=res;i>=1;i--){
		ans=(ans*i)%mod;
	}
	cout<<ans;
	return 0;
} 