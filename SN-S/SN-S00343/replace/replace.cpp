//李承恩 SN-S00343 西安湖滨中学
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10,mod=1e9+7,p=131;
int n,q,cnt,L[N],R[N],sum[N],m[N];
vector<int>g[N];
string s[N][2];
map<pair<int,int>,int>v;
int cal(string s){
	int ret=1,k=0;
	for(int i=0;i<s.size();i++)k=(k+(s[i]-'a'+1)*ret)%mod,ret=ret*p%mod;
	return k;
}
int ksm(int a,int b){
	int ret=1;
	while(b){
		if(b&1)ret=ret*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return ret;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	m[n]=ksm(ksm(p,n),mod-2);
	for(int i=n-1;i>=0;i--)m[i]=m[i+1]*p%mod;
	for(int i=1;i<=n;i++){
		string s1,s2,x,y;
		cin>>s1>>s2;
		int l=n,r=0;
		for(int j=0;j<s1.size();j++){
			if(s1[j]!=s2[j])l=min(l,j),r=max(r,j);
		}
		for(int j=l;j<=r;j++)x+=s1[j],y+=s2[j];
		int k1=cal(x),k2=cal(y);
		if(!v[{k1,k2}])v[{k1,k2}]=++cnt;
		g[v[{k1,k2}]].push_back(i);
		s[i][0]=s1,s[i][1]=s2;
		L[i]=l,R[i]=r;
	}
	for(int i=1;i<=q;i++){
		string s1,s2,x,y;
		cin>>s1>>s2;
		int l=n,r=0,ret=1;
		for(int j=0;j<s1.size();j++){
			if(s1[j]!=s2[j])l=min(l,j),r=max(r,j);
			sum[j+1]=(sum[j]+ret*(s1[j]-'a'+1))%mod;
			ret=ret*p%mod;
		}
		for(int j=l;j<=r;j++)x+=s1[j],y+=s2[j];
		int k1=cal(x),k2=cal(y);
		int z=v[{k1,k2}],ans=0;
		for(int j=0;j<g[z].size();j++){
			int x=g[z][j];
			if(l<L[x]||s1.size()-r<s[x][0].size()-R[x])continue;
			int k=cal(s[x][0]);
			int l2=l-L[x],r2=r+s[x][0].size()-R[x]-1;
			int k2=(sum[r2+1]-sum[l2]+mod)%mod*m[l2]%mod;
//			cout<<sum[r2+1]<<" "<<k<<endl;
			if(k2==k)ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
