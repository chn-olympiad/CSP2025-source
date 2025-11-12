#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 50;
long long n,m,k,s[N],d[15][N],ans;
struct f{
	long long a,b,v;
}c[N];
int cz(int x){
	int xx = x;
	if(xx != s[xx])xx = cz(s[xx]);
	return xx;
}
void hb(int x,int y){
	int xx = x,yy = y;
	xx = cz(xx);
	yy = cz(yy);
	if(xx < yy)s[yy] = xx;
	else s[xx] = yy;
}
bool cmp(f x,f y){
	return x.v < y.v;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i = 1;i <= n;i ++){
		s[i] = i;
	}
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i ++){
		cin >> c[m].a >> c[m].b >> c[m].v;
	}
	for(int i = 1;i <= k;i ++){
		for(int j = 0;j <= n;j ++){
			cin >> d[i][j];
		}
	}
	sort(c + 1,c + m + 1,cmp);
	for(int i = 1;i <= m;i ++){
		if(cz(c[i].a) != cz(c[i].b)){
			ans += c[i].v;
			hb(c[i].a,c[i].b);
		}
	}
	cout << ans;
	return 0;
} 
