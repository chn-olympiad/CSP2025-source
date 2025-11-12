#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;
const ll P=998244353;
int n,a[N];
ll cnt[N],Pow[N],ans,sum;
void init(){
	Pow[0]=1;
	for(int i=1;i<=5000;i++)Pow[i]=Pow[i-1]*2%P;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	init();
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	cnt[0]=1;
	for(int i=1;i<=n;i++){
		sum=0;
		for(int j=0;j<=a[i];j++)sum=(sum+cnt[j])%P;
		ans=((ans+Pow[i-1]-sum)%P+P)%P;
		for(int j=5000;j>=a[i];j--)cnt[j]=(cnt[j]+cnt[j-a[i]])%P;
	}
	cout<<ans<<'\n';
	return 0;
}