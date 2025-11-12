#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+10;
const int MO=998244353;
int n,m;
string s;
int c[N];
void solves1(){
	int ans=1;
	for (int i=1; i<=n; i++){
		ans=(ans*i)%MO;
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	bool fl1=1;
	cin>>n>>m;
	cin>>s;
	s="?"+s;
	for (int i=1; i<=n; i++){
		cin>>c[i];
	}
	for (int i=1; i<s.size(); i++){
		if (s[i]!='1'){
			fl1=0;
		}
	}
	if (fl1){
		solves1();
		return 0;
	}
	return 0;
}