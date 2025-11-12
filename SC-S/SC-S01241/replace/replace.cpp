#include<bits/stdc++.h>
#define ri register long long
#define int long long
#define rll register long long
#define ll long long
#define pint pair<int,int>
#define endl '\n'
using namespace std;
const int N=2e5+5,p=1e9+7,L=5e6+5;
int n,q;
unsigned ll pw[L];
string s1[N],s2[N];
string t1[N],t2[N];
unsigned hh1[L],hh2[L];
map<unsigned ll,map<unsigned ll,int> >mp;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	pw[0]=1;
	for(ri i=1;i<=L;i++)pw[i]=pw[i-1]*p;
	for(ri i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		unsigned ll h1=0,h2=0;
		for(ri j=0;j<s1[i].size();j++){
			h1=h1*p+s1[i][j];
			h2=h2*p+s2[i][j];
		}
		//cout<<h1<<" "<<h2<<endl;
		mp[h1][h2]++;
	}
	int ans=0;
	for(ri i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
		for(ri j=1;j<=t1[i].size();j++){
			hh1[j]=hh1[j-1]*p+t1[i][j-1];
			hh2[j]=hh2[j-1]*p+t2[i][j-1];
		}
		for(ri l=0;l<t1[i].size();l++){
			for(ri r=l+1;r<=t1[i].size();r++){
				unsigned ll h11=hh1[r]-hh1[l]*pw[r-l],h22=hh2[r]-hh2[l]*pw[r-l];
				//cout<<h11<<" "<<h22<<endl;
				ans+=mp[h11][h22];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
