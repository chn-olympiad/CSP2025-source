#include <iostream>
#include <vector>
#define SUBMITMODE 1
#define DEBU__G_ 0
#define DEBUG DEBU__G_&&!SUBMITMODE
using namespace std;
//string src,tar;
int n,q;
/*struct rule {
	int npre,nade,rpre,rade;
}law[200003];*/
int main_bak() {
	/*
	
	freopen("D:\\csps\\down\\replace\\replace4.in","r",stdin);
	if(SUBMITMODE) {
		freopen("replace.in","r",stdin);
		freopen("replace.out","w",stdout);
	}
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;++i) {
		string a,b;
		cin>>a>>b;
		int bpa=0,bpb=0;
		while(a[bpa]!='b') {
			++bpa;
		}
		while(b[bpb]!='b') {
			++bpb;
		}
		law[i]={bpa-1,a.size()-bpa,bpb-1,b.size()-bpb};
	}
	for(int i=1;i<=q;++i) {
		int ans=0;
		cin>>src>>tar;
		int bps=0,bpt=0;
		while(src[bps]!='b') {
			++bps;
		}
		while(tar[bpt]!='b') {
			++bpt;
		}
		for(int j=1;j<=n;++j) {
			if(bps>=law[j].npre && src.size()-bps>=law[j].nade && bps-law[j].npre+law[j].rpre==bpt && src.size()-bps-law[j].nade+law[j].rade==tar.size()-bpt) {
				++ans;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
	
	*/
	return 0;
}
/*
aaaabaa
aaabaaa

aaba -> abaa
ab -> ba
abaa -> baa
*/
vector <pair <string,string>> rules;
//int n,q;
int main() {
	if(SUBMITMODE) {
		freopen("replace.in","r",stdin);
		freopen("replace.out","w",stdout);
	}
	//ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;++i) {
		string a,b;
		cin>>a>>b;
		rules.push_back({a,b});
	}
	for(int i=1;i<=q;++i) {
		string a,b;
		cin>>a>>b;
		int ans=0;
		for(auto x : rules) {
			for(int j=0;j<a.size()-x.first.size()+1;++j) {
				bool ok2=1;
				for(int k=0;k<x.first.size() && ok2;++k) {
					if(a[j+k]!=x.first[k]) {
						ok2=0;
						break;
					}
				}
				if(ok2) {
					string pre="",til="";
					for(int k=0;k<j;++k) {
						pre=pre+a[k];
					}
					for(int k=j+x.first.size();k<a.size();++k) {
						til=til+a[k];
					}
					if(pre+x.second+til==b) {
						++ans;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
