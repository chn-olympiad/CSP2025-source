#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
long long n,m,k,ju[10001][10001],dis[10001],zou=0;
bool zhuang[10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	memset(ju,0x7f7f7f7f,sizeof(ju));
	for(int i=1;i<=n;i++){
		ju[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		int y,x;
		ll bao;
		scanf("%d%d%lld",&y,&x,&bao);
		ju[y][x]=bao;
		ju[x][y]=bao;
	}
	for(int i=1;i<=k;i++){
		ll bao,c[10001];
		scanf("%lld",&bao);
		for(int o=1;o<=m;o++){
			scanf("%lld",&c[o]);
		}
		for(int o=1;o<=m;o++){
			for(int p=1;p<=m;p++){
				if(o!=p){
					ll baon=c[o]+c[p]+bao;
					if(baon<ju[o][p]){
						ju[o][p]=baon;
					}
				}
			}
		}
	}
	memset(dis,0x7f7f7f7f,sizeof(dis));
	dis[1]=0;
	for(int i=1;i<=n;i++){
		ll kn=0;
		ll minn=0x7f7f7f7f;
		for(int j=1;j<=n;j++){
			if(!zhuang[j]&&minn>dis[j]){
				minn=dis[j];
				kn=j;
			}
		}
		if(kn==0) break;
		for(int j=1;j<=n;j++){
			if(!zhuang[j]&&dis[j]>ju[kn][n]){
				dis[j]=ju[kn][n];
			}
		}
		zhuang[kn]=true;
	}
	for(int i=1;i<=n;i++){
		zou+=dis[i];
	}
	printf("%lld\n",zou);
	return 0;
}
