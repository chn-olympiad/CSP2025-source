#include<bits/stdc++.h>
#define int long long

const int N=100010;

using namespace std;

int T;

int n,m,cnt[5];

int tot,ans;

struct node{
	int x,y,z,id;
}a[N];

int d[N];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')ret=ret*10+(ch&15),ch=getchar();
	return ret*f;
}

void _solve(){
	n=read(),m=0,tot=0,ans=0;
	for(int i=1;i<=3;i++)cnt[i]=0;
	for(int i=1;i<=n;i++)a[i].x=read(),a[i].y=read(),a[i].z=read(),a[i].id=0;
	for(int i=1;i<=n;i++){
		if(a[i].x>=a[i].y&&a[i].x>=a[i].z)a[i].id=1,ans+=a[i].x;
		else{
			if(a[i].y>=a[i].x&&a[i].y>=a[i].z)a[i].id=2,ans+=a[i].y;
			else{
				if(a[i].z>=a[i].x&&a[i].z>=a[i].y)a[i].id=3,ans+=a[i].z;
			}
		}
		cnt[a[i].id]++;
	}
	if(cnt[1]>(n/2)){
		m=cnt[1]-(n/2);
		for(int i=1;i<=n;i++){
			if(a[i].id==1){
				int tmp=min(a[i].x-a[i].y,a[i].x-a[i].z);
				d[++tot]=tmp;
			}
		}
	}else{
		if(cnt[2]>(n/2)){
			m=cnt[2]-(n/2);
			for(int i=1;i<=n;i++){
				if(a[i].id==2){
					int tmp=min(a[i].y-a[i].x,a[i].y-a[i].z);
					d[++tot]=tmp;
				}
			}
		}else{
			if(cnt[3]>(n/2)){
				m=cnt[3]-(n/2);
				for(int i=1;i<=n;i++){
					if(a[i].id==3){
						int tmp=min(a[i].z-a[i].x,a[i].z-a[i].y);
						d[++tot]=tmp;
					}
				}
			}
		}
	}
	sort(d+1,d+tot+1);
	for(int i=1;i<=m;i++)ans-=d[i];
	printf("%lld\n",ans);
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)_solve();
	return 0;
}
