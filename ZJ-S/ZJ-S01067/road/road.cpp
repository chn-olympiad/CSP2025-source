#include<bits/stdc++.h>
using namespace std;
#define ps putchar(' ')
#define pn putchar('\n')
#define In(x) freopen(x".in","r",stdin)
#define Out(x) freopen(x".out","w",stdout)
#define File(x) (In(x),Out(x))

typedef long long ll;

template<typename T> void re( T &t){
	t=0;int f=1;char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	do{
		(t=((t<<3)+(t<<1)))+=(ch^48);
		ch=getchar();
	}while(ch>='0' && ch<='9');
	t*=f;
}

void wr(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) wr(x/10);
	putchar(x%10+'0');
}

int n,m,k,cnt;

int f[2000005];

struct node{
	int u,v,va;
	friend bool operator < (node x,node y){
		return x.va<y.va;
	}
}a[2000005];

int find(int x){
	return f[x]==x ? x : find(f[x]=find(f[x]));
	
}

ll ans;

int main(){
	File("road");
	re(n),re(m),re(k);
	for(int i=1;i<=m;i++){
		int u,v,va;
		re(u),re(v),re(va);
		a[++cnt]={u,v,va};
	}
	for(int i=n+1;i<=n+k;i++){
		for(int j=0;j<=n;j++){
			int x;
			re(x);
			if(j>0) a[++cnt]={i,j,x};
		}
	}
	for(int i=1;i<=cnt;i++) f[i]=i;
	sort(a+1,a+1+cnt);
	for(int i=1;1;i++){
		int ff=1;
		for(int j=2;j<=n;j++) if(f[j]!=f[j-1]){ ff=0;break;}
		if(ff) break;
		int fu=find(a[i].u),fv=find(a[i].v);
		if(fu==fv) continue;
		f[fu]=fv;
		ans+=a[i].va;
	}
	wr(ans);
	return 0;
}
//Chtholly bless me!
//If happniess has a color,it must be the blue dyed by the last red!
//What are you doing in the end of the wolrd? Are you busy? Will you save us?  
