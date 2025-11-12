#include<bits/stdc++.h>
using namespace std;
int n,q,id[200005],ha[200005],hb[200005],has[200005],al[200005],ar[200005],bl[200005],br[200005],mod=998244353;
long long k[200005];
string tmp1,tmp2;
pair<string,string>s[200005],p;
bool cmp(int x,int y){
	return s[x]<s[y];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	k[0]=1;
	for(int i=1;i<=n;i++)k[i]=(k[i-1]*26)%mod;
	for(int i=1;i<=n;i++){
		cin>>tmp1>>tmp2;
		int l=0,len=tmp1.size(),r=len-1;
		for(int j=0;j<len;j++)(hb[i]+=k[j]*(tmp1[j]-'a')%mod)%=mod;
		while(tmp1[l]==tmp2[l])++l;
		while(tmp1[r]==tmp2[r])--r;
		for(int j=l;j<=r;j++)tmp1[j-l]=tmp1[j];
		tmp1.resize(max(r-l+1,0));
		for(int j=l;j<=r;j++)tmp2[j-l]=tmp2[j];
		tmp2.resize(max(r-l+1,0));
		s[i]=make_pair(tmp1,tmp2),bl[i]=l,br[i]=len-r-1,id[i]=i;
	}
	sort(id+1,id+n+1,cmp);
	for(int i=1;i<=n;i++)al[i]=bl[id[i]],ar[i]=br[id[i]],ha[i]=hb[id[i]];
	sort(s+1,s+n+1);
	while(q--){
		cin>>tmp1>>tmp2;
		int l=0,len=tmp1.size(),r=len-1;
		for(int i=1;i<=len;i++)(has[i]=has[i-1]+k[i-1]*(tmp1[i-1]-'a')%mod)%=mod;
		while(tmp1[l]==tmp2[l])++l;
		while(tmp1[r]==tmp2[r])--r;
		for(int j=l;j<=r;j++)tmp1[j-l]=tmp1[j];
		tmp1.resize(max(r-l+1,0));
		for(int j=l;j<=r;j++)tmp2[j-l]=tmp2[j];
		tmp2.resize(max(r-l+1,0));
		p=make_pair(tmp1,tmp2);
		int ll=lower_bound(s+1,s+n+1,p)-s,rr=upper_bound(s+1,s+n+1,p)-s-1,cnt=0;
		for(int i=ll;i<=rr;i++){
			int kl=l-al[i],kr=ar[i]+r;
			if(kl<0||kr>=len)continue;
			long long h=ha[i]*k[kl]%mod;
			if(h==has[kr+1]-has[kl])++cnt;
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
