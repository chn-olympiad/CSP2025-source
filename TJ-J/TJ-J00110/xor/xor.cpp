#include<bits/stdc++.h>
#define ll long long;
using namespace std;
int main(){
	/*
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	*/
	int n;
	int a[500005];
	ll k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll sum=0;
	ll num=0;
	for(int i=1;i<=n;i++){
		sum=0;
		for(int j=1;j<=i;j++){
			sum+=sum^a[j];
		}
		if(sum==k) num++:
	}
	cout<<num;
	return 0;
}
