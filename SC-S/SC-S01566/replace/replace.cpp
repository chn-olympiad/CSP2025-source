#include<bits/stdc++.h>
#include<stdio.h>
#define ull unsigned long long
using namespace std;
const int maxn = 5e6+2;
int n,q;
map<ull,ull> mp;
char c1[maxn],c2[maxn];
ull a[maxn],b[maxn];
ull mi[maxn];

ull hash(char c[]) {
    int len = strlen(c);
    ull ans = 0;
    for(int i=1;i<=len;i++) 
	ans = ans*131 + (c[i]-'a'+1);
    return ans;
}
void geta(char c[]) {
    mi[0] = 1;
    int len = strlen(c);
    for(int i=1;i<=len;i++) {
        a[i] = a[i-1]*131 + (c[i]-'a'+1);
	mi[i] = mi[i-1]*131;
    }
}
void getb(char c[]) {
    mi[0] = 1;
    int len = strlen(c);
    for(int i=1;i<=len;i++) {
        b[i] = b[i-1]*131 + (c[i]-'a'+1);
	mi[i] = mi[i-1]*131;
    }
}
ull sona(int l,int r) {
    ull u = a[r];
    ull v = a[l-1] * mi[r-l+1];
    return u-v;
}
ull sonb(int l,int r) {
    ull u = b[r];
    ull v = b[l-1] * mi[r-l+1];
    return u-v;
}
int main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++) {
	cin>>c1>>c2;
	mp[hash(c1)] = hash(c2);
    }
    while(q--) {
	int ans = 0;
	cin>>c1>>c2;
	int n1 = strlen(c1),n2 = strlen(c2);
	geta(c1);
	getb(c2);
	if(n1!=n2) { cout<<0<<endl; continue ; }
	for(int len=1;len<=n1;len++) 
	    for(int i=1;i+len-1<=n1;i++) {
		int l = i,r = i+len-1;
		ull x = sona(l,r);
		ull y = sonb(l,r);

		ull pa = -1,pb = -1;
		ull qa = -1,qb = -1;
		if(l-1>0) 
		    pa = sona(1,l-1),pb = sonb(1,l-1);
		if(r+1<=n) 
		    qa = sona(1,r+1),qb = sonb(1,r+1);
		if(pa==pb && qa==qb && mp.find(x) != mp.end()) 
		    if((mp[x]) == y) ans++;
	    }
	cout<<ans<<endl;
    }
    return 0;
}
