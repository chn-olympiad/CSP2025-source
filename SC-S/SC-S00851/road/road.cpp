#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<1)+(s<<3)+ch-'0';
		ch=getchar();
	}
	return s*w;
}
void write(int x){
	if(x<0){
		putchar('-');
		write(-x);
		return ;
	}
	if(x<=9){
		putchar('0'+x);
		return ;
	}
	write(x/10);
	putchar('0'+x%10);
	return ;
}
const int N=1e4+5;
const int M=1e6+5;
const int mod=998244353;
const int inf=1e18+7;
int n,m,k;
struct node{
	int qi,dao,w;
}no[N],bian[M];
bool operator <(const node &x,const node &y){
	return x.w<y.w;
}
int a[15][N],c[N];
int f[N],si[N];
void init(){
	for(int i=1;i<=n+k;i++)f[i]=i,si[i]=1;
	return ;
}
int get(int x){
	if(x==f[x])return x;
	return f[x]=get(f[x]);
}
void mg(int a,int b){
	int fx=get(a),fy=get(b);
	if(si[fx]>si[fy])si[fx]+=si[fy],f[fy]=fx;
	else si[fy]+=si[fx],f[fx]=fy;
	return ;
}
int ans=inf,res=0,cnt=0;
int minn[N],mind[N];
void calc(){
	init();
	sort(bian+1,bian+cnt+1);
	for(int i=1;i<=cnt;i++){
		int a=bian[i].qi,b=bian[i].dao,w=bian[i].w;
		if(get(a)==get(b))continue;
		mg(a,b);
		res+=w;
		if(res>=ans)return ;
	}
	ans=min(ans,res);
	return ;
}
signed main(){
//	system("fc road.out road3.ans");
//	return 0;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int a=read(),b=read(),c=read();
		bian[i]={a,b,c};
	}
	sort(bian+1,bian+m+1);
	init();
	cnt=0;
	for(int i=1;i<=m;i++){
		int a=bian[i].qi,b=bian[i].dao,w=bian[i].w;
		if(get(a)==get(b))continue;
		mg(a,b);
		no[++cnt]=bian[i];
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			a[i][j]=read();
		}
	}
	for(int i=(1<<k);i>=0;i--){
		res=0;
		cnt=0;
		for(int j=1;j<=n;j++){
			minn[j]=inf,mind[j]=0;
		}
		for(int j=1;j<n;j++){
			bian[++cnt]=no[j];
		}
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1))){
				res+=c[j];
				for(int l=1;l<=n;l++){
					if(a[j][l]<=minn[l]){
						minn[l]=a[j][l];
						mind[l]=j;
					}
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(mind[j]){
				bian[++cnt]={j,n+mind[j],minn[j]};
			}
		}
		calc();
	}
	cout<<ans<<endl;
	return 0;
}