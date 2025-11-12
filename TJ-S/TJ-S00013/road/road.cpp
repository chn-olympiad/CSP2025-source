#include<cstdio>
#include<algorithm>
int n,m,k;
const int MAXN=10012,MAXM=1000012,MAXK=20;
int u[MAXM],v[MAXM],w[MAXM];
int c[MAXK];
int a[MAXK][MAXN];
bool t[MAXN+MAXK][MAXN+MAXK];
bool t2[MAXN+MAXK][MAXN+MAXK];
long long minn;
int l=0;
int now1=0,now2=0;
long long money=0;
void a1(int x,int y){
	for(int i=1;i<=n+k;i++)if(t[x][i]){
		t[i][y]=true;
		t[y][i]=true;
	}
	for(int i=1;i<=n+k;i++)if(t[y][i]){
		t[i][x]=true;
		t[x][i]=true;
	}
}
void b1(int x,int y){
	for(int i=1;i<=n+k;i++)if(t[y][i]&&!t2[y][i]&&t2[x][i]){
		t[i][y]=false;
		t[y][i]=false;
	}
	for(int i=1;i<=n+k;i++)if(t[x][i]&&t2[y][i]){
		t[i][x]=false;
		t[x][i]=false;
	}
}
void dfs(){
	if(now1==m){
		bool ok=true;
		for(int i=1;i<=n;i++){
			if(!t[1][i]){
				ok=false;
				break;
			}
		}
		if(ok&&money<minn){
			minn=money;
		}
		return;
	}
	
	
	now1++;
	//t[u[now1]][v[now1]]=true;
	//t[v[now1]][u[now1]]=true;
	a1(u[now1],v[now1]);
	money+=w[now1];
	dfs();
	money-=w[now1];
	b1(u[now1],v[now1]);
	//t[v[now1]][u[now1]]=false;
	//t[u[now1]][v[now1]]=false;
	now1--;
	
	now1++;
	dfs();
	now1--;
	
	now2++;
	money+=a[l][now2];
	t2[l][now2]=true;
	t[n+l][now2]=true;
	t[now2][n+l]=true;
	for(int i=1;i<=n+k;i++)if(t[n+l][i]){
		t[i][now2]=true;
		t[now2][i]=true;
	}
	for(int i=1;i<=n+k;i++)if(t[now2][i]){
		t[i][n+l]=true;
		t[n+l][i]=true;
	}
	dfs();
	for(int i=1;i<=n+k;i++)if(t[now2][i]&&!t2[l][i]){
		t[i][n+l]=false;
		t[n+l][i]=false;
	}
	for(int i=1;i<=n+k;i++)if(t[n+l][i]&&t2[l][i]){
		t[i][now2]=false;
		t[now2][i]=false;
	}
	t[now2][n+l]=false;
	t[n+l][now2]=false;
	t2[l][now2]=false;
	money-=a[l][now2];
	now2--;
	
	
	int t=0;
	
	l++;
	t=now2;
	now2=0;
	money+=c[l];
	dfs();
	money-=c[l];
	now2=t;
	t=0;
	l--;
	
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&u[i],&v[i],&w[i]),minn+=w[i];
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("%d\n",minn);
	return 0;
}
