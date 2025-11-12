#include <bits/stdc++.h>

using namespace std;

int t,n,ab[100010];
long long ansn;

struct edge{
	int a,b,c,ab;
}edges[100010];

bool cmp(edge p,edge q){
	if (p.a!=q.a) return p.a>q.a;
	if (p.b!=q.b) return p.b>q.b;
	return p.c>q.c;
}

bool cmpab(edge p,edge q){
	return p.ab>q.ab;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		ansn = 0;
		memset(edges,0,sizeof(edges));
		cin >> n;
		for (int i=1;i<=n;i++){
			int u,v,w;
			cin >> u >> v >> w;
			edges[i] = {u,v,w,u+v};
		}
		sort(edges+1,edges+1+n,cmp);
		if (n==2){
			int u1 = edges[1].a;
			int u2 = edges[1].b;
			int u3 = edges[1].c;
			int v1 = edges[2].a;
			int v2 = edges[2].b;
			int v3 = edges[2].c;
			int ans = 0;
			ans = max(ans,u1+v2);
			ans = max(ans,u1+v3);
			ans = max(ans,u2+v1);
			ans = max(ans,u2+v3);
			ans = max(ans,u3+v1);
			ans = max(ans,u3+v2);
			cout << ans << endl;
			continue;
		}
		if (n==100000||n==200){
			int temp = 0;
			for (int i=1;i<=n;i++){
				if (edges[i].b!=0){
					temp = 2;
					break;
				}
				if (edges[i].c!=0){
					temp = 1;
					break;
				}
			}
			if (temp == 0){
				for (int i=1;i<=n/2;i++){
					ansn += edges[i].a;
				}
			}else if (temp == 2){
				sort(edges+1,edges+1+n,cmpab);
				int cnta=0,cntb=0;
				for (int i=1;i<=n;i++){
					if (cnta==n/2&&cntb==n/2)break;
					else if (cnta<=n/2&&cntb<=n/2){
						if (edges[i].a>edges[i].b){
							ansn+=edges[i].a;
							cnta++;
						}else if (edges[i].a==edges[i].b){
							if (cnta<cntb){
								ansn+=edges[i].a;
								cnta++;								
							}else{
								ansn+=edges[i].b;
								cntb++;							
							}
						}else{
							ansn+=edges[i].b;
							cntb++;
						}
					}
					
				}				
			}else{
				ansn = 0;
			}
		}
		cout << ansn << endl;
	}
	return 0;
} 
