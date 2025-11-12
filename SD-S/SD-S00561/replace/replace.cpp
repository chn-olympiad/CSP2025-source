#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
#define pii pair<int,int>
using namespace std;

// rp++;

inline ll read(){
	ll x=0,w=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')w=-1;c=getchar();}
	while(c<='9'&&c>='0') x=x*10+c-'0',c=getchar();
	return x*w;
}

const int N=100050,M=1200000,inf=0x3f3f3f3f;
int n,q;
string s[N][2];
string t[2];

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int Q=1;Q<=q;Q++){
		cin>>t[0]>>t[1];
		int lt=t[0].size();
		int ans=0;
		for(int i=1;i<=n;i++){
			string s1=s[i][0],s2=s[i][1];
			int ls=s1.size();
//			cerr<<i<<" "<<lt<<" "<<ls<<endl;
			for(int j=0;j<=lt-ls;j++){
				bool K=1;
//				cerr<<j<<"\n";
				for(int k=0;k<j && K;k++) if(t[0][k]!=t[1][k]) K=0;
				for(int k=j+1;k<=j+ls-1 && K;k++) if(t[0][k]!=s1[k-j] || t[1][k]!=s2[k-j]) {
					K=0;
//					cerr<<t[0][k]<<s1[k-j]<<t[1][k]<<s2[k-j]<<endl;
				}
//				cerr<<j+ls<<" "<<lt<<endl;
				for(int k=j+ls;k<=lt && K;k++){
//					cerr<<t[0][k]<<t[1][k]<<endl;
					if(t[0][k]!=t[1][k]) K=0;
				}
//				if(K) cerr<<i<<endl;
				ans+=K;
			}
		}
		cout<<ans<<"\n";
	}
}
