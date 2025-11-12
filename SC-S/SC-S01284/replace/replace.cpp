#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

string ss[200010],s[200010];

int main(){
    #ifndef Reimu
        freopen("replace.in","r",stdin);
        freopen("replace.out","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){
    	cin>>ss[i]>>s[i];
	}
	while(q--){
		string s_,t;cin>>s_>>t;
		int ans=0,m=t.size()-1,m1=s_.size()-1;
		for(int i=1;i<=n;i++){
			int p=0;
			while(p<=m){
				int ls=s_.find(ss[i],p);
				string ls1="";
				for(int k=0;k<ls;k++)ls1+=s_[k];
				ls1+=s[i];
				for(int k=ls+ss[i].size();k<=m1;k++)ls1+=s_[k];
				if(ls1==t)ans++;
//				cerr<<p<<' '<<ls<<'\n';
//				cerr<<ls1<<'\n';
				if(ls==-1)break;
				p=ls+1;
			}
		}
		cout<<ans<<'\n';
	}
    return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a

1 1
a b
aa b

*/