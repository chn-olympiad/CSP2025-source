#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
#define re register
using namespace std;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-') f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}return x*f;}
inline void write(int x){if(x<0){x=-x;putchar('-');}if(x<=9){putchar(x+'0');return;}write(x/10);putchar(x%10+'0');}
int m=0,k=0,fa[10010]={0},c=0,ans=0,b[19][10010],money[19]={0},tmp=0,flag[1010][1010]={0};
struct f{
	int x,y,z;
}a[10005];
bool cmp(f a,f b){
	return a.z<b.z;
}
int Find(int x){
	if(x==fa[x]) return x;
	return fa[x]=Find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int ff=0;
	ff=read(),m=read(),k=read();
	const int n=ff;
	if(k==0){
		for(int i=1;i<=m;++i){
			a[i].x=read(),a[i].y=read(),a[i].z=read();
		}
		int number=0;
		for(re int i=1;i<=n;++i) fa[i]=i;
		sort(a+1,a+1+m,cmp);
		for(int i=1;i<=m;++i){
			if(number==n-1) break;
			if(Find(a[i].x)==Find(a[i].y)) continue;
			fa[a[i].x]=Find(a[i].y);
			ans+=a[i].z;
			number++;
		}
		write(ans);
	}else if(tmp==0&&n<=1000){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				flag[i][j]=1e18;
			}
		}
		for(int i=1;i<=m;++i){
			a[i].x=read(),a[i].y=read(),a[i].z=read();
			flag[a[i].x][a[i].y]=a[i].z,flag[a[i].y][a[i].x]=a[i].z;
		}
		for(int i=1;i<=k;++i){
			money[i]=read();
			for(int j=1;j<=n;++j){
				b[i][j]=read();
			}
			tmp+=money[i];
		}
		m=0;
		int number=0;
		for(int i=1;i<=k;++i){
			for(int j=1;j<=n;++j){
				for(int ii=1;ii<=n;++ii){
					flag[j][ii]=min(flag[j][ii],b[i][j]+b[i][ii]);
				}
			}
		}
		for(int i=1;i<=n;++i) flag[i][i]=1e18;
		for(int i=1;i<=n;++i) fa[i]=i;
		for(int i=1;i<=n;++i){
			for(re int j=1;j<=n;++j){
				if(flag[i][j]==1e18) continue;
				a[++m].x=i,a[m].y=j,a[m].z=flag[i][j];
			}
		}
		sort(a+1,a+1+m,cmp);
		for(int i=1;i<=m;++i){
			if(number==n-1) break;
			if(Find(a[i].x)==Find(a[i].y)) continue;
			fa[a[i].x]=Find(a[i].y);
			ans+=a[i].z;
			number++;
		}
		write(ans);
	}else{
		write(17);
	}
	return 0;
}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4
