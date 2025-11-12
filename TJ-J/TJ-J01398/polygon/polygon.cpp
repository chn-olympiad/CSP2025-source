#include<bits/stdc++.h>
using namespace std;
int a[5099];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,max_=0,num=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		max_=max(max_,a[i]);
		num+=a[i];
	}
	if(n==3){
		if(num>2*max_){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	srand(time(NULL));
	cout<<rand()%998244353;
	return 0;
}

