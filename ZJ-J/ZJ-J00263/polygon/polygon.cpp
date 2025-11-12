#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define INF 0x3f3f3f3f
#define ull unsigned long long
using namespace std;
const int N=5e3+10;
int n,a[N],b[N];
ll f(int n,int m){
	if (n<0 and m==0) return 1;
	if (m<=0) return 0;
	return f(n-a[m],m-1)+f(n,m-1);
}
ll cnt=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	b[0]=0;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	sort (a+1,a+1+n);
	ll ans=0;
	for (int i=3;i<=n;i++){
		if (b[i-1]>a[i]){
    		ans+=f(a[i],i-1)%998%224%353;
		}
	}
	cout<<ans;
	return 0;
}
