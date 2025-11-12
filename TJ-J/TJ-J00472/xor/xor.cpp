#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
long long n,t=3,r=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		a[i]+=a[i-1];
	}
	while (t<=n){
		for(int i=1;i<=n-3;i++){
			if(a[i+t-1]-a[i-1]>a[i+t]) r+=1;
		}
		t++;
	}
	cout<<r;
	return 0;
}
