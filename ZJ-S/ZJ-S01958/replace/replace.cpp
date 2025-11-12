#include<bits/stdc++.h>
#define ull unsigned long long
#define pr 131
using namespace std;
int n,q,l[200010],r[200010],mi[5000010];
ull hs[5000010],ha[5000010],ht1[5000010],ht2[5000010],h1[200010],h2[200010],leni[200010];
string s[200010],a[200010],t1,t2;
map<pair<ull,ull>,vector<int>>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	mi[0]=1;
	for(int i=1;i<=5000000;++i){
		mi[i]=mi[i-1]*pr;
	}
	for(int i=1;i<=n;++i){
		cin>>s[i]>>a[i];
		leni[i]=s[i].length();
		int len=leni[i];
		l[i]=-1;
		for(int j=1;j<=len;++j){
			if(s[i][j-1]!=a[i][j-1]&&l[i]==-1)l[i]=j-1;
			hs[j]=hs[j-1]*pr+s[i][j-1],ha[j]=ha[j-1]*pr+a[i][j-1];
		}
		for(int j=len;j>0;--j){
			if(s[i][j-1]!=a[i][j-1]&&r[i]==0)r[i]=j+1;
		}
		if(l[i]==-1)continue;
		mp[{hs[r[i]-1]-hs[l[i]]*mi[r[i]-l[i]-1],ha[r[i]-1]-ha[l[i]]*mi[r[i]-l[i]-1]}].push_back(i);
		h1[i]=hs[len],h2[i]=ha[len];
	}
	while(q--){
		cin>>t1>>t2;
		int len=t1.length();
		int ql=-1,qr=0,ans=0;
		for(int j=1;j<=len;++j){
			if(t1[j-1]!=t2[j-1]&&ql==-1)ql=j-1;
			ht1[j]=ht1[j-1]*pr+t1[j-1],ht2[j]=ht2[j-1]*pr+t2[j-1];
		}
		for(int j=len;j>0;--j){
			if(t1[j-1]!=t2[j-1]&&qr==0)qr=j+1;
		}
		for(int id:mp[{ht1[qr-1]-ht1[ql]*mi[qr-ql-1],ht2[qr-1]-ht2[ql]*mi[qr-ql-1]}]){
			if(r[id]>qr||l[id]>ql||(qr-ql)!=(r[id]-l[id]))continue;
//			cout<<id<<' '<<qr<<' '<<ql<<' '<<r[id]<<' '<<l[id]<<' ';
			if(ht1[qr+(leni[id]-r[id])]-ht1[ql-l[id]]*mi[qr+(leni[id]-r[id])-ql-l[id]]==h1[id]&&ht2[qr+(leni[id]-r[id])]-ht2[ql-l[id]]*mi[qr+(leni[id]-r[id])-ql-l[id]]==h2[id])++ans;
		}
//		cout<<ql<<' '<<qr<<' ';
		cout<<ans<<'\n';
	}
	return 0;
}
