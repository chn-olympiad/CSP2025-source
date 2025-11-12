#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505;
int n,m;
ll mod=998244353,ans=1;
string s;
int c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	bool ok=1;
	int len=s.length(); 
	for(int i=0;i<len;i++) if(s[i]!='1') ok=0;
	for(int i=1;i<=n;i++)
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) ans=ans*i%mod;
	if(n==m && !ok) cout<<0;
	else cout<<ans;
	return 0;
}
