#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0)
constexpr int maxn = 1e5+3;
struct node{int a,b,c;}p[maxn];
int n;
int ans;
void dfs(int sum,int al,int bl,int cl,int pos){
	if(pos > n){
		ans = max(ans,sum);
		return;
	}
	if(al < n/2) dfs(sum+p[pos].a,al+1,bl,cl,pos+1);
	if(bl < n/2) dfs(sum+p[pos].b,al,bl+1,cl,pos+1);
	if(cl < n/2) dfs(sum+p[pos].c,al,bl,cl+1,pos+1);
}
bool cmp1(node x,node y){return x.a > y.a;}
bool cmp2(node x,node y){return x.a-x.b > y.a-y.b;}
int main(){
	IOS;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		ans = 0;
		cin >> n;
		bool flg = 1;
		for(int i = 1;i <= n;i++){
			cin >> p[i].a >> p[i].b >> p[i].c;
			if(p[i].b) flg = 0;
		}	
		if(n > 30){
			if(flg){
				sort(p+1,p+n+1,cmp1);
				for(int i = 1;i <= n/2;i++)
					ans += p[i].a;
			}else{
				sort(p+1,p+n+1,cmp2);
				for(int i = 1;i <= n/2;i++)
					ans += p[i].a;
				for(int i = n;i > n/2;i--)
					ans += p[i].b;
			}
		}else dfs(0,0,0,0,1);
		cout << ans << endl;
	}
	return 0;
}
