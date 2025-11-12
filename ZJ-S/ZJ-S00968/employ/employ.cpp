#include<bits/stdc++.h>
using namespace std;

const long long MOD=998244353;

int n,m,z=0;
bool flag=true;
string s;

int main() {

	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	cin>>n>>m;
	cin>>s;
	for(int i=0; i<n; i++) {
		if(s[i]!='1') {
			flag=false;
		}
		else	z++;
	}
	int x;
	for(int i=1; i<=n; i++)
		cin>>x;
	long long ans=1;
	if(z<m) {
		cout<<"0"<<endl;
		return 0;
	}
	if(flag==true) {
		for(int i=1; i<=n; i++) {
			ans*=i;
			ans%=MOD;
		}
		cout<<ans<<endl;
	} else if(m==n&&flag==false) cout<<"0"<<endl;

	return 0;
}