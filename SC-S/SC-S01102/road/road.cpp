#include<bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;
int read(){
	int ans=0,j=1;
	char c=getchar();
	while(c>'9' or c<'0'){
		if(c=='-')
			j=-1;
		c=getchar();
	}
	while(c>='0' and c<='9'){
		ans=(ans<<3)+(ans<<1)+(c^48);
		c=getchar();
	}
	return ans*j;
}
void write(int x){
	if(x<0)
		putchar('-'),
		x=-x;
	if(x>9)
		write(x/10);
	putchar('0'+x%10);
}
const int N=2e6+5,M=1e4+5;
int n,m,k,c[N];
struct node{
	int x,y,w;
	bool operator<(const node &p)const{
		return w<p.w;
	}
}s[N];
struct f{
	int p,w;
	bool operator<(const f &p)const{
		return w<p.w;
	}
}a[11][M];
int fa[N],ans=1e18;
int ask(int x){
	if(x==fa[x])
		return x;
	return fa[x]=ask(fa[x]);
}
float bbc=CLOCKS_PER_SEC*0.92;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i)
		s[i]={read(),read(),read()};
	sort(s+1,s+m+1);
	for(int i=1;i<=k;++i){
		c[i]=read();
		for(int j=1;j<=n;++j)
			a[i][j]={j,read()};
		sort(a[i]+1,a[i]+n+1);
	}
	for(int st=0;st<(1<<k);++st){
//		cout<<"st="<<st<<'\n';
		for(int i=1;i<=n+k;++i)
			fa[i]=i;
		int now=0,cnt=n-1;
		vector<int> e;
		for(int i=1;i<=k;++i)
			if(st&(1<<(i-1)))
				now+=c[i],++cnt,e.push_back(i);
		int b[12]={0};
		for(int i=0;i<=11;++i)
			b[i]=1;
		while(cnt){
			if(now>=ans)
				break;
			int mn=1e18,mid=-1;
			if(b[11]<=m)
				mn=s[b[11]].w,mid=11;
			for(int i=0;i<e.size();++i)
				if(b[i]<=n and a[e[i]][b[i]].w<mn)
					mn=a[e[i]][b[i]].w,mid=i;
//			cout<<"use"<<cnt<<" "<<mn<<' '<<mid<<' '<<b[mid]<<'\n';
			int x,y;
			if(mid==11)
				x=s[b[11]].x,y=s[b[11]].y;
			else
				x=n+e[mid],y=a[e[mid]][b[mid]].p;
//			cout<<"x="<<x<<' '<<"y="<<y<<'\n';
			int fx=ask(x),fy=ask(y);
			if(fx!=fy)
				fa[fx]=fy,--cnt,now+=mn;
			++b[mid];
			if(clock()>bbc){
				now=1e18;//这次不算数
				break;
			}
		}
		ans=min(ans,now);
		if(clock()>bbc)
			break;
	}
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/