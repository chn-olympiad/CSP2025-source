#include<bits/stdc++.h>
using namespace std;
int T,n,p[100005],temp;
long long f[100005][4],a[100005][4],ans;
bool s1,s2;
struct data {
	int x,y,z;
}c[100005][3];

void add1(int i,int j) {
	int f1 = 0,temp = 0;
	for(int k = 1;k <= 3;k++) {
		if(c[i-1][k-1].x < n/2) {
			f1 = 1;
			if(f[i-1][k] + a[i][j] > f[i][1]) {
				f[i][1] = f[i-1][k] + a[i][j];
				temp = k;
				c[i][j-1].x = c[i][temp-1].x + 1;
				c[i][j-1].y = c[i][temp-1].y;
				c[i][j-1].z = c[i][temp-1].z;
			}
		}
	}
}
void add2(int i,int j) {
	int f1 = 0,temp = 0;
	for(int k = 1;k <= 3;k++) {
		if(c[i-1][k-1].y < n/2) {
			if(f[i-1][k] + a[i][j] > f[i][2]) {
				f1 = 1;
				f[i][2] = f[i-1][k] + a[i][j];
				temp = k;
				c[i][j-1].x = c[i][temp-1].x;
				c[i][j-1].y = c[i][temp-1].y + 1;
				c[i][j-1].z = c[i][temp-1].z;
			}
		}
	}
}
void add3(int i,int j) {
	int f1 = 0,temp = 0;
	for(int k = 1;k <= 3;k++) {
		if(c[i-1][k-1].z < n/2) {
			if(f[i-1][k] + a[i][j] > f[i][3]) {
				f1 = 1;
				f[i][3] = f[i-1][k] + a[i][j];
				temp = k;
				c[i][j-1].x = c[i][temp-1].x;
				c[i][j-1].y = c[i][temp-1].y;
				c[i][j-1].z = c[i][temp-1].z + 1;
			}
		}
	}
	
}

void dfs(int pos,int t1,int t2,int t3,int a1,int a2,int a3) {
	if(t1 > n/2 || t2 > n/2 || t3 > n/2) {
		return;
	}
	if(pos >= n) {
		ans = max(ans,(long long)a1+a2+a3);
	}
	dfs(pos+1,t1+1,t2,t3,a1+a[pos][1],a2,a3);
	dfs(pos+1,t1,t2+1,t3,a1,a2+a[pos][2],a3);
	dfs(pos+1,t1,t2,t3+1,a1,a2,a3+a[pos][3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		s1 = 0;
		s2 = 0;
		ans = 0;
		for(int i = 1;i <= n;i++) {
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2] != 0) {
				s1 = 1;
			}
			if(a[i][3] != 0) {
				s2 = 1;
			}
		}
		if(!s1 && !s2) {
			long long ans = 0;
			for(int i = 1;i <= n;i++) {
				p[i] = a[i][1];
			}
			sort(p+1,p+1+n);
			for(int i = n;i > n/2;i--) {
				ans += p[i];
			}
			printf("%lld\n",ans);
			continue;
		}
		if(n <= 10) {
			dfs(1,0,0,0,0,0,0);
			printf("%lld\n",ans);
			continue;
		}
		memset(f,0,sizeof(f));
		f[1][1] = a[1][1];
		f[1][2] = a[1][2];
		f[1][3] = a[1][3];
		c[1][0].x = 1;
		c[1][1].y = 1;
		c[1][2].z = 1;
		for(int i = 2;i <= n;i++) {
			for(int j = 0;j < 3;j++) {
				c[i][j].x = c[i-1][j].x;
				c[i][j].y = c[i-1][j].y;
				c[i][j].z = c[i-1][j].z;
			}
			for(int j = 1;j <= 3;j++) {
				if(j == 1) add1(i,j);
				if(j == 2) add2(i,j);
				if(j == 3) add3(i,j);
			}
		}
		printf("%lld\n",max(f[n][1],max(f[n][2],f[n][3])));
	}
	return 0;
}

