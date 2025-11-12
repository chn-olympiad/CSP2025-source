#include <bits/stdc++.h>
using namespace std;

const int N=105;
int n,m,id[N],a[N];

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]),id[i]=i;
	sort(id+1,id+1+n*m,[&](int x,int y) {
		return a[x]>a[y];
	});
	int posx=1,posy=1,down=1;
	for(int i=1;i<=n*m;i++) {
		if(id[i]==1) return printf("%d %d\n",posy,posx),0;
		if(down&&posx==n) ++posy,down=0;
		else if(!down&&posx==1) ++posy,down=1;
		else if(down) ++posx;
		else --posx;
	}
	return 0;
}
