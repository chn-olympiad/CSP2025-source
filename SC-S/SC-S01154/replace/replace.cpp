#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define re register
const int maxn=5e6+10;
const int N=2e5+10;
const ull p=13331;
ull z[maxn];
int n,q;
string s[N][2],t[N][2];
int len;
ull hs1[maxn],hs2[maxn];
inline ull gt1(int l,int r){
	if(l>r) return 0;
	return hs1[r]-hs1[l-1]*z[r-l+1];
}
inline ull gt2(int l,int r){
	if(l>r) return 0;
	return hs2[r]-hs2[l-1]*z[r-l+1];
}
int zzzl(int l,int r){
	int mid;
	while(l<r){
		mid=(l+r)>>1;
		if(gt1(1,mid)==gt2(1,mid)) l=mid+1;
		else r=mid;
	}
	return l;
}
int zzzr(int l,int r){
	int mid;
	while(l<r){
		mid=((l+r)>>1)+1;
		if(gt1(mid,len)==gt2(mid,len)) r=mid-1;
		else l=mid;
	}
	return l;
}
map<pair<ull,ull>,int>id;
int cnt;
vector<pair<pair<int,ull>,pair<int,ull> > >vec[maxn];
pair<ull,ull>now;
pair<pair<int,ull>,pair<int,ull> > node;
int ans[N];
int posl,posr;
ull hsl,hsr,hsm1,hsm2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	z[0]=1;
	for(int i=1;i<=5e6;++i) z[i]=z[i-1]*p;
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i][1]>>s[i][2];
		if(s[i][1]==s[i][2]) continue;
		len=s[i][1].length();
		hs1[0]=hs2[0]=0;
		for(int j=1;j<=len;++j){
			hs1[j]=hs1[j-1]*p+s[i][1][j-1];
		}
		for(int j=1;j<=len;++j){
			hs2[j]=hs2[j-1]*p+s[i][2][j-1];
		}
		posl=zzzl(1,len),posr=zzzr(1,len);
		hsl=gt1(1,posl-1);hsr=gt1(posr+1,len);
		hsm1=gt1(posl,posr);hsm2=gt2(posl,posr);
		now.first=hsm1;now.second=hsm2;
		if(!id[now]) id[now]=++cnt;
		node.first.first=posl-1;node.first.second=hsl;
		node.second.first=len-posr;node.second.second=hsr;
		vec[id[now]].push_back(node);
	}
	for(int i=1;i<=q;++i){
		cin>>t[i][1]>>t[i][2];
		if(t[i][1].length()!=t[i][2].length()) continue;
		len=t[i][1].length();
		hs1[0]=hs2[0]=0;
		for(int j=1;j<=len;++j){
			hs1[j]=hs1[j-1]*p+t[i][1][j-1];
		}
		for(int j=1;j<=len;++j){
			hs2[j]=hs2[j-1]*p+t[i][2][j-1];
		}
		posl=zzzl(1,len),posr=zzzr(1,len);
		hsm1=gt1(posl,posr);
		hsm2=gt2(posl,posr);
		now.first=hsm1;now.second=hsm2;
		if(id.count(now)){
			int xid=id[now];
			int siz=(int)vec[xid].size();
			for(int j=0;j<siz;++j){
				if(posl-vec[xid][j].first.first>=1&&posr+vec[xid][j].second.first<=len){
					if(gt1(posl-vec[xid][j].first.first,posl-1)==vec[xid][j].first.second&&gt1(posr+1,posr+vec[xid][j].second.first)==vec[xid][j].second.second) ++ans[i];
				}
			}
		} 
	}
	for(int i=1;i<=q;++i) cout<<ans[i]<<"\n";
	return 0;
}
/*

*/