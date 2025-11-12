#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005],p[5005],mx,d,l;
const long long MOD=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=((long long)(1)<<n);i++){
		int q=i;
		for(int j=1;j<=n;j++){
			p[j]=q%2;
			q/=2;
		}
		mx=0;
		long long ans=0;
		for(int j=1;j<=n;j++){
			if(p[j]){
				ans+=a[j];
				d++;
				mx=max(mx,a[j]);
			}
		}
		if(ans>mx*2&&d>=3){
			l++;
			l%=MOD;
		}
	}
	cout<<l;
	return 0;
}
