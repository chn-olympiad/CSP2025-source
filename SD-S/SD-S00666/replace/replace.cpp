#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,q,minl=1e9;
string s[200010][4],t1,t2;
int useful(string a,string b) {
	int l1=a.size();
	int l2=b.size();
	if(l2>l1) return -1;
	if(a[0]==b[0]) {
		for(int j=1; j<l2; j++) {
			if(a[j]!=b[j]) return -1;
		}
		return 0;
	}
	for(int i=0; i+l2-1<l1; i++) {
		if(a[i]==b[0]) {
			for(int j=1; j<l2; j++) {
				if(a[i+j]!=b[j]) return -1;
			}
			return i;
		}
	}
	return -1;
}
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();
	q=read();
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>t1>>t2;
		for(int j=1;j<=n;j++){
			int l1=t1.size();
			int l2=t2.size();
			if(l1!=l2) continue;
			int pos=useful(t1,s[j][1]);
			if(pos==-1) continue;
			l2=s[j][1].size();
			string tes=t1;
			for(int k=pos;k<pos+l2;k++) tes[k]=s[j][2][k-pos];
			if(tes==t2){
				ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
//csp-2025 rp++!
//SD-S00666
//Èü²©·ð×æ±£ÓÓ
