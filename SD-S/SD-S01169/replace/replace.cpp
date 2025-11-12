#include<bits/stdc++.h>
using namespace std;
const int N=4e5+10,M=5e6+30;
const long long mod1=1080857003,mod2=10808057033,bs1=1080857,bs2=1080899;
string s[M],t[M];
int n,q,ans[N],l,hs1[N],hs2[N],ht1[N],ht2[N];
long long b1[N],b2[N]; 
struct node {
	long long a,b,c,d;
} a[N];
bool cmp(node n1,node n2) {
	if(n1.a==n2.a) {
		if(n1.b==n2.b) {
			if(n1.c==n2.c) return n1.d<n2.d;
			return n1.c<n2.c;
		}
		return n1.b<n2.b; 
	}
	return n1.a<n2.a;
}
int findp(node n1) {
	int l=1,r=n,mid;
	while(l<=r) {
		mid=(l+r)/2;
		if(cmp(n1,a[mid])) l=mid+1;
		else r=mid-1;
	}
	return l;
}
int main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
	n=2005;
	b1[0]=b2[0]=1;
	for(int i=1;i<=n;i++) {
		b1[i]=b1[i-1]*bs1%mod1;
		b2[i]=b2[i-1]*bs2%mod2;
	}
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) {
		scanf("%s%s",&s,&t);
		l=strlen(s);
		if(l>2005) break;
		long long h1=0,h2=0,h3=0,h4=0;
		for(int j=1;j<=l;j++) {
			h1=(h1*bs1+s[j-1])%mod1;
			h2=(h2*bs1+t[j-1])%mod1;
			h3=(h3*bs2+s[j-1])%mod2;
			h4=(h4*bs2+t[j-1])%mod2;
		}
		a[i]={h1,h2,h3,h4};
	}
	while(q--) {
		scanf("%s%s",&s,&t);
		l=strlen(s);
		for(int i=1;i<=l;i++) {
			hs1[i]=(hs1[i-1]*bs1+s[j-1])%mod1;
			hs2[i]=(hs2[i-1]*bs1+t[j-1])%mod1;
			ht1[i]=(ht1[i-1]*bs2+s[j-1])%mod2;
			ht2[i]=(ht2[i-1]*bs2+t[j-1])%mod2;
		}
		int p=1,q=l;
		for(;p<=l;p++) {
			if(s[p-1]!=t[p-1]) break;
		}
		if(p==1) {
			printf("0\n");
			continue; 
		}
		for(;q;q--) {
			if(s[q-1]!=t[q-1]) break;
		}
		int ans=0;
		for(int i=1;i<p;i++) {
//			for(int j=q+1;j<=n;j++) ans+=findp({}) 
		}
		printf("%d\n",ans);
	}
	return 0;
}
//Is hash right?
