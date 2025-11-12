#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int xx = 1e5+10;
ll dp[xx][5],ans;
int l[5],p[xx][5];
int n,x,y,z;
int q;
struct node{
	int to,id,w;
}e[xx*3];
int cnt;
bool is[xx];
void made(int id,int w,int to){
	e[++cnt].id = id;
	e[cnt].w = w;
	e[cnt].to = to;
}
bool cmp(node a,node b){
	return a.w > b.w;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> q;
	while(q--){
		ans = 0;
		memset(l,0,sizeof(l));
		memset(e,0,sizeof(e));
		memset(p,0,sizeof(0));
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> p[i][1] >> p[i][2] >> p[i][3];
			made(i,p[i][1],1);
			made(i,p[i][2],2);
			made(i,p[i][3],3);
		}
		sort(e+1,e+cnt+1,cmp);
		for(int i=1;i<=cnt;i++){
			if(!is[e[i].id]){
				is[e[i].id] = 1;
				if(l[e[i].to] < (n/2)){
					l[e[i].to]++;
					ans += e[i].w;
				}
			}
		}
		cout << ans << "\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
