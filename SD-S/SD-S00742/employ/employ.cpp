#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,sum,sum1;
int mod=998244353;
string s;
int c[100010];
int jie[100010];
int dp[1010][1010];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	jie[0]=1;
	for(int i=1;i<=n;i++){
		jie[i]=jie[i-1]*i;
		jie[i]%=mod;
	}
	for(int i=0;i<n;i++){
		sum+=(s[i]=='1');
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		sum1+=(c[i]==0);
	}
	if(m==n){
		if(sum!=n||sum1!=0){
			cout<<0;
		}else{
			cout<<jie[n];
		}
		return 0;
	}else if(m==1){
		sort(c+1,c+1+n);
		int ans=1,x=0;
		for(int i=0;i<n;i++){
			if(s[i]=='1'){
				int id=upper_bound(c+1,c+1+n,i)-c-1;
				if(id-x<0){
					cout<<0;
					return 0;
				}
				ans=(ans*(id-x))%mod;
				x++;
			} 
		}
		ans=ans*(jie[n-x])%mod;
		cout<<(jie[n]-ans+mod)%mod<<endl;
	}else{
		cout<<0<<endl;
	}
	return 0;
}


