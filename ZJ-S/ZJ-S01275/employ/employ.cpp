#include<bits/stdc++.h>
using namespace std;
int n,m,a[100000],sum;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	cout<<sum/2;
	return 0;
}

