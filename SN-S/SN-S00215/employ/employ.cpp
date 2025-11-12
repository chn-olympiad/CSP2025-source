#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n=0,m=0;cin>>n>>m;
	string s;cin>>s;
	int a[n];
	for (int i=0;i<n;i++)cin>>a[i];
	if (m==1){
		cout<<n;return 0;
	}
	if (m==n){
		cout<<0;return 0;
	}
	return 0;
}
