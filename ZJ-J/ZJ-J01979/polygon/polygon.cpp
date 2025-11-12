#include<bits/stdc++.h>
using namespace std;
int a[5050],p[5050],n;
bool check(int i){
	int j=n-1,sum=0,mx=0,ct=0;
	while(i){
		if(i%2==1){
			sum+=a[j];
			mx=max(a[j],mx);
			ct++;
		}
		j--;
		i/=2;
	}
	return (sum>mx*2) and ct>=3;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int i,j=1;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	long long cnt=0;
	for(i=0;i<n;i++){
		j*=2;
	}
	for(i=0;i<j;i++){
		if(check(i)) cnt++;
	}
	cout<<cnt%998244353;
	return 0;
}

