#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
int perm[11];
string s;
int c[11];
int n,m;
int ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for (int i=1;i<=n;i++) cin>>c[i];
	for (int i=1;i<=n;i++) perm[i]=i;
	do{
		int failed=0;
		int successed=0;
		for (int i=1;i<=n;i++){
			int diff=s[i-1]-'0';
			if (failed>=c[perm[i]]) {failed+=1;continue;}
			failed+=1-diff;
			successed+=diff;
		}
		if (successed>=m) ans+=1;
	}while (next_permutation(perm+1,perm+n+1));
	cout<<ans;
	return 0;
}
