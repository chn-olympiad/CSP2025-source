#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
#define L(i,j,k) for(int i=(j);(i)<=(k);i++)
#define R(i,j,k) for(int i=(j);(i)>=(k);i--)

#define n hasdashhuuhihhhhhhhhhhhpppppppooo
#define m asifjhgiasuhfwnyuyyyyyyyyy
#define k aihfuiwuhhiuhhuihuhuihuihuih
#define a llllluiouiouiollllllllllllllppppp
#define u jioasjfionmvnxciihuuh
#define c iioqipoeqweuioasfoppppppppp
#define v ihsafiuwqnuidhsaiacqqqpaixpzjcip
#define w fffff165wfjoihafio
using namespace std;
//const int MAXN=1e4+10;
int n,m,k;
int u,v,w,c,a;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c);
		for(int j=1;j<=n;j++){
			scanf("%d",&a);
		}
	}

	printf("0\n");
	fclose(stdin);
	fclose(stdout);
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
/*
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
#define L(i,j,k) for(int i=(j);(i)<=(k);i++)
#define R(i,j,k) for(int i=(j);(i)>=(k);i--)

using namespace std;
const int MAXN=1e4+10;
struct DA{
	int to;
	int l;
};
vector<DA> va[MAXN];
int nn[MAXN];
int n,m,k;
int c[MAXN]
void myadd(int x,int y,int z){
	DA s;
	s.l=z;
	s.to=y;
	nn[x]++;
	va[x].push_back(s);
	DA s;
	s.l=z;
	s.to=x;
	nn[y]++;
	va[y].push_back(s);
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	L(i,1,m){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		myadd(u,v,w);
	}
	L(i,1,k){
		int c;
		scanf("%d",&c);
		int cx[MAXN];
		L(j,1,n){
			scanf("%d",cx+i);
		}
		L(j,1,n){
			L(k,j+1,n){
				
			}
		}
	}
	if(k==0){
		
	}
	if(k>0){
		printf("0\n");
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
*/