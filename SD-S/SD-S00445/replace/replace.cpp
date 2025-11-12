#include<bits/stdc++.h>
#define int long long
#define N 200005
#define M 5000005
#define pi pair<int,int>
using namespace std;
const int mod=1e9+9,base=331;
int n,q,f1[M],f2[M],ha1[M],ha2[M],b[M],len[N];
int ans[N];
string s1[N],s2[N],t1,t2;
map<int,int>ID;
struct node{
	int x,y,id;
};
bool cmp(node a,node b){
	return a.x<b.x;
}
vector<node>lxy[N],gzq[N];
int h(string s){
	int ans=0;
	for(char c:s)ans=(ans*base+c)%mod;
	return ans;
}
int query1(int l,int r){
	return (f1[r]-f1[l-1]*b[r-l+1]%mod+mod)%mod;
}
int query2(int l,int r){
	return (f2[r]-f2[l-1]*b[r-l+1]%mod+mod)%mod;
}
int qpow(int x,int y){
	int ans=1;
	while(y){
		if(y&1)ans=ans*x%mod;
		x=x*x%mod;y>>=1;
	}
	return ans;
}
struct BIT{
	int c[M];
	void add(int x,int k){
		while(x<M)c[x]+=k,x+=x&-x;
	}
	int ask(int x){
		int ans=0;
		while(x)ans+=c[x],x-=x&-x;
		return ans;
	}
}A;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	b[0]=1;
	for(int i=1;i<M;++i)b[i]=b[i-1]*base%mod;
	cin>>n>>q;
	int f=1;
	for(int i=1;i<=n;++i){
		cin>>s1[i]>>s2[i];len[i]=s1[i].size();
		for(char c:s1[i])f&=(c=='a'||c=='b');
		for(char c:s2[i])f&=(c=='a'||c=='b');
		ha1[i]=h(s1[i]);ha2[i]=h(s2[i]);
	}
	if(f){
		int idx=0;
		for(int i=1;i<=n;++i){
			int rr1=0,rr2=0;
			for(int j=0;j<len[i];++j)if(s1[i][j]=='b')rr1=j;
			for(int j=0;j<len[i];++j)if(s2[i][j]=='b')rr2=j;
			int X=min(rr1,rr2),Y=len[i]-1-max(rr1,rr2);
			if(!ID.count(rr1-rr2))ID[rr1-rr2]=++idx;
			lxy[ID[rr1-rr2]].push_back({X+1,Y+1,0ll});
		}
		for(int i=1;i<=q;++i){
			cin>>t1>>t2;int l=t1.size();
			int rr1=0,rr2=0;
			for(int j=0;j<l;++j)if(t1[j]=='b')rr1=j;
			for(int j=0;j<l;++j)if(t2[j]=='b')rr2=j;
			int X=min(rr1,rr2),Y=l-1-max(rr1,rr2);
			if(ID.count(rr1-rr2))gzq[ID[rr1-rr2]].push_back({X+1,Y+1,i});
		}
		for(int i=1;i<=idx;++i){
			sort(gzq[i].begin(),gzq[i].end(),cmp);sort(lxy[i].begin(),lxy[i].end(),cmp);
			int now=0;
			for(int j=0;j<gzq[i].size();++j){
				while(now<lxy[i].size()&&lxy[i][now].x<=gzq[i][j].x)A.add(lxy[i][now].y,1),++now;
				ans[gzq[i][j].id]=A.ask(gzq[i][j].y);
			}
			for(int j=0;j<now;++j)A.add(lxy[i][j].y,-1);
		}
		for(int i=1;i<=q;++i)cout<<ans[i]<<'\n';
		return 0;
	}
	if(q==1&&n>1000){
		cin>>t1>>t2;
		map<int,int>qwq;
		for(int i=0;i<t1.size();++i)++qwq[b[i]];
		int Q=(h(t1)-h(t2)+mod)%mod,ans=0;
		for(int i=1;i<=n;++i){
			int del=(ha1[i]-ha2[i]+mod)%mod;
			//cout<<Q<<" "<<del<<" "<<Q*qpow(del,mod-2)%mod<<'\n';
			ans+=qwq[Q*qpow(del,mod-2)%mod];
		}
		cout<<ans;
		return 0;
	}
	while(q--){
		cin>>t1>>t2;
		int l=t1.size();t1=" "+t1;t2=" "+t2;
		for(int i=1;i<=l;++i)f1[i]=(f1[i-1]*base+t1[i])%mod;
		for(int i=1;i<=l;++i)f2[i]=(f2[i-1]*base+t2[i])%mod;
		int ans=0;
		for(int i=1;i<=l;++i){
			for(int j=1;j<=n;++j){
				if(i+len[j]-1<=l&&query1(i,i+len[j]-1)==ha1[j]&&query2(i,i+len[j]-1)==ha2[j]){
					if(query1(1,i-1)==query2(1,i-1)&&query1(i+len[j],l)==query2(i+len[j],l))++ans;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
4 1
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
*/
