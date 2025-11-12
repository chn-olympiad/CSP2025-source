#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[5005],st[5005],ans,n;
void fun(int x,long long sum,long long maxx){
	if(x>n){
		int t=0;
		for(int i=1;i<=n;i++)if(st[i])t++;
		if(t>=3&&sum>maxx*2)ans++;
		return ;
	}
	st[x]++;
	fun(x+1,sum+a[x],max(maxx,a[x]));
	st[x]--;
	fun(x+1,sum,maxx);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	fun(1,0,0);
//	for(int i=1;i<=n-2;i++){
//		int sum=a[i]+a[i+1];
//		int maxx=max(a[i],a[i+1]);
//		for(int j=i+2;j<=n;j++){
//			sum+=a[j];
//			maxx=max(maxx,a[j]);
//			if(sum>maxx*2)ans++;
//		}
//	}
	cout<<ans;
	return 0;
}
