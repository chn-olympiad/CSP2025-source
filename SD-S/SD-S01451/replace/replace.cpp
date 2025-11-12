#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
using namespace std;
int p,n;
string s1,s2,t1,t2;
long long pw1[5000001],pw2[5000001],ans;
const long long p1=1000000007,p2=1000000009,bs1=257,bs2=233;
struct hs {
	long long h1,h2;
} ht1[5000001],ht2[5000001];
hs hsh(string s) {
	long long tmp1=0,tmp2=0;
	for(int i=0; s[i]; i++) {
		tmp1*=bs1;
		tmp1+=s[i];
		tmp1%=p1;
		tmp2*=bs2;
		tmp2+=s[i];
		tmp2%=p2;
	}
	hs ret;
	ret.h1=tmp1;
	ret.h2=tmp2;
	return ret;
}
hs gt(int tp,int l,int r) {
	hs ret= {0,0};
	if(tp==1) {
		ret.h1=ht1[r].h1-(ht1[l-1].h1*pw1[r-l+1])%p1;
		ret.h1%=p1;
		ret.h1+=p1;
		ret.h1%=p1;
		ret.h2=ht1[r].h2-(ht1[l-1].h2*pw2[r-l+1])%p2;
		ret.h2%=p2;
		ret.h2+=p2;
		ret.h2%=p2;
	} else {
		ret.h1=ht2[r].h1-(ht2[l-1].h1*pw1[r-l+1])%p1;
		ret.h1%=p1;
		ret.h1+=p1;
		ret.h1%=p1;
		ret.h2=ht2[r].h2-(ht2[l-1].h2*pw2[r-l+1])%p2;
		ret.h2%=p2;
		ret.h2+=p2;
		ret.h2%=p2;
	}
	return ret;
}
map<pair<pair<long long,long long>,pair<long long,long long> >,int>mp;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&p);
	pw1[0]=1;
	pw2[0]=1;
	for(int i=1; i<=5000000; i++) {
		pw1[i]=pw1[i-1]*bs1;
		pw2[i]=pw2[i-1]*bs2;
		pw1[i]%=p1;
		pw2[i]%=p2;
	}
	for(int i=1; i<=n; i++) {
		cin>>s1>>s2;
		hs al,bt;
		al=hsh(s1);
		bt=hsh(s2);
//		cout<<s1<<":"<<al.h1<<" "<<al.h2<<" "<<s2<<":"<<bt.h1<<" "<<bt.h2<<endl;
		if(mp.count({{al.h1,al.h2},{bt.h1,bt.h2}})) {
			mp[ {{al.h1,al.h2},{bt.h1,bt.h2}}]++;
		}
		else {
			mp.insert(make_pair(make_pair(make_pair(al.h1,al.h2),make_pair(bt.h1,bt.h2)),1));
		}
	}
	while(p--) {
		cin>>t1>>t2;
		if(t1.size()!=t2.size()) {
			printf("0\n");
			continue;
		}
		int fi=t1.size()+1,ls=0;
		for(int i=0; i<(int)t1.size(); i++) {
			ht1[i+1].h1=ht1[i].h1*bs1;
			ht1[i+1].h1+=t1[i];
			ht1[i+1].h1%=p1;
			ht1[i+1].h2=ht1[i].h2*bs2;
			ht1[i+1].h2+=t1[i];
			ht1[i+1].h2%=p2;
			ht2[i+1].h1=ht2[i].h1*bs1;
			ht2[i+1].h1+=t2[i];
			ht2[i+1].h1%=p1;
			ht2[i+1].h2=ht2[i].h2*bs2;
			ht2[i+1].h2+=t2[i];
			ht2[i+1].h2%=p2;
			if(t1[i]!=t2[i]) {
				fi=min(fi,i+1);
				ls=max(ls,i+1);
			}
		}
		ans=0;
		if(ht1[t1.size()].h1==ht2[t1.size()].h1&&ht1[t1.size()].h2==ht2[t1.size()].h2)ans++;
		t1=' '+t1;
		t2=' '+t2;
		if(ls) {
			for(int i=fi; i; i--) {
				for(int j=ls; t1[j]; j++) {
					hs tmp1=gt(1,i,j),tmp2=gt(2,i,j);
//					cout<<t1.substr(i,j-i+1)<<" "<<tmp1.h1<<" "<<tmp1.h2<<" ";
//					cout<<t2.substr(i,j-i+1)<<" "<<tmp2.h1<<" "<<tmp2.h2<<"\n";
					if(mp.count({{tmp1.h1,tmp1.h2},{tmp2.h1,tmp2.h2}})) {
						ans+=mp[ {{tmp1.h1,tmp1.h2},{tmp2.h1,tmp2.h2}}];
					}
				}
			}
		} else {
			for(int i=1; t1[i]; i++) {
				for(int j=i; t1[j]; j++) {
					hs tmp1=gt(1,i,j),tmp2=gt(2,i,j);
//					cout<<t1.substr(i,j-i+1)<<" "<<tmp1.h1<<" "<<tmp1.h2<<" ";
//					cout<<t2.substr(i,j-i+1)<<" "<<tmp2.h1<<" "<<tmp2.h2<<"\n";
					if(mp.count({{tmp1.h1,tmp1.h2},{tmp2.h1,tmp2.h2}})) {
						ans+=mp[ {{tmp1.h1,tmp1.h2},{tmp2.h1,tmp2.h2}}];
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
