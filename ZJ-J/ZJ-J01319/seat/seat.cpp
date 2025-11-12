#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,x,ans,sum1,sum2,a[10010];
bool cmp(int q,int h){
	return q>h;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)cin>>a[i];
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(i=1;i<=n*m;i++)
		if(a[i]==x)ans=i;
	if(ans%n==0)sum1=ans/n;
	else sum1=ans/n+1;
	if(sum1%2==1){
		if(ans%n==0)sum2=n;
		else sum2=ans%n;
	}
	else{
		if(ans%n==0)sum2=1;
		else sum2=n-ans%n+1;
	}
	cout<<sum1<<" "<<sum2;
}
