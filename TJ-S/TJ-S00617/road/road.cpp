#include<bits/stdc++.h>
using namespace std;

const int N=1e4+10;
const int M=1e6+10;

struct SD{
	int u;
	int v;
	int w;
};

int twnCnt;
int sdCnt;
int cunCnt;
SD sd[M];
int bsCun[N];
int cun[N][N];

int fa[N];

long long ans;

bool cmp(SD x,SD y){
	return x.w<y.w;
}

int fndFa(int x){
	if(fa[x]==x){
		return x;
	}
	fa[x]=fndFa(fa[x]);
	return fa[x];
}

void slv1(){
	sort(sd+1,sd+sdCnt+1,cmp);
	
//	for(int i=1;i<=sdCnt;i++){
//		cout<<sd[i].u<<" "<<sd[i].v<<" "<<sd[i].w<<"\n";
//	}
	
	int cnt=0;
	int uFa;
	int vFa;
	int tot=sdCnt;
	for(int i=1;i<=sdCnt;i++){
		uFa=fndFa(sd[i].u);
		vFa=fndFa(sd[i].v);
		if(uFa!=vFa){
			fa[vFa]=uFa;
			ans+=sd[i].w;
			tot--;
		}
		if(tot==1){
			break;
		}
	}
	cout<<ans;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>twnCnt>>sdCnt>>cunCnt;
	for(int i=1;i<=twnCnt;i++){
		fa[i]=i;
	}
	for(int i=1;i<=sdCnt;i++){
		cin>>sd[i].u>>sd[i].v>>sd[i].w;
	}
	for(int i=1;i<=cunCnt;i++){
		cin>>bsCun[i];
		for(int j=1;j<=twnCnt;j++){
			cin>>cun[i][j];
		}
	}
	slv1();
	return 0;
} 
