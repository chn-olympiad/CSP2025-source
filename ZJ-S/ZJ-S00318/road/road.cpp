#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define sc(a) scanf("%d",&a)
#define put(a) printf("%lld\n",a)
#define scan(a,b) scanf("%d%d",&a,&b)
int n,m,k,t;
int T;
const long long inf=1e17;
const int N=1e6+20;
const int N2=1e5+20;
int cntt[N];
int f[N],s[N],x,y,w,c[15],id;
long long cnt,ans;

struct node{
	int x,y,w;
	friend bool operator<(const node &a,const node &b){
		return a.w<b.w;
	}
}a[N],aa[N2],b[N2],d[11][10005],cc[N2];
int find(int x){
	return (f[x]==x)?x:f[x]=find(f[x]);
}
bool merge(int x,int y,int w){
	int fx=find(x),fy=find(y);
	if(fx==fy) return 0;
	cnt+=w;
	//put(w);
	if(s[fx]>s[fy]) swap(fx,fy);
	f[fx]=fy;
	s[fy]+=s[fx];
	return 1;
	
}
void hebing(node *&a,int n,node *&bb,int m){
	int k=0;
	int i=1,j=1;
	while(i<=n&&j<=m){
		if(i>n){
			while(j<=m){
				cc[++k]=bb[j++];
			}
		}
		if(j>m){
			while(i<=n){
				cc[++k]=a[i++];
			}
		}
		if(a[i]<bb[j]) cc[++k]=a[i++];
		else cc[++k]=bb[j++];
	}
	id=n+m;
	rep(i,1,id){
		b[i]=cc[i];
	}
	
	
	
}
void solve(){
	ans=inf;
	scan(n,m);sc(k);
	rep(i,1,n+k){
		f[i]=i;
		s[i]=1;
	}
	rep(i,1,m){
		scan(x,y);
		sc(w);
		a[i]=(node){x,y,w};
	}
	rep(i,1,k){
		sc(c[i]);
		rep(j,1,n){
			sc(d[i][j].w);
			d[i][j].y=j;
			d[i][j].x=n+i;
		}
		sort(d[i]+1,d[i]+1+n);
	}
	

	
	
	
	cnt=0;
	sort(a+1,a+m+1);
	rep(i,1,m){
		if(merge(a[i].x,a[i].y,a[i].w)){
			aa[++t]=a[i];
		}
	}
	if(k==0){
		put(cnt);
		return ;
	}
	m=n;
	for(int i=1;i<(1ll<<k);i++){
		
		
		
		
		cnt=0;
		id=0;
		rep(j,1,n+k){
			f[j]=j;
			s[j]=1;
		}
		rep(j,1,t){
			b[++id]=aa[j];
		}
		id=t;
		rep(j,1,k){
			if(i&(1<<(j-1))){
				cnt+=c[j];
			
				
				int kk=0;
				int ii=1,jj=1;
				while(ii<=id||jj<=m){
					if(ii>id){
						while(jj<=m){
							cc[++kk]=d[j][jj++];
						}
						break;
					}
					if(jj>m){
						while(ii<=id){
							cc[++kk]=b[ii++];
						}
						break;
					}
					if(b[ii]<d[j][jj]) cc[++kk]=b[ii++];
					else cc[++kk]=d[j][jj++];
				}
				swap(cc,b);
				id+=n;
				
				
				
				
			}
		}
	

		rep(j,1,id){
			merge(b[j].x,b[j].y,b[j].w);
//			put(b[j].x),put(b[j].y);put(b[j].w);
//			put(999999);
			

		}
	
		ans=min(ans,cnt);
	}
	put(ans);
	
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	solve();
	
	return 0;
}
