#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
#define fi first
#define se second
#define eb emplace_back
const int N=5e6+10;
map<pair<ull,ull>,int>mp;
ull w[N],ha1[N],ha2[N];
int n,q;
string s1,s2;
signed main(){
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		ull h1=0,h2=0;
		for(auto j:s1) h1=h1*202021+j;
		for(auto j:s2) h2=h2*202021+j;
		mp[{h1,h2}]++;
	}
	w[0]=1;
	for(int i=1;i<=N-10;i++) w[i]=w[i-1]*202021;
	while(q--){
//		clog <<q<<endl;
		cin>>s1>>s2;
		int l1=s1.size(),l2=s2.size();
		s1=" "+s1,s2=" "+s2;
		if(l1!=l2){cout <<"0\n";continue;}
		int l=0,r=0;
		for(int i=1;i<=l1;i++){
			ha1[i]=ha1[i-1]*202021+s1[i];
			ha2[i]=ha2[i-1]*202021+s2[i];
//			cout <<i<<' '<<ha1[i]<<' '<<ha2[i]<<"\n";
			if(s1[i]!=s2[i]){
				if(!l) l=i;
				r=i;
			}
		}
		ll ans=0;
		for(int i=1;i<=l;i++){
			for(int j=r;j<=l1;j++){
				ull h1=ha1[j]-w[j-i+1]*ha1[i-1],h2=ha2[j]-w[j-i+1]*ha2[i-1];
//				cout <<i<<' '<<j<<' '<<h1<<' '<<h2<<' '<<mp[{h1,h2}]<<"\n";
				ans+=mp[{h1,h2}];
			}
		}
		cout <<ans<<endl;
//		if(ans!=0) clog <<q<<"!!!!"<<endl;
//		if(q%100==0) clog <<q<<endl;
	}
	return 0;
}
/*
3 1
aa ab
aa ba
aaaaa aabaa
aaaaa aabaa
*/
