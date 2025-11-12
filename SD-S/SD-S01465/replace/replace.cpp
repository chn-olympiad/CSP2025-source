#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fst ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fp(s) string ssssss=s;freopen((ssssss+".in").c_str(),"r",stdin);freopen((ssssss+".out").c_str(),"w",stdout);
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define pb push_back
#define inl inline
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define mt(x,y) memset(x,y,sizeof x)
#define INF 1e18
#define ui unsigned
#define prr make_pair
using namespace std;
const int N=2e5+5,base=31,M=5e6+5;
string s[2][N];
ui __int128 hshr[2][N],pw[M],hsh[2][N],sum[2][M];
int idxl[N],idxr[N],len[N],idx[N];
map<pair<ui __int128,ui __int128>,int>mp[base];
inl ui __int128 gethsh(int l,int r,int op){
	return sum[op][r]-sum[op][l-1]*pw[r-l+1];
}
inl bool check(int idl,int idr,int j){
	rep(op,0,1)
		if(gethsh(idl-idxl[j]+1,idr+len[j]-idxr[j],op)!=hsh[op][j]) return 0;
	return 1;
}
signed main(){
	fp("replace");
	fst;
	int n,q,sqt,cnt=0;
	cin>>n>>q;
	pw[0]=1;
	rep(i,1,5e6) pw[i]=pw[i-1]*base;
	rep(i,1,n) cin>>s[0][i]>>s[1][i];
	rep(i,1,n)
		if(s[0][i]!=s[1][i]){
			s[0][++cnt]=s[0][i];
			s[1][cnt]=s[1][i];
		}
	n=cnt;
	rep(i,1,n) len[i]=s[0][i].size();
	rep(i,1,n) s[0][i]=' '+s[0][i];
	rep(i,1,n) s[1][i]=' '+s[1][i];
	sqt=(int)sqrtl(sqrtl(2*n/log2(n+1)));
	mt(idxl,-1);
	mt(idxr,-1);
	rep(i,1,n)
		rep(j,1,len[i])
			if(s[0][i][j]!=s[1][i][j]){
				if(!~idxl[i]) idxl[i]=j;
				idxr[i]=j;
			}
	rep(op,0,1)
		rep(i,1,n)
			rep(j,1,len[i]) (hsh[op][i]*=base)+=s[op][i][j]-'a'+1;
	cnt=0;
	rep(i,1,n)
		if(len[i]<=sqt) ++mp[len[i]][prr(hsh[0][i],hsh[1][i])];
		else idx[++cnt]=i;
	rep(i,1,q){
		string t[2];
		cin>>t[0]>>t[1];
		int lent=t[0].size(),idl=-1,idr=-1,ans=0;
		t[0]=' '+t[0];
		t[1]=' '+t[1];
		rep(j,1,lent)
			if(t[0][j]!=t[1][j]){
				if(!~idl) idl=j;
				idr=j;
			}
		rep(op,0,1){
			sum[op][0]=0;
			rep(j,1,lent) sum[op][j]=sum[op][j-1]*base+t[op][j]-'a'+1;
		}
		if(lent<=sqt){
			int ans=0;
			rep(l,1,idl)
				rep(r,idr,lent) ans+=mp[r-l+1][prr(gethsh(l,r,0),gethsh(l,r,1))];
			cout<<ans<<endl;
			continue;
		}
		rep(l,idr-sqt+1,idl)
			rep(r,idr,l+sqt-1) ans+=mp[r-l+1][prr(gethsh(l,r,0),gethsh(l,r,1))];
//		cout<<idl<<' '<<idr<<' '<<t[0][idl]<<' '<<t[1][idl]<<endl;
		rep(j,1,cnt)
			if(idxr[idx[j]]-idxl[idx[j]]==idr-idl&&idl-idxl[idx[j]]>=0&&idr+len[idx[j]]-idxr[idx[j]]<=lent&&check(idl,idr,idx[j])) ++ans;
		cout<<ans<<endl;
	}
	return 0;
} 
