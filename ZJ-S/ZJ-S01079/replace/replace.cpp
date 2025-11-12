#include <bits/stdc++.h>
const int N=2e5+5,M=2.5e6+5;
typedef long long ll;
typedef unsigned long long ull;
const ll Mod=998244353,B2=171;
const ull B=131;
using namespace std;
string s[2][N],t[2];
int yxl[N],yxr[N],len[N];
ll HS2[2][M],BB2[M];
ull BB[M],HS[2][M];
ull query(vector<ull>& hs,int l,int r){return hs[r]-hs[l-1]*BB[r-l+1];}
ll query1(vector<ll>& hs,int l,int r){return ((hs[r]-hs[l-1]*BB2[r-l+1])%Mod+Mod)%Mod;}
ull query2(int id,int l,int r){return HS[id][r]-HS[id][l-1]*BB[r-l+1];}
ll query3(int id,int l,int r){return ((HS2[id][r]-HS2[id][l-1]*BB2[r-l+1])%Mod+Mod)%Mod;}
vector<vector<int>>v(M);
signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	BB[0]=1;for(int j=1;j<M;j++)BB[j]=BB[j-1]*B;
	BB2[0]=1;for(int j=1;j<M;j++)BB2[j]=BB2[j-1]*B2%Mod;
	int n,Q;
	cin>>n>>Q;
	vector<vector<vector<ull>>>hs(2,vector<vector<ull>>(n+1));
	vector<vector<vector<ll>>>hs2(2,vector<vector<ll>>(n+1));
	for(int i=1;i<=n;i++)
	{
		cin>>s[0][i]>>s[1][i];
		len[i]=s[0][i].size();
		s[0][i]=' '+s[0][i];
		s[1][i]=' '+s[1][i];
		yxl[i]=M;yxr[i]=0;
		for(int j=1;j<=len[i];j++)if(s[0][i][j]!=s[1][i][j]){yxl[i]=j;break;}
		for(int j=len[i];j>=1;j--)if(s[0][i][j]!=s[1][i][j]){yxr[i]=j;break;}
		if(yxl[i]<=yxr[i])v[yxr[i]-yxl[i]+1].emplace_back(i);
		hs[0][i].resize(len[i]+2);hs[1][i].resize(len[i]+2);
		hs2[0][i].resize(len[i]+2);hs2[1][i].resize(len[i]+2);
		hs[0][i][0]=hs[1][i][0]=0;
		hs2[0][i][0]=hs2[1][i][0]=0;
		for(int j=1;j<=len[i];j++)
		{
			hs[0][i][j]=hs[0][i][j-1]*B+s[0][i][j];
			hs[1][i][j]=hs[1][i][j-1]*B+s[1][i][j];
			hs2[0][i][j]=(hs2[0][i][j-1]*B2+s[0][i][j])%Mod;
			hs2[1][i][j]=(hs2[1][i][j-1]*B2+s[1][i][j])%Mod;
		}
	}
	while(Q--)
	{
		int ans=0;
		cin>>t[0]>>t[1];
		int Len=t[0].size(),yxL=Len+1,yxR=0;
		t[0]=' '+t[0];t[1]=' '+t[1];
		for(int j=1;j<=Len;j++)
		if(t[0][j]!=t[1][j]){yxL=j;break;}
		for(int j=Len;j>=1;j--)
		if(t[0][j]!=t[1][j]){yxR=j;break;}
		if(yxL>yxR){cout<<0<<'\n';continue;}
		HS[0][0]=HS[1][0]=0;
		HS2[0][0]=HS2[1][0]=0;
		for(int j=1;j<=Len;j++)
		{
			HS[0][j]=HS[0][j-1]*B+t[0][j];
			HS[1][j]=HS[1][j-1]*B+t[1][j];
			HS2[0][j]=(HS2[0][j-1]*B2+t[0][j])%Mod;
			HS2[1][j]=(HS2[1][j-1]*B2+t[1][j])%Mod;
		}
		if(yxL<=yxR)
		{
			for(auto i:v[yxR-yxL+1])
			if(yxL-yxl[i]>=0&&yxR+(len[i]-yxr[i])<=Len)
			{
				if(query2(0,yxL-(yxl[i]-1),yxR+(len[i]-yxr[i]))==query(hs[0][i],1,len[i])
				&&query2(1,yxL-(yxl[i]-1),yxR+(len[i]-yxr[i]))==query(hs[1][i],1,len[i])
				&&query3(0,yxL-(yxl[i]-1),yxR+(len[i]-yxr[i]))==query1(hs2[0][i],1,len[i])
				&&query3(1,yxL-(yxl[i]-1),yxR+(len[i]-yxr[i]))==query1(hs2[1][i],1,len[i]) )
				ans+=1;
			}
		}
		cout<<ans<<'\n';
	}
}
//			cerr<<"D: "<<Q<<'\n';
//			cerr<<i<<' '<<yxL-(yxl[i]-1)<<' '<<yxR+(len[i]-yxr[i])<<'\n';
//			cerr<<query2(0,yxL-(yxl[i]-1),yxR+(len[i]-yxr[i]))<<' '<<query(hs[0][i],1,len[i])<<'\n';
//			cerr<<query2(1,yxL-(yxl[i]-1),yxR+(len[i]-yxr[i]))<<' '<<query(hs[1][i],1,len[i])<<'\n';
//			cerr<<query3(0,yxL-(yxl[i]-1),yxR+(len[i]-yxr[i]))<<' '<<query1(hs2[0][i],1,len[i])<<'\n';
//			cerr<<query3(1,yxL-(yxl[i]-1),yxR+(len[i]-yxr[i]))<<' '<<query1(hs2[1][i],1,len[i])<<'\n';
