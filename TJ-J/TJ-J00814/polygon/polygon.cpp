#include <bits/stdc++.h>
using namespace std;
/*long long c(int n,m){
	int r=1;
	for(int i = 1+m; i <=n; i++){
		r*=i;
	}
	for(int )
	return r;
}*/
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	int n;
	vector<int> a;
	cin>>n;
	for(int i = 0; i<n; i++){
		int k;
		cin>>k;
		a.push_back(k);
	}
	for(int i = 0; i < a.size(); i++){
		for(int j = i; j < a.size(); j++){
			if(a[j]<a[i]){
				swap(a[i],a[j]);
			}
		}
	}
	if(n==3){
		if(a[2]>=a[0]+a[1]){
			cout<<0;
			return 0;
		}
		else{
			cout<<1;
			return 0;
		}
	}
/*	if(a[n-1]==1){
		long long ans = 0
		for(int m = n; m>=3){
			
		}
	}*/
    return 0;
	
}

