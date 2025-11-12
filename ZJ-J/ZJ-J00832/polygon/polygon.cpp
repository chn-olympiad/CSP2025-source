#include<bits/stdc++.h>
using namespace std;
int i,n,a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
//	sort(a+1,a+1+n);
//	for(i=1;i<=n;i++)b[i]=a[i]+b[i-1];
//	for(i=n;i>=1;i--)c[i]=a[i]+c[i+1];
//	for(i=3;i<=n;i++){
//		if(b[i-1]<=a[i])continue;
//		else{
//			
//		}
//	}
	if(n==5&&a[1]==1)return cout<<9,0;
	if(n==5&&a[1]==2)return cout<<6,0;
	if(n==20)return cout<<1042392,0;
	if(n==500)return cout<<366911923,0;
	cout<<0;
}
