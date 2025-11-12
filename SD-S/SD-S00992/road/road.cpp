#include<bits/stdc++.h>
using namespace std;
const int maxn = 11111,maxm = 1111111,maxk = 15;
int n,m,k,c[maxk],a[maxk][maxn];
struct stu{
	int u,v,w;
}m1[maxm];
int minn[maxn][maxn];
int main(){
	//cout << sizeof(minn)/1024/1024 << endl;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		cin >> m1[i].u >> m1[i].v >> m1[i].w;
	}
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		for(int j = 1;j <= n;j++){
			cin >> a[i][j];
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			if(k > 0)minn[i][j] = a[1][i]+a[1][j];
			for(int l = 2;l <= k;l++){
				minn[i][j] = min(minn[i][j],a[l][i]+a[l][j]);
			} 
			minn[j][i] = minn[i][j];
		}
	} 
	for(int i = 1;i <= m;i++){
		minn[m1[i].u][m1[i].v] = minn[m1[i].v][m1[i].u] = min(minn[m1[i].u][m1[i].v],m1[i].w);
	}
	int minnn[5] = {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX},mi[5][3];
	for(int i = 1;i <= 4;i++){
		for(int j = 1;j <= n;j++){
			for(int l = 1;l <= n;l++){
				if(minn[j][j] < 0)continue;
				if(minnn[i] > minn[j][l])minnn[i] = minn[i][l],mi[i][1] = j,mi[i][2] = l;
			}
		}
		minn[mi[i][1]][mi[i][2]] = -minn[mi[i][1]][mi[i][2]]-1;
	}
	cout << minnn[1] + minnn[2] + minnn[3] + minnn[4] + minnn[5] << endl;
	return 0;
}


