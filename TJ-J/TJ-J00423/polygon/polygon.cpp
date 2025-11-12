#include <bits/stdc++.h>
using namespace std;
long long n;
long long s[5001];
long long a[5001];
long long x;
long long f(long long a[],long long l,long long r){
	long long Max=a[l];
	for(int i=l+1;i<=r;i++){
		if(a[i]>Max){
			Max=a[i];
		}
	} 
	return Max;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+2;j<=n;j++){
			if(s[j]-s[i-1]>2*f(a,i,j)){
				x++;
				cout<<i<<" "<<j<<endl;
			}
		}
	}
	cout<<x%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

