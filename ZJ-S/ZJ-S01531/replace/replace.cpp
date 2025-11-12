#include<bits/stdc++.h>
using namespace std;
const int N=6e5+10,M=1e5+10,bs=30;
int mod[2]={998244353,1000000007};
inline int read(){
    int x=0,fg=0;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fg=1; ch=getchar();}
    while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
    return fg?(~(x-1)):x;
}
struct node{
	int a[2],b[2];
	bool operator<(const node y)const{
		if(a[0]!=y.a[0]) return a[0]<y.a[0];
		if(b[0]!=y.b[0]) return b[0]<y.b[0];
		if(a[1]!=y.a[1]) return a[1]<y.a[1];
		return b[1]<y.b[1];
	}
	bool operator!=(const node y){
		return a[0]!=y.a[0]||a[1]!=y.a[1]||b[0]!=y.b[0]||b[1]!=y.b[1];
	}
};
map<node,queue<int> >mp;
char c[N],d[N];
string s[M];
node e[M];int la[M],ra[M];
node wrk(int l,int r){
	node z={0,0,0,0};
	for(int i=l;i<=r;i++){
		for(int j=0;j<1;j++){
			z.a[j]=(1ll*z.a[j]*bs+c[i]-'a')%mod[j];
			z.b[j]=(1ll*z.b[j]*bs+d[i]-'a')%mod[j];
		}
	}
	return z;
}
int n,q;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    n=read(),q=read();
    for(int i=1;i<=n;i++){
    	scanf("%s%s",c+1,d+1);
    	int l=n+1,r=-1,len=strlen(c+1);
    	for(int j=1;j<=len;j++)
    		if(c[j]!=d[j]) l=min(l,j),r=max(r,j);
    	for(int j=1;j<=len;j++) s[i].push_back(c[j]);
		e[i]=wrk(l,r),la[i]=l,ra[i]=r,mp[e[i]].push(i);
	}
	while(q--){
		scanf("%s%s",c+1,d+1);
		int l=n+1,r=-1,len=strlen(c+1);
    	for(int j=1;j<=len;j++)
    		if(c[j]!=d[j]) l=min(l,j),r=max(r,j);
    	node x=wrk(l,r);int ans=0;
    	queue<int>q=mp[x];
    	while(q.size()){
    		int i=q.front();q.pop();
    		int flg=1;
    		for(int j=1;j<=la[i];j++)
    			if(l-(la[i]-j)<=0||s[i][j-1]!=c[l-(la[i]-j)])
    				{flg=0;break;}
    		for(int j=ra[i]+1;j<=s[i].size();j++)
    			if(r+(j-ra[i])>len||!flg||s[i][j-1]!=c[r+(j-ra[i])])
    				{flg=0;break;}
    		ans+=flg;
		}
		printf("%d\n",ans);
	}
    return 0;
}






















