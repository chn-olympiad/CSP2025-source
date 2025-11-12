#include<bits/stdc++.h>

#define hyc_qcz_jmr_baoyouwo_AC
#define zty_AK_CSPS_2025

#define rep(i,s,e) for(int i=s;i<=e;i++)
#define fep(i,s,e) for(int i=s;i<e;i++)
#define per(i,s,e) for(int i=s;i>=e;i--)
#define pef(i,s,e) for(int i=s;i>e;i--)

namespace FastIO{
	template <typename T> inline void read(T &x){
		x=0;
		T f=1;
		T c=getchar();
		for(;!isdigit(c);c=getchar()){
			if(c=='-'){
				f=-1;
			}
		}
		for(;isdigit(c);c=getchar()){
			x=(x<<1)+(x<<3)+(c^48);
		}
		x*=f;
	}
	template <typename T> inline void print(T x){
		if(x<0){
			x=-x;
			putchar('-');
		}
		if(x>9){
			print(x/10);
		}
		putchar((x%10)^48);
	}
}

using namespace std;
using namespace FastIO;
struct edge{
	int u;
	int v;
	long long w;
}e[1000005];
struct nw_node{
	long long c;
	long long w[10005];
	bool chos;
}pq[15];
struct node{
	vector<pair<int,long long> >son;
	int fa;
}p[10005]; 
int n,m,k,u,v,cnt;
long long w,ans[15],dis[1005][1005];
bool hav[1005][1005];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int find_an(int now){
	if(p[now].fa==now){
		return now;
	}
	return p[now].fa=find_an(p[now].fa);
}
void con(int fir,int sec,long long thr,int nw){
	int an_fir=find_an(fir);
	int an_sec=find_an(sec);
	if(an_fir!=an_sec){
		cnt++;
		p[an_fir].fa=an_sec;
		ans[nw]+=thr;
	}
}
void kruskal(int nw){
	rep(i,1,n){
		p[i].fa=i;
	} 
	sort(e+1,e+cnt+1,cmp);
	cnt=0;
	rep(i,1,m){
		con(e[i].u,e[i].v,e[i].w,nw);
		if(cnt==n-1){
			break;
		} 
	}
}
int main(){
	hyc_qcz_jmr_baoyouwo_AC
	zty_AK_CSPS_2025
//	freopen("road2.in","r",stdin);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	read(m);
	read(k);
	rep(i,1,m){
		read(e[i].u);
		read(e[i].v);
		read(e[i].w);
		dis[e[i].u][e[i].v]=dis[e[i].v][e[i].u]=e[i].w;
		hav[e[i].u][e[i].v]=hav[e[i].v][e[i].u]=1;
	}
	cnt=m;
	kruskal(0);
	if(k==0){
		print(ans[0]);
		return 0;
	} 
//	cout<<ans[0]<<endl;
//	cout<<11111<<endl;
	rep(i,1,k){
//		cout<<i<<" "<<11111<<endl;
		read(pq[i].c);
		cnt=0;
		rep(j,1,n){
			read(pq[i].w[j]);
			fep(l,1,j){
				cnt++;
				e[cnt].u=j;
				e[cnt].v=l;
				if(hav[j][l]==0){
					e[cnt].w=pq[i].w[j]+pq[i].w[l];
				}
				else{
					e[cnt].w=min(dis[j][l],pq[i].w[j]+pq[i].w[l]);
				}
//				cout<<e[cnt].u<<" "<<e[cnt].v<<" "<<e[cnt].w<<endl;
			}
		} 
//		cout<<cnt<<endl;
		kruskal(i);
		if(ans[i]+pq[i].c<ans[0]){
			ans[0]=ans[i]+pq[i].c;
			rep(j,1,n){
				fep(l,1,j){
					if(hav[l][j]==0){
						hav[l][j]=1;
						dis[l][j]=dis[j][l]=e[cnt].w;
					}
					else{
						dis[l][j]=dis[j][l]=min(dis[j][l],e[cnt].w);
					}
				}
			}
		}
	}
	print(ans[0]);
	return 0;	
}