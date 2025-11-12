#include <iostream>
#include <vector>
using ll = long long;
using namespace std;
const int N=5e6+3;
string s1[N],s2[N];
void finds(string s,string t,int ls,int lt,vector<int> &fd) { //s找t
	if(ls<lt) return;
	vector<int> kmp(ls+3);
	kmp[0]=1;
	for(int i=1,j=0;i<=lt;i++) {
		while(j>0 && t[i]!=t[j+1]) {
			j=kmp[j];
		}
		j+=(t[i]==t[j]);
		kmp[i]=j;
	}
	for(int i=1,j=0;i<=ls;i++) {
		while(j>0 && s[i]!=t[j+1]) {
			j=kmp[j];
		}
		j+=(s[i]==t[j+1]);
		if(j==lt) {
			fd.push_back(i-j+1);
			if(fd.size()>1) return;
			j=0;
		}
	}
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>s1[i]>>s2[i];
	}
	while(q--) {
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		for(int i=1;i<=n;i++) {
			vector<int> fd1,fd2;
			finds(' '+t1,' '+s1[i],t1.size(),s1[i].size(),fd1);
			finds(' '+t2,' '+s2[i],t2.size(),s2[i].size(),fd2);
			if(fd1.size()!=1 || fd2.size()!=1) continue;
			if(fd1==fd2) {
				ans++;
			}
		}
		printf("%d\n",ans);
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
*/