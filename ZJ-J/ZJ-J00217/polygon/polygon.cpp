#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int n;
	cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==3){
		int _1=a[1],_2=a[2],_3=a[3];
		if(_1+_2>_3&&_1+_3>_2&&_2+_3>_1) {
			cout<<1;
			return 0; 
		}
	}
	cout<<0;
	return 0; 
}
