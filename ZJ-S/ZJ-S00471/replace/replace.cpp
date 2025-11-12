#include<iostream>
#define int long long
const int N=2e5+10;
using namespace std;
int n,q;
string s[N][2];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	while(q--){
		string t1,t2;cin>>t1>>t2;
		int m=t1.length(),ans=0;t1=" "+t1,t2=" "+t2;
		for(int i=1;i<=n;i++){
			int op=s[i][0].length();
			for(int j=1;j+op-1<=m;j++){
				string x=t1.substr(0,j),y=t1.substr(j,op),z=t1.substr(j+op,m-j-op+1);
				if(y!=s[i][0])continue;
				string to=x+s[i][1]+z;
				if(to==t2)ans++;
			}
		}cout<<ans<<'\n';
	}
	return 0;
}
