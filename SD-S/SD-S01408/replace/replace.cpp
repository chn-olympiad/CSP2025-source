#include<bits/stdc++.h>
using namespace std;
int n,q,base1=107,base2=109,p1=1000000007,p2=998244353,h1[2][2010],h2[2][2010],pow1[2010],pow2[2010],ha1[2][2010],ha2[2][2010];
string s1[2000010],s2[2000010],c1[2000010],c2[2000010];
int l[2000010];
int hhh1 (string s) {
	int len=(int)(s.size());
	long long ha=0;
	for (int i=0;i<len;i++) {
		ha=(ha*base1+s[i]-'a'+1)%p1;
	}
	return ha;
}
int hhh2 (string s) {
	int len=(int)(s.size());
	long long ha=0;
	for (int i=0;i<len;i++) {
		ha=(ha*base2+s[i]-'a'+1)%p2;
	}
	return ha;
}
void Hash1 (int z,string s) {
	long long ha=0;
	int len=(int)(s.size());
	for (int i=0;i<len;i++) {
		ha=(ha*base1+s[i]-'a'+1)%p1;
		h1[z][i+1]=ha;
	}
}
void Hash2 (int z,string s) {
	long long ha=0;
	int len=(int)(s.size());
	for (int i=0;i<len;i++) {
		ha=(ha*base2+s[i]-'a'+1)%p2;
		h2[z][i+1]=ha;
	}
}
int hash1 (int z,int l,int r) {
	long long x=1ll*h1[z][l-1]*pow1[r-l+1]%p1;
	return (0ll+h1[z][r]-x+p1)%p1;
}
int hash2 (int z,int l,int r) {
	long long x=1ll*h2[z][l-1]*pow2[r-l+1]%p2;
	return (0ll+h2[z][r]-x+p2)%p2;
}
void solve (string c1,string c2) {
	Hash1(0,c1);
	Hash2(0,c1);
	Hash1(1,c2);
	Hash2(1,c2);
	int len=(int)(c1.size()),ans=0;
	int le=1e9,r=0;
	for (int i=0;i<len;i++) {
		if (c1[i]!=c2[i]) {
			le=min(le,i+1);
			r=max(r,i+1);
		}
	}
//	printf("%d %d\n",le,r);
	for (int i=1;i<=len;i++) {
		for (int j=1;j<=n;j++) {
			if (i+l[j]-1<=len&&i<=le&&i+l[j]-1>=r) {
				if (hash1(0,i,i+l[j]-1)==ha1[0][j]&&
					hash2(0,i,i+l[j]-1)==ha2[0][j]&&
					hash1(1,i,i+l[j]-1)==ha1[1][j]&&
					hash2(1,i,i+l[j]-1)==ha2[1][j]) {
//					printf("%d\n",j);
					ans++;
				}	
			}
		}
	}
	printf("%d\n",ans);
}
int main () {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pow1[0]=pow2[0]=1;
	for (int i=1;i<=2000;i++) {
		pow1[i]=(1ll*pow1[i-1]*base1)%p1;
		pow2[i]=(1ll*pow2[i-1]*base2)%p2;
	}
	scanf("%d%d",&n,&q);
	int l1=0,l2=0;
	for (int i=1;i<=n;i++) {
		cin>>s1[i]>>s2[i];
		l1+=(int)(s1[i].size());
		l1+=(int)(s2[i].size());
	}
	for (int i=1;i<=q;i++) {
		cin>>c1[i]>>c2[i];
		l2+=(int)(c1[i].size());
		l2+=(int)(c2[i].size());
	}
	if (n<=1000&&q<=1000&&l1<=2000&&l2<=2000) {
		for (int i=1;i<=n;i++) {
			ha1[0][i]=hhh1(s1[i]);
			ha2[0][i]=hhh2(s1[i]);
			ha1[1][i]=hhh1(s2[i]);
			ha2[1][i]=hhh2(s2[i]);
			l[i]=(int)(s1[i].size());
		}
		for (int test=1;test<=q;test++) {
			solve(c1[test],c2[test]);
		}
	}
	else printf("0");
	return 0;
}
