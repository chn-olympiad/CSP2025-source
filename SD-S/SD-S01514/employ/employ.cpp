#include<bits/stdc++.h>
using namespace std;
const int Maxn=1e6+500;
#define int long long
int result=1;
const int MoD=998244353;
int n,m;
int x;
signed main () {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x==0){
			cnt++;
		}
		result=(i*result)%MoD;
	}
	//cout<<cnt;
	//cout<<"\n";
	cout<<result;
	return 0;
}


