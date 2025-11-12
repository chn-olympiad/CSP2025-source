#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,mod=998244353;
int n,m,c[N],a[N],ans;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n==m){
		bool flag=true;
		for(int i=0;i<n;i++)
			if(s[i]=='0'){
				flag=false;
				break;
			}
		if(flag){
			ans=1;
			for(int i=2;i<=n;i++){
				ans*=i;
				ans%=mod;
			}
		}
	}
	else if(m==1){
		ans=1;
		for(int i=2;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
	}
	else{
		int sum=0;
		for(int i=0;i<n;i++)
			if(s[i]=='1') sum++;
		if(sum<m){
			cout<<0;
			return 0;
		}
		if(sum==n){
			ans=1;
			for(int i=2;i<=n;i++){
				ans*=i;
				ans%=mod;
			}
		}
		else{
			for(int i=1;i<=n;i++) a[i]=i;
			do{
				int fail=0,ss=0;
				for(int i=1;i<=n;i++){
					if(fail<c[a[i]]&&s[i-1]=='1') ss++;
					else fail++;
				}
				if(ss>=m) ans++,ans%=mod;
			}while(next_permutation(1+a,1+a+n));
		}
	}
	cout<<ans;
	return 0;
}
