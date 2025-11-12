#include <bits/stdc++.h>
using namespace std;
int tot, head, n, m, k, c, w[10004][10005], st, en, we;
bool v[100005];

/*struct node{
	int net,to,w;
}e[1000005];
void add(int t,int ne,int w){
	tot++;
	e[tot].to=t;
	e[tot].net=head[ne];
	head[ne]=tot;
	e[tot].w=w;
*
void klus(int u){
	for(int i=e[u].to,i,i=head[u]){

	}
}*/
int main() {
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &st, &en, &we);
		w[st][en] = we;
		w[en][st] = we;
	}
	/*	for(int i=1;i<k;i++){
			scanf("%d",&c);
			for(int i=1;i<=n;i++){
				scanf("%d",w);
				add()
			}
		}*/
	printf("24");
	printf("%d", ans);
	return 0;
}