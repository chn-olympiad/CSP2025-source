#include<bits/stdc++.h>
#define P 131
using namespace std;
int n,q,l,r,ans;
unsigned long long hash1,hash2,Hash1[5000005],Hash2[5000005],p[5000005];
string t,s1,s2;
map<unsigned long long,unsigned long long>mp;
int main() {
	//freopen("replace.in","r",stdin);
	//freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>t;
		hash1=0;
		for(int j=0; j<t.size(); j++) {
			hash1=hash1*P+t[j]-'a';
		}
		cin>>t;
		hash2=0;
		for(int j=0; j<t.size(); j++) {
			hash2=hash2*P+t[j]-'a';
		}
		mp[hash1]=hash2;
	}
	for(int i=1; i<=q; i++) {
		cin>>s1;
		p[0]=1;
		for(int j=0; j<s1.size(); j++) {
			if(j>0) {
				Hash1[j]=Hash1[j-1]*P+s1[j]-'a';
			} else {
				Hash1[j]=s1[j]-'a';
			}
			p[j+1]=p[j]*P;
		}
		cin>>s2;
		for(int j=0; j<s2.size(); j++) {
			if(j>0) {
				Hash2[j]=Hash2[j-1]*P+s2[j]-'a';
			} else {
				Hash2[j]=s2[j]-'a';
			}
		}
		if(s1.size()!=s2.size()) {
			cout<<"0\n";
			continue;
		}
		l=0,r=-1;
		for(int j=0; j<s1.size(); j++) {
			if(s1[j]!=s2[j]) {
				if(r==-1)l=j;
				r=j;
			}
		}
		cout<<l<<" "<<r<<"\n";
		for(int j=0; j<=l; j++) {
			for(int k=r; k<s1.size(); k++) {
				if(j!=0) {
					if(mp.count(Hash1[k]-Hash1[j-1]*p[k-j+1])&&mp[Hash1[k]-Hash1[j-1]*p[k-j+1]]==Hash2[k]-Hash2[j-1]*p[k-j+1])ans++;
				} else {
					if(mp.count(Hash1[k])&&mp[Hash1[k]]==Hash2[k])ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
