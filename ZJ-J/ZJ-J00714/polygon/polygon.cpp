#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5000+100;
ll n,a[N],dis[N],cnt,mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dis[i]=dis[i-1]+a[i];
	}
	if(n==3){
		sort(a+1,a+n+1);
		if(dis[n]>a[n]*2) cnt=1;
		cout<<cnt;
		return 0;
	}
	return 0;
}