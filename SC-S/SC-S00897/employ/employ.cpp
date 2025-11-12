#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=500+10;
const int mod=998244353;

int read() {
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)) {
		if(c=='-') f=-1;
		c=getchar();
	} while(isdigit(c)) {
		x=(x<<1)+(x<<3)+(c-'0');
		c=getchar();
	} return x*f;
}

int n,m,c[maxn],a[maxn],ans;
char s[maxn];
int fac[maxn];
bool flag=1;
void add(int &x,int y) {
	x+=y;
	if(x>=mod) x-=mod;
}

void init() {
	fac[0]=1;
	for(int i=1;i<maxn;i++) fac[i]=1ll*fac[i-1]%mod;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>>(s+1);
	for(int i=1;i<=n;i++) {
		if(s[i]=='0') flag=0;
	}
	for(int i=1;i<=n;i++) c[i]=read();
	
	if(n<=10) {
		for(int i=1;i<=n;i++) a[i]=i;
		do{
			int now=0,cnt=0;
			for(int i=1;i<=n;i++) {
				if(now>=c[a[i]]) {
					now++; continue;
				}
				if(s[i]=='1') cnt++;
				else now++;
			} add(ans,(cnt>=m));
		}while(next_permutation(a+1,a+1+n));
		cout<<ans<<"\n";
	}
	return 0;
}