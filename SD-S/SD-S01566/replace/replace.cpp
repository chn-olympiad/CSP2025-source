#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;
int read() {
	int x=0;
	short f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
const int N=2e5+10;
string s1[N],s2[N],t1,t2;
int len1,len2;
int l1[N];
bool pre(int u){
	for(int i=0;i<=u;i++)
		if(t1[i]!=t2[i])
			return 0;
	return 1; 
}
bool bck(int u){
	for(int i=len1-1;i>=u;i--){
		if(t1[i]!=t2[i])
			return 0;
	}
	return 1;
}
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read(),q=read();
	for(int i=1; i<=n; i++) {
		cin>>s1[i]>>s2[i];
		l1[i]=s1[i].length();
	}
	while(q--) {
		int ans=0;
		cin>>t1>>t2;
		
		len1=t1.length();
		len2=t2.length();
		if(len1!=len2) {
			cout<<0<<endl;
			continue;
		}
		for(int i=0; i<len1; i++) {
			for(int j=1; j<=n; j++) {
				bool flag=1;
				for(int k=0; k<l1[j]; k++) {
					if(s1[j][k]!=t1[i+k]||s2[j][k]!=t2[i+k]||i+k>=len1) {
						flag=0;
						break;
					}
				}
				if(flag&&pre(i-1)&&bck(i+l1[j])) {
					ans++;
				}
			}
		}
		cout<<ans<<endl;
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
