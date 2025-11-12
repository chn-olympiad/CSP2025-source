#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[555],num=1;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	num=a[0];
	for(int i=1;i<=n;i++){
		num*=i;
	}
	if(m==n){
		cout<<num;
	}
	return 0;
}

