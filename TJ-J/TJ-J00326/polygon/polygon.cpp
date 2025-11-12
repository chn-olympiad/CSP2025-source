#include <bits/stdc++.h>

using namespace std;

int n,a[5005],sum,maxx;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	if(n < 3){
		cout<<0;
	}
	else if(n == 3){
		for(int i = 1;i<=3;i++){
			sum+=a[i];
			maxx = max(maxx,a[i]);
		}
		if(sum>2*maxx){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	return 0;
}
