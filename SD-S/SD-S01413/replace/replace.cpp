#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int base=13331;
set<pair<int,int> >st;
set<int>le;
string s1,s2;
pair<int,int> has(){
	int h1=0,h2=0;
	for(int i=0;i<s1.length();i++){
		h1=h1*base+s1[i]-'a'+1;
		h2=h2*base+s2[i]-'a'+1;
	}
	return make_pair(h1,h2);
}
int ha1[1000020],ha2[1000020],p[1000020];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,Q;cin>>n>>Q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		st.insert(has());
		le.insert(s1.length());
	}
	int pm=1;p[0]=1;
	while(Q--){
		cin>>s1>>s2;
		if(s1.length()!=s2.length()){
			cout<<"0\n";continue;
		}
		int len=s1.length();
		for(int i=pm;i<=len+3;i++){
			p[i]=p[i-1]*base;
		}
		pm=max(pm,len+3);
		for(int i=1;i<=len;i++){
			ha1[i]=ha1[i-1]*base+s1[i-1]-'a'+1;
			ha2[i]=ha2[i-1]*base+s2[i-1]-'a'+1;
		}
		int ans=0;
		for(int i=1;i<=len;i++){
			for(auto it=le.begin();it!=le.end()&&(*it)+i-1<=len;it++){
				int j=i+(*it)-1;
				int h1=ha1[j]-ha1[i-1]*p[j-i+1],h2=ha2[j]-ha2[i-1]*p[j-i+1];
				
				if(st.count(make_pair(h1,h2))){
					//cout<<"hhhjs\n";
					if(ha1[i-1]==ha2[i-1] && ha1[len]-ha1[j]*p[len-j]==ha2[len]-ha2[j]*p[len-j]) ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
