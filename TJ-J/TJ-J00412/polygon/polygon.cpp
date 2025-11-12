#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	if(n==3){
		int sum=0;
		if(a[0]+a[1]+a[2]>2*max(a[0],a[1])&&a[0]+a[1]+a[2]>2*max(a[2],a[1])) sum++;
		cout<<sum;
		return 0;
	}
	int s=0;
	for(int i=0;i<n;i++){
		s+=a[i];
	}
	if(s==n){
		s=0;
		cout<<n-2;
		return 0;
	}
	long long t=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int sum=0;
			int m=0;
			for(int l=i;l<=j;l++){
				sum+=a[l];
				if(a[l]>m) m=a[l];
			}
			if(sum>2*m) t++;
		}
	}
	cout<<(t%998244353);
	//我不会我不会我不会o(╥﹏╥)o 
	return 0;
}
