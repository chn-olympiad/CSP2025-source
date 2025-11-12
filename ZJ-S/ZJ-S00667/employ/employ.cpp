#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=503;
int n,m,c[N],b[N],cnt=1,ans;
char s[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>(s+1);
	for (int i=1;i<=n;i++){
		cin>>c[i];
		cnt*=i;
	}
	for (int i=1;i<=cnt;i++){
//		for (int j=1;j<=n;j++) cout<<c[j]<<" "; cout<<"\n";
		int tot=0;
		for (int j=1;j<=n;j++){
			if (tot>=c[j]){
				tot++;
			}
			else if (s[j]=='0'){
				tot++;
			}
		}
		if (n-tot>=m) ans++;
		next_permutation(c+1,c+n+1);
	}
	cout<<ans;
	return 0;
}

