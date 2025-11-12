#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
#define L(i,a,b) for(int i=(a);i<=(b);i++)
#define R(i,a,b) for(int i=(a);i>=(b);i--)
#define minl aijodsjlasd
#define gmap iadsjkjifes
#define vis bhaodskkasdl
#define bokk adsijoasiofjf
#define addE foidhsidfsiua
//#define SCGMAP L(i,1,n){L(j,1,n)printf("%d ",gmap[i][j]>1e8?-1:gmap[i][j]);printf("\n");}printf("\n");
using namespace std;
const int Mxn=1e3+10;
const int Mxm=1e6+10;
const int Mxk=21;
int n,m,k;
int d[Mxn];
long long ans=0;
int gmap[Mxn][Mxn];
int minl[Mxn];
bool vis[Mxn];
void addE(int x,int y,int d) {
	gmap[x][y]=gmap[y][x]=d;
}
void prim(int s);
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	memset(gmap,0x3f,sizeof(gmap));
	L(i,1,m) {
		int x,y,d;
		scanf("%d%d%d",&x,&y,&d);
		addE(x,y,d);
	}
	L(i,1,n)gmap[i][i]=0;
	L(i,1,k) {
		int c;scanf("%d",&c);//c=0 24·Ö 
		L(j,1,n)scanf("%d",d+j);
		L(j1,1,n)L(j2,1,n){
			gmap[j1][j2]=Min(gmap[j1][j2],d[j1]+d[j2]);
		}
	}
//SCGMAP
	prim(1);
	L(i,1,n)ans+=minl[i];
	printf("%lld\n",ans);
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
void prim(int s) {
	memset(vis,false,sizeof(vis));
	memset(minl,0x3f,sizeof(minl));
	L(i,1,n)minl[i]=gmap[s][i];
	vis[s]=true;
	L(i,1,n) {
		int km=1e9,k=0;
		L(j,1,n) {
			if(vis[j])continue;
			if(km>minl[j])km=minl[j],k=j;
		}
		vis[k]=true;
		L(j,1,n) {
			if(vis[j])continue;
			minl[j]=Min(minl[j],gmap[j][k]);
		}
	}
}
