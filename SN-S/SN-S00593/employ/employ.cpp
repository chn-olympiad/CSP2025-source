#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ3.in","r",stdin);
	freopen("employ111111.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m;
	cout<<n<<endl;
	vector<int> ceiling(n);
	for(int i=0;i<n;i++){
		cin>>ceiling[i];
	}
	int ans=1;
	for(int i=n;i>0;i--){
		ans*=i;
	}
	cout<<ans%998244353;
	return 0;
}
