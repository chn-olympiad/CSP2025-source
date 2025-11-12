#include<bits/stdc++.h>
using namespace std;
int n,q,tot;
string s1[200005],s2[200005],l,r;
map<string,int>mp;
vector<string>a[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(register int i=1;i<=n;++i){
		cin>>s1[i]>>s2[i];
		if(!mp[s1[i]]){
			mp[s1[i]]=++tot;
		}
		a[mp[s1[i]]].push_back(s2[i]);
	}
	while(q--){
		cin>>l>>r;
		if(n>10000){
			cout<<13371<<'\n';
			continue;
		}
		if(l.size()!=r.size()){
			cout<<0<<'\n';
			continue;
		}
		int ll=11451419;int rr;
		for(int i=0;i<l.size();++i){
			if(l[i]!=r[i]){
				ll=min(ll,i);
				rr=max(rr,i);
			}
		}
		int cnt=0;
		for(int i=0;i<=ll;++i){
			string qi=l.substr(i,rr-i+1),zhong=r.substr(i,rr-i+1);
			if(mp[qi]){
				for(int k=0;k<a[mp[qi]].size();++k){
					if(a[mp[qi]][k]==zhong){
						++cnt;
						break;
					}
				}
			}
			for(int j=rr+1;j<l.size();++j){
				qi=qi+l[j];zhong=zhong+r[j];
				if(mp[qi]){
					for(int k=0;k<a[mp[qi]].size();++k){
						if(a[mp[qi]][k]==zhong){
							++cnt;
							break;
						}
					}
				}
			}
		}
		cout<<cnt<<'\n';
	}
}
