#include<bits/stdc++.h>

#define int long long

using namespace std;

int read(){
	int x = 0,y = 1;
	char ch = getchar();
	while(ch < '0'||ch > '9'){
		if(ch == '-') y = -1;
		ch = getchar();
	}
	while(ch >= '0'&&ch <= '9'){
		x = x*10+ch-'0';
		ch = getchar();
	}
	return x*y;
}

void print(int x){
	char ch = x%10+'0';
	if(x < 10){
		printf("%c",ch);
		return;
	}
	print(x/10);
	printf("%c",ch);
}

int n,m,k;
struct nd{
	int u,v,w;
}e[2000005],e2[1000005];
int c[15][10005];
int fa[10005];

int find(int x){
	if(x == fa[x]) return x;
	else return fa[x] = find(fa[x]);
}

bool cmp(nd x,nd y){
	return x.w < y.w;
}
signed main(){

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	n = read();m = read();k = read();
	
	for(int i = 1;i <= m;++ i){
		e2[i].u = read();e2[i].v = read();e2[i].w = read();
	}
	
	sort(e2+1,e2+1+m,cmp);
	
	for(int i = 1;i <= n;++ i) fa[i] = i;
	int mcnt = 0;
	for(int i = 1;i <= m;++ i){
		if(find(e2[i].u) == find(e2[i].v)) continue;
		fa[find(e2[i].u)] = find(e2[i].v);
		e[++mcnt] = e2[i];
	}
	m = mcnt; 
	
	bool xza = 1;
	
	for(int i = 1;i <= k;++ i){
		cin >> c[i][0];
		if(c[i][0]) xza = 0;
		for(int j = 1;j <= n;++ j){
			cin >> c[i][j];
		}
	}
	
	if((n <= 1000&&xza)||k <= 0){
		
		for(int i = 1;i <= n;++ i){
			for(int j = i+1;j <= n;++ j){
				int mnw = 1e10,wz = 0;
				for(int _ = 1;_ <= k;++ _){
					int w = c[_][i]+c[_][j];
					if(w < mnw){
						mnw = w;
						wz = _; 
					}
				}
				e[++m] = {i,j,mnw};
			}
		}
		
		for(int i = 1;i <= n;++ i) fa[i] = i;
		
		sort(e+1,e+1+m,cmp);
		int ans = 0,res = 0;
		for(int i = 1;i <= m&&res < n-1;++ i){
			if(find(e[i].u) == find(e[i].v)) continue;
			fa[find(e[i].u)] = find(e[i].v);
			ans += e[i].w;
			res++;
		}
		
		print(ans);
		return 0;
		
	}

	return 0;

}
