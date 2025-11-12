#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=505;
int n,m,c[N],p[N];
char str[N];

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,str+1);
	bool subtaskA=true;
	for(int i=1;i<=n;i++) {
		scanf("%d",&c[p[i]=i]);
		subtaskA=subtaskA&&(str[i]=='1');
	}
	if(subtaskA) {
		ll ans=1;
		for(int i=1;i<=n;i++) (ans*=i)%=mod;
		return printf("%lld\n",ans),0;
	}
	int ans=0;
	do {
		int d=0,t=0;
		for(int i=1;i<=n;i++)
			if(d>=c[p[i]]) ++d;
			else if(str[i]&15) ++t;
			else ++d;
		if(t>=m) ++ans;
	} while(next_permutation(p+1,p+1+n));
	printf("%d\n",ans);
	return 0;
}
