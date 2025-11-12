#include<bits/stdc++.h>
#define ll long long
#define N 5005
#define mod 998244353
using namespace std;

int n,m,ans,sum;
int a[N],f[N*N];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	f[0]=1;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		for(int j=sum;j>=a[i];j--){
			(f[j]+=f[j-a[i]])%=mod;
			if(j>2*a[i])(ans+=f[j-a[i]])%=mod;
		}
	}
	cout<<ans;
	return 0;
}
