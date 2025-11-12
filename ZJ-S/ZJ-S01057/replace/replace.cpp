#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5000005,M=7e7+5;
const LL k=1003,P=(LL)(1e18)+3;
const LL ny=321036889332003989ll;
const __int128 p=1;
struct op{
	LL key[M];
	int val[M];
	inline int& operator[](LL x){
		++x;
		int id=x%M;
		while(key[id]!=x&&key[id])++id,(id==M)&&(id-=M);
		key[id]=x;
		return val[id];
	}
	inline LL cx(LL x){
		++x;
		int id=x%M;
		while(key[id]!=x&&key[id])++id,(id==M)&&(id-=M);
		return val[id];
	}
}id;
int n,m,len,s[N],mi,mx,dx,l,r,mid,v[N];
LL a[N],hs[N],pw[N],o2,kc[N],ans;
char S[N],T[N];
vector<int>mp[N];
int read(char *s0){
	int n=0;
	char c=getchar();
	while(c<'a'||c>'z')c=getchar();
	while('a'<=c&&c<='z')s0[++n]=c,c=getchar();
	return n;
}
void dfs(int x){
	for(int i=0;i<mp[x].size();i++){
		int y=mp[x][i];
		s[y]+=s[x];
		dfs(y);
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pw[0]=kc[0]=1;
	for(int i=1;i<N;i++){
		pw[i]=p*pw[i-1]*ny%P;
		kc[i]=p*kc[i-1]*k%P;
	}
	scanf("%d%d",&n,&m);
	id[0]=++dx;
	for(int i=1;i<=n;i++){
		len=read(S),read(T);
		for(int j=1;j<=len;j++){
			a[j]=(S[j]-'a'+1)*26+(T[j]-'a'+1);
			hs[j]=(hs[j-1]+p*kc[j]*a[j])%P;
			o2=id[hs[j]];
			if(!o2){
				id[hs[j]]=o2=++dx;
				mp[id[hs[j-1]]].push_back(o2);
			}
		}
		++s[o2],++v[o2];
	}
	dfs(1);
	for(int i=1;i<=m;i++){
		len=read(S),mid=read(T);
		if(len!=mid){
			printf("0\n");
			continue;
		}
		mi=N,mx=0;
		for(int j=1;j<=len;j++){
			if(S[j]!=T[j])mi=min(mi,j),mx=max(mx,j);
			a[j]=(S[j]-'a'+1)*26+(T[j]-'a'+1);
			hs[j]=(hs[j-1]+p*kc[j]*a[j])%P;
		}
		ans=0;
		for(int j=1;j<=mi;j++){
			l=mx,r=len;
			o2=p*pw[j-1]*(hs[l]-hs[j-1]+P)%P;
			if(!id.cx(o2))r=mx-1;
			while(l<=r){
				mid=(l+r)/2;
				o2=p*pw[j-1]*(hs[mid]-hs[j-1]+P)%P;
				if(id.cx(o2))l=mid+1;
				else r=mid-1;
			}
			l=mx;
			if(l<=r){
				o2=p*pw[j-1]*(hs[l]-hs[j-1]+P)%P;
				o2=id[o2];
				ans+=v[o2]-s[o2];
				o2=p*pw[j-1]*(hs[r]-hs[j-1]+P)%P;
				o2=id[o2];
				ans+=s[o2];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
