#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=5e6+10,base=131,mod=19260817;
int read()
{
	register int x=0,t=1;
	register char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') t=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*t;
}
int n,q,len[N],L[N],R[N];
string s[N][2],t[N][2];
ll h[N][2],h1[N][2],p[N];
ll query0(int l,int r)
{
	return (h1[r][0]-h1[l-1][0]*p[r-l+1]%mod+mod)%mod;
}
ll query1(int l,int r)
{
	return (h1[r][1]-h1[l-1][1]*p[r-l+1]%mod+mod)%mod;
}
int pos[N][2],slen;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	p[0]=1;
	for(int i = 1;i<=1e6;i++){
		p[i]=(p[i-1]*base)%mod;
	}
	
	for(int i = 1;i<=n;i++){
		cin >> s[i][0] >> s[i][1];
		len[i]=s[i][0].size();
		slen+=len[i]*2;
		s[i][0]=" "+s[i][0];
		s[i][1]=" "+s[i][1];
		for(int k = 0;k<=1;k++){
			ll hs=0;
			for(int j = 1;j<=len[i];j++){
				if(s[i][k][j]=='b'){
					pos[i][k]=j;
				}
				hs=(hs*base%mod+s[i][k][j])%mod;		
			}
			h[i][k]=hs;
		}
	}
	for(int i = 1;i<=q;i++){
		cin >> t[i][0] >> t[i][1];
		slen+=t[i][0].size();
	}
	if(n<=1e3 && slen<=2000){
		for(int i = 1;i<=q;i++){
			L[i]=1e9,R[i]=-1e9;
		//	cin >> t[i][0] >> t[i][1];
			int l=t[i][0].size();
			t[i][0]=" "+t[i][0];
			t[i][1]=" "+t[i][1];
			for(int k = 0;k<=1;k++)
			for(int j = 1;j<=l;j++){
				h1[j][k]=(h1[j-1][k]*base%mod+t[i][k][j])%mod;
			//	cout << j << " " << k << " " << h1[j][k] << "\n";
			}
		//	cout << 3 << " " << 4 << " " << query0(3,4) << '\n';
			ll sum=0;
			for(int j = 1;j<=l;j++){
				if(t[i][0][j]!=t[i][1][j]){
					L[i]=min(L[i],j);
					R[i]=max(R[i],j);
				}
			}
			for(int j = 1;j<=l;j++){
				
				for(int k = 1;k<=n;k++){
					
					if(j+len[k]-1<=l){
						if(j<=L[i] && j+len[k]-1>=R[i]){	
				//			cout << j << " " << k << " " << 	query0(j,j+len[k]-1) << " " << h[k][0] << " " << query1(j,j+len[k]-1) << " " << h[k][1] << '\n';
							if(query0(j,j+len[k]-1)==h[k][0] && query1(j,j+len[k]-1)==h[k][1]){
								sum++;
							}
						}
					}
				}
			}
			cout << sum << '\n';
		}
	}
	else{
		for(int i = 1;i<=q;i++){
	//		cin >> t[i][0] >> t[i][1];
			int l=t[i][0].size();
			t[i][0]=" "+t[i][0],t[i][1]=" "+t[i][1];
			int p0,p1,cnt=0;
			for(int j = 1;j<=l;j++){
				if(t[i][0][j]=='b') p0=j;
				if(t[i][1][j]=='b') p1=j;
			}
			for(int k = 0;k<=1;k++)
			for(int j = 1;j<=l;j++){
				h1[j][k]=(h1[j-1][k]*base%mod+t[i][k][j])%mod;
			//	cout << j << " " << k << " " << h1[j][k] << "\n";
			}
			for(int j = 1;j<=n;j++){
				if(p0-pos[j][0]==p1-pos[j][1]){
					int st=p0-pos[j][0]+1;
					if(st+len[j]-1<=l)
					if(query0(st,st+len[j]-1)==h[j][0] && query1(st,st+len[j]-1)==h[j][1]){
						cnt++;
					}
				}
			}	
			cout << cnt << '\n';
		}
	}
	return 0;
}
/*

*/
