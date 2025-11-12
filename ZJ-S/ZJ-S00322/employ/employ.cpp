#include<iostream>
using namespace std;
const int N=510;
const int MOD=998244353;
int c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==1){
		int index;
		for(int i=0;i<n;i++){
			if(s[i]==1){
				index=i+1;
				break;
			}
		}
		int res=0;
		for(int i=1;i<=n;i++){
			if(c[i]<index)res++;
		}
		int ans=res;
		for(int i=n-1;i>=1;i--){
			ans%=MOD;
			ans*=i;
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		int ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=MOD;
		}
		cout<<ans;
		return 0;
	}
	int ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=MOD;
		}
		cout<<ans;
}
