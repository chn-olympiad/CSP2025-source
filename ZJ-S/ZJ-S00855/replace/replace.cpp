#include<bits/stdc++.h>

using namespace std;
const int N=2e3+10;
const int k=137;
const int mod=1e9+7;
int n,t;
string s[N][3];
int a[N][3];
long long hash[N][3],p[N],hx[N],hy[N];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>t;
	if(n*t*200*200<=4e9) {
		for(int i=1; i<=n; i++)cin>>s[i][1]>>s[i][2];
		while(t--) {
			int ans=0;
			string x,y;
			cin>>x>>y;
			int lenx=x.size(),leny=y.size();
			x=' '+x,y=' '+y;
			for(int i=1; i<=n; i++) {
				int flag=0;
				for(int j=1; j<=lenx; j++) {
					int t=j;
					for(int k=1; k<j; k++)
						if(x[k]!=y[k]) {
							flag=1;
							break;
						}
					if(flag==0) {
						for(int k=j+s[i][1].size(); k<=lenx; k++)
							if(x[k]!=y[k]) {
								flag=1;
								break;
							}
					}
					if(flag==0) {
						for(int k=0; k<s[i][1].size(); k++) {
							if(x[t+k]!=s[i][1][k]||y[t+k]!=s[i][2][k]) {
								flag=1;
								break;
							}
						}
					}
					if(flag==0) {
						ans++;
						break;
					}
				}
			}
			cout<<ans<<'\n';
		}
	} else {
		p[0]=1;
		for(int i=1; i<=2000; i++)p[i]=p[i-1]*k%mod;
		for(int i=1; i<=n; i++) {
			cin>>s[i][1]>>s[i][2];
			for(int j=0; j<s[i][1].size(); j++)
				hash[i][1]=(hash[i][1]+p[j]*(s[i][1][j]-'a'+1))%mod,hash[i][2]=(hash[i][2]+p[j]*(s[i][2][j]-'a'+1))%mod;
		}
		while(t--) {
			int ans=0;
			string x,y;
			cin>>x>>y;
			int lenx=x.size(),leny=y.size();
			x=' '+x,y=' '+y;
			for(int i=1; i<=lenx; i++) {
				if(i>0)hx[i]=hx[i-1],hy[i]=hy[i-1];
				hx[i]=(hx[i]+p[i-1]*(x[i]-'a'+1))%mod,hy[i]=(hy[i]+p[i-1]*(y[i]-'a'+1))%mod;
			}
			hx[0]=hy[0]=0;
			for(int i=1; i<=n; i++) {
				for(int j=0; j<=lenx; j++) {
					int Tx=j+s[i][1].size(),Ty=j+s[i][1].size();
					if(hx[j]==hy[j]&&hx[lenx]-hx[Tx]==hy[leny]-hy[Ty]&&hx[Tx]-hx[j]==hash[i][1]*p[j]%mod&&hy[Ty]-hy[j]==hash[i][2]*p[j]%mod) {
						ans++;
						break;
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
