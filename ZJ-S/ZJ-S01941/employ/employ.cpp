#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long n,m,t[505],ans,c[505],l;
string s;
bool f;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	f=0;
	for(int i=1;i<=n;i++){
		t[i]=s[i-1]-'0';
		if(t[i]==0){
			f=1;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			f=1;
		}
	}
	if(m==n){
		if(f){
			cout<<0;
			return 0;
		}
		else{
			for(int i=1;i<=n;i++){
				ans*=i;
				ans%=MOD;
			}
			cout<<ans;
			return 0;
		}
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(t[i]==1){
				for(int j=1;j<=n;j++){
					if(c[j]>i){
						l++;
					}
				}
				ans=l;
				for(int j=1;j<n;j++){
					ans*=j;
					ans=ans%MOD;
				}
				cout<<ans;
				return 0;
			}
		}
	}
	return 0;
}
