#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 2e5+5;
int read () {
	int f=1,x=0;char ch=getchar();
	while (!isdigit(ch)) {if(ch=='-')f=-1;ch=getchar();}
	while (isdigit(ch)) {x=x*10+ch-48;ch=getchar();}
	return f*x;
}
int n,q,f=1,fs1[N],fs2[N];
string s1[N],s2[N];
map <int,int> mp; 
signed main () {
	freopen ("replace.in","r",stdin);
	freopen ("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++) 
		cin>>s1[i]>>s2[i];
	for(int k=1;k<=n;k++) {
		for(int i=0;i<s1[k].size();i++) {
			if(s1[k][i]!='b'&&s1[k][i]!='a')f=0;
			else if(s2[k][i]!='b'&&s2[k][i]!='a')f=0;
			if(f&&s1[k][i]=='b') fs1[k]=i;
			if(f&&s2[k][i]=='b') fs2[k]=i;
		} mp[-(fs2[k]-fs1[k])]++;
	}
	
	while (q--) {
		string t1,t2;
		cin>>t1>>t2;
		if(t1==t2) {cout<<1<<'\n';
			continue;
		}
			int ts1,ts2;
			for(int i=0;i<t1.size();i++) {
				if(t1[i]=='b') ts1=i;
				if(t2[i]=='b') ts2=i;
			} int ttp=ts1-ts2;
			int fl=0;
			for(int i=1;i*i<=ttp;i++) {
				if(n%i==0&&i*i!=n)fl+=mp[i]+mp[ttp/i];
				else if(i*i==n)fl+=mp[i];
			} cout<<fl<<'\n';
	}
	return 0;
}
