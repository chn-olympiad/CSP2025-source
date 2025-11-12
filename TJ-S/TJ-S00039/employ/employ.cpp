#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x != 0){
			cnt++;
		}
	}
	long long k = 1;
	for(int i=cnt;i>=1;i--){
		k *= i;
	}
	k = k % 998244353;
	cout<<k;
	return 0;
}
