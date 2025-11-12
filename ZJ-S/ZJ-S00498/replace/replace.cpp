#include<bits/stdc++.h>
#define ll long long
#define rep(i,x,y) for(int (i)=(x);(i)<=(y);++(i))
using namespace std;
const int N=5e6+10;
const int M=2e6+10;

ll n,m,ans=0;
string t1[N],t2[N],s1[N],s2[N];

void solve(){
    cin>>n>>m;
    rep(i,1,n){
    	cin>>s1[i]>>s2[i];
	}
	rep(i,1,m){
		ans=0;
		cin>>t1[i]>>t2[i];
		for(int j=1;j<=n;++j){
			int len=s1[j].size();
			for(int k=0;k+s1[j].size()-1<t1[i].size();++k){
//				cout<<s1[j]<<' '<<t1[i].substr(k,k+s1[j].size())<<' '<<t1[i].substr(k+s1[j].size(),t1[i].size())<<' '<<
//					t1[i].substr(0,k)+s2[j]+t1[i].substr(k+s1[j].size(),t1[i].size())<<' '<<
//					t2[i]<<'\n';
				if(t1[i].substr(k,k+len)==s1[i]&&
					t1[i].substr(0,k)+s2[j]+t1[i].substr(k+len,t1[i].size())
					==t2[i]){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _=1;
//    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}