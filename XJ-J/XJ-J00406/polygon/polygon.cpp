#include<bits/stdc++.h>
using namespace std;
int m=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0,ans=0,ma=-1e9;
	cin>>n;
	vector<int>a(n); 
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			sum+=a[j];
			if(a[j]>ma)ma=a[j];
			if(j>=3&&sum>2*ma)ans++;
		}
	}
	cout<<ans%m;
	return 0;
} 
