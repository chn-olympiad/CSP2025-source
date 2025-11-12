#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
typedef long long ll;
using namespace std;
const int maxn=1e4+10;
int n;
struct node{
	int x[3]={0,0,0};
}a[maxn];
bool cmp(node a,node b){
	int maxa=max(a.x[0],max(a.x[1],a.x[2]));
	int maxb=max(b.x[0],max(b.x[1],b.x[2]));
	return maxa<maxb;
}
int f[maxn][3];
int qwq[maxn][3];
int RP=INF;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	++RP;
	int T;cin>>T;
	while(T--){
		memset(f,0,sizeof(f));
		memset(qwq,0,sizeof(qwq));
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i].x[0]>>a[i].x[1]>>a[i].x[2];
		//sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				/*f[i][k][j]=max(f[i-1][k-1][0]+a[i][j],max(f[i-1][k-1][1]+a[i][j],f[i-1][k-1][2]+a[i][j]));
				cout<<f[i][k][j]<<'\n';*/
				int fa=f[i-1][0]+a[i].x[j],fb=f[i-1][1]+a[i].x[j],fc=f[i-1][2]+a[i].x[j];
				int numa=qwq[i-1][0],numb=qwq[i-1][1],numc=qwq[i-1][2];
				if(fa>=fb&&fa>=fc&&numa<(n/2)){
					qwq[i][0]=numa+1;   
					//qwq[i][1]=numb;
					//qwq[i][2]=numc;
					f[i][j]=fa;
				}
				else if(((fb>=fa&&fb>=fc)||numa>=(n/2))&&numb<(n/2)){
					//qwq[i][0]=numa;
					qwq[i][1]=numb+1;
					//qwq[i][2]=numc;
					f[i][j]=fb;
				}
				else{
					//qwq[i][0]=numa;
					//qwq[i][1]=numb;
					qwq[i][2]=numc+1;
					f[i][j]=fc;
				}
				//cout<<f[i][j]<<' ';
				//cout<<fa<<'$'<<fb<<'$'<<fc<<'\n';
			}
			for(int j=0;j<3;j++){if(qwq[i][j]==0)qwq[i][j]=qwq[i-1][j];}	
		}
		cout<<max(f[n][0],max(f[n][1],f[n][2]))<<'\n';
		//for(int i=1;i<=n;i++){for(int j=0;j<3;j++)cout<<qwq[i][j];cout<<'\n';}
	}
	
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/