#include<bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define ll long long
#define itn int
//#define int ll
using namespace std;
const int MOD1=1e9+7;
const int MOD2=998244353;
const int N=1e6+5;
int n,q;
string a,b;
map<string,string> s;
void Solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		s[a]=b;
	}
	for(int i=1;i<=q;i++){
		cin>>a>>b;
		int ans=0;
		if(a.length()!=b.length()){
			cout<<0<<endl;
			continue;
		}
		int l=-1,r=-1,m=a.length();
		for(int i=0;i<m;i++){
			if(a[i]!=b[i]){
				if(l==-1)l=i;
				else r=i;
			}
		}
		for(int i=0;i<=l;i++){
			string x=a.substr(i,r-i);
			string y=b.substr(i,r-i);
			for(int j=r;j<m;j++){
				x+=a[j],y+=b[j];
//				cerr<<l<<' '<<r<<' '<<x<<' '<<y<<endl;
				if(s[x]==y){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--)
		Solve();
	return 0;
}
