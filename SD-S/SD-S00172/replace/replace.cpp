#include<bits/stdc++.h>
#define int long long
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
const int N=2e3+100;
using namespace std;
int n,q,ans=0;
char s1[N][N],s2[N][N],t1[N],t2[N];
int nxt[N][N],len[N];
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>(s1[i]+1);
		cin>>(s2[i]+1);
		len[i]=strlen(s1[i]+1);
		for(int j=2,p=0; j<=len[i]; j++) {
			while(p!=0 and s1[i][p+1]==s1[i][j]) {
				p=nxt[i][p];
			}
			if(s1[i][p+1]==s1[i][j]) {
				p++;
			}
			nxt[i][j]=p;
		}
	}
	while(q--) {
		ans=0;
		cin>>(t1+1);
		cin>>(t2+1);
		for(int i=1; i<=n; i++) {
			for(int j=1,p=0; j<=strlen(t1+1); j++) {
				while(p!=0 and s1[i][p+1]==t1[j]) {
					p=nxt[i][p];
				}
				if(s1[i][p+1]==t1[j]) {
					p++;
				}
				if(p==len[i]) {
					string tmp=t1;
					for(int k=j-p+1,ll=1; k<=j; k++,ll++) {
						tmp[k]=t2[ll];
					}
					bool flag=1;
					for(int k2=1; k2<=strlen(t1+1); k2++) {
						if(tmp[k2]!=t2[k2]) {
							flag=false;
							break;
						}
					}
					if(flag) {
						ans++;
					}
					p=nxt[i][p];
				}

			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
