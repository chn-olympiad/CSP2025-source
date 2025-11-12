#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=5e6+10;
const int p1=1e4+9,m1=1e9+7;
const int p2=10273,m2=998244353;
int n,q,f1[M],f2[M],l[N],g1[N],g2[N],b[N],h1[M],h2[M],nxt[M],s[M],t[700];
string s1,s2;
int tot;
unordered_map<int,int>mp;
map<pair<int,int>,int>tr[N];
void upd(int id,int x,int y){
	if(!mp.count(id))mp[id]=++tot;
	id=mp[id];
	for(int i=x;i<M;i+=i&(-i))
		for(int j=y;j<M;j+=j&(-j))
			tr[id][{i,j}]++;
}
int qry(int id,int x,int y){
	if(!mp.count(id))return 0;
	id=mp[id];
	int res=0;
	for(int i=x;i>0;i-=i&(-i))
		for(int j=y;j>0;j-=j&(-j))
			if(tr[id].count({i,j}))
				res+=tr[id][{i,j}];
	return res;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	f1[0]=f2[0]=1;
	for(int i=1;i<=5000000;i++)
		f1[i]=1ll*f1[i-1]*p1%m1,
		f2[i]=1ll*f2[i-1]*p2%m2;
	bool sub=1;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		int len=s1.size();
		int X=0,Y=0;
		if(sub)
			for(int i=0;i<len;i++){
				if(s1[i]=='b'){if(!X)X=i+1;else sub=0;}
				else if(s1[i]!='a')sub=0;
				if(s2[i]=='b'){if(!Y)Y=i+1;else sub=0;}
				else if(s2[i]!='a')sub=0;
			}
		if(!X||!Y)sub=0;
		if(sub)upd(Y-X,X,len-X+1);
		l[i]=len;
		for(int j=0,x;j<len;j++)
			x=(s1[j]-'a')*26+s2[j]-'a',
			g1[i]=(1ll*g1[i]*p1+x)%m1,
			g2[i]=(1ll*g2[i]*p2+x)%m2;
		b[i]=(s1[0]-'a')*26+s2[0]-'a';
	}
	while(q--){
		cin>>s1>>s2;
		int len=s1.size();
		if(s2.size()!=len){cout<<"0\n";continue;}
		int X=0,Y=0;
		if(sub)
			for(int i=0;i<len;i++){
				if(s1[i]=='b'){if(!X)X=i+1;else sub=0;}
				else if(s1[i]!='a')sub=0;
				if(s2[i]=='b'){if(!Y)Y=i+1;else sub=0;}
				else if(s2[i]!='a')sub=0;
			}
		if(!X||!Y)sub=0;
		if(sub){cout<<qry(Y-X,X,len-X+1)<<'\n';continue;}
		int L=1,R=len;
		for(;L<=len&&s1[L-1]==s2[L-1];L++);
		for(;R>=1&&s1[R-1]==s2[R-1];R--);
		for(int j=1;j<=len;j++)
			s[j]=(s1[j-1]-'a')*26+s2[j-1]-'a',
			h1[j]=(1ll*h1[j-1]*p1+s[j])%m1,
			h2[j]=(1ll*h2[j-1]*p2+s[j])%m2;
		for(int i=0;i<676;i++)t[i]=len+1;
		for(int j=len;j;j--)
			nxt[j]=t[s[j]],t[s[j]]=j;
		int res=0;
		for(int i=1;i<=n;i++)
			for(int j=t[b[i]];j<=L&&j+l[i]-1<=len;j=nxt[j])
				if(j+l[i]>R&&
				h1[j+l[i]-1]==(g1[i]+1ll*h1[j-1]*f1[l[i]]%m1)%m1&&
				h2[j+l[i]-1]==(g2[i]+1ll*h2[j-1]*f2[l[i]]%m2)%m2)
					res++;
		cout<<res<<'\n';
	}
	return 0;
}
