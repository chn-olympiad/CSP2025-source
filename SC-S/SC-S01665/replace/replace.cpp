#include<bits/stdc++.h>
#define F(i,x,y) for (int i=(x);i<=(y);i++)
#define R(i,x,y) for (int i=(x);i>=(y);i--)
#define ull unsigned long long
using namespace std;

const int N=2e5+5,S=5e6+5;
int n,q,cnt,ok[N];
map<pair<int,int>,int> tr;
struct hv {
	ull val;
	int len;
	bool operator == (const hv &b) {
		return val==b.val&&len==b.len;
	}
} pre[N],mid[N],suf[N];
inline int calc (char x,char y) {
	return (x-97)*26+y-96;
}
inline hv add (hv x,ull y) {
	x.val=x.val*1007+y;
	x.len+=1;
	return x;
}
hv md,pr[N],sf[N];
int main () {
	freopen ("replace.in","r",stdin);
	freopen ("replace.out","w",stdout);
	ios::sync_with_stdio (0); cin.tie (0);
	cin>>n>>q;
	cnt=1;
	string s1,s2;
	F(i,1,n) {
		cin>>s1>>s2;
		int sz=s1.size();
		int lb=-1,rb=-1;
		F(j,0,sz-1) {
			if (s1[j]!=s2[j]) {
				if (lb==-1) lb=j;
				rb=j;
			}
		}
		if (lb==-1) continue;
		ok[i]=1;
		F(j,lb,rb) mid[i]=add(mid[i],calc(s1[j],s2[j]));
		R(j,lb-1,0) pre[i]=add(pre[i],s1[j]);
		F(j,rb+1,sz-1) suf[i]=add(suf[i],s1[j]);
	}
	F(i,1,q) {
		cin>>s1>>s2;
		if (s1.size()!=s2.size()) {
			cout<<0<<"\n";
			continue;
		}
		int sz=s1.size();
		int lb=-1,rb=-1;
		F(j,0,sz-1) {
			if (s1[j]!=s2[j]) {
				if (lb==-1) lb=j;
				rb=j;
			}
		}
		F(j,lb,rb) md=add(md,calc(s1[j],s2[j]));
		R(j,lb-1,0) pr[lb-j]=add(pr[lb-j-1],s1[j]);
		F(j,rb+1,sz-1) sf[j-rb]=add(sf[j-rb-1],s1[j]);
		int ans=0;
		F(j,1,n) {
			if (md==mid[j]&&pr[pre[j].len]==pre[j]&&sf[suf[j].len]==suf[j]) ++ans;
		}
		cout<<ans<<"\n";
		R(j,lb-1,0) pr[lb-j]={0,0};
		F(j,rb+1,sz-1) sf[j-rb]={0,0};
		md={0,0};
	}
	return 0;
}