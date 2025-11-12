#include<bits/stdc++.h>
using namespace std;
long long a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,ret1=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a,a+n+1);
	for(int i=3;i<=n;i++){
		for(int l=1;l<n-i+1;l++){
			long long ret=a[l];
			for(int r=l+1;r<l+i;r++)ret+=a[r];
			if(ret>2*a[l+i-1])ret1++;
		}
	}
	cout<<ret1%998244353;
	return 0;
} 
