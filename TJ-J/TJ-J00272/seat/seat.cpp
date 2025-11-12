#include <cstdio>
#include <algorithm>

const int maxn=15;
int a[maxn],mp[maxn][maxn];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	int r=a[1];
	
	std::sort(a+1,a+n*m+1,cmp);
	
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		if(x<1||x>n){
			if(x<1) x=1;
			else x=n;
			y++;
		}
		mp[x][y]=a[i];
		
		if(y&1) x++;
		else x--;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]==r) printf("%d %d\n",j,i);
		}
	}
	return 0;
}
