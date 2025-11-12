#include<bits/stdc++.h>
//#define int long long
#define FST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define ls(x)(x<<1)
#define rs(x)(x<<1|1)
#define mid(l,r)((l+r)>>1)
#define fclose buyaojiafclose
using namespace std;
const int maxn=2e5+37,maxm=5e6+37,base=33377,mxm=5e6+10;
ull b[maxm];
string s1[maxn],s2[maxn];
int len[maxn];
int n,q;
ull geth(string &s,int len){
	ull res=0;
	for(int i=0;i<len;i++){
		res+=s[i]*b[i];
	}
	return res*b[mxm];
}
map<ull,map<ull,ull>>mp;
ull h1[maxn],h2[maxn];
ull f1[maxn],f2[maxn];
ull geth2(int l,int r,int mod){
	if(mod==1){
		return (h1[r]-(l==0?0:h1[l-1]))*b[mxm-l];
	}else{
		return (h2[r]-(l==0?0:h2[l-1]))*b[mxm-l];
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	FST;
	cin>>n>>q;
	b[0]=base;
	for(int i=1;i<=mxm;i++){
		b[i]=b[i-1]*base;
	}
	int zq=q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		len[i]=s1[i].size();
		f1[i]=geth(s1[i],len[i]),f2[i]=geth(s2[i],len[i]);
		if(zq!=1)mp[f1[i]][f2[i]]++;
	}
	while(q--){
		string z1,z2;
		cin>>z1>>z2;
		int lenz=z1.size();
		if(z1.size()!=z2.size()){
			cout<<0<<endl;
			continue;
		}
		
		int l=-1,r=0;
		for(int i=0;i<lenz;i++){
			h1[i]=(i==0?0:h1[i-1])+z1[i]*b[i];
			h2[i]=(i==0?0:h2[i-1])+z2[i]*b[i];
			if(z1[i]!=z2[i]){
				if(l==-1)l=i;
				r=i;
			}
		}
		int ans=0;
		if(n>=1000||zq==1){
			for(int i=1;i<=n;i++){
				for(int j=0;j<=l;j++){
					if(j+len[i]-1<r)continue;
					if(j+len[i]-1>=lenz)continue;
					if(geth2(j,j+len[i]-1,1)==f1[i]&&geth2(j,j+len[i]-1,2)==f2[i]){
						ans++;
					}
				}
			} 
			cout<<ans<<endl;
			continue;
		}
		for(int i=0;i<=l;i++){
			for(int j=r;j<lenz;j++){
				ans+=mp[geth2(i,j,1)][geth2(i,j,2)];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

