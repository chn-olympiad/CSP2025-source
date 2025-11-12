#include <iostream>
#include <algorithm>

struct Node{
	int a, b, c;
	int id;
};
Node p[200005];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	
	while(t--){
		int n;
		scanf("%d", &n);
		int na = 0, nb = 0, nc = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d%d%d", &p[i].a, &p[i].b, &p[i].c);
			if(p[i].a >= p[i].b and p[i].a >= p[i].c)
				na++, p[i].id = 1;
			else if(p[i].b >= p[i].a and p[i].b >= p[i].c)
				nb++, p[i].id = 2;
			else if(p[i].c >= p[i].b and p[i].c >= p[i].a)
				nc++, p[i].id = 3;
		}
		if(na > n / 2){
			for(int l = 1;l <= na - n / 2;l++){
				int maxx = -100005, maxi = 0, to = 0;
				for(int i = 1;i <= n;i++){
					if(p[i].id == 1){
						int x = std::max(p[i].b, p[i].c) - p[i].a;
						if(x > maxx){
							maxx = x;
							maxi = i;
							to = ((p[i].b > p[i].c) ? 2 : 3);
						}
					}
				}
				p[maxi].id = to;			
			}
		}
		if(nb > n / 2){
			for(int l = 1;l <= nb - n / 2;l++){
				int maxx = -100005, maxi = 0, to = 0;
				for(int i = 1;i <= n;i++){
					if(p[i].id == 2){
						int x = std::max(p[i].a, p[i].c) - p[i].b;
						if(x > maxx){
							maxx = x;
							maxi = i;
							to = ((p[i].a > p[i].c) ? 1 : 3);
						}
					}
				}
				p[maxi].id = to;			
			}
		}
		if(nc > n / 2){
			for(int l = 1;l <= nc - n / 2;l++){
				int maxx = -100005, maxi = 0, to = 0;
				for(int i = 1;i <= n;i++){
					if(p[i].id == 3){
						int x = std::max(p[i].a, p[i].b) - p[i].c;
						if(x > maxx){
							maxx = x;
							maxi = i;
							to = ((p[i].a > p[i].b) ? 1 : 2);
						}
					}
				}
				p[maxi].id = to;			
			}
		}
		int ans = 0;
		for(int i = 1;i <= n;i++){
			if(p[i].id == 1)
				ans += p[i].a;
			if(p[i].id == 2)
				ans += p[i].b;
			if(p[i].id == 3)
				ans += p[i].c;
		}
		printf("%d\n", ans);
	}
	return 0;
}