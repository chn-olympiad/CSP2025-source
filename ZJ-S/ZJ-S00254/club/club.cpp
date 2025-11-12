

#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

#define MAXN 100099
#define INF 1000000

int cnt[MAXN];
int ans = 0;
int mini = INF;
int pa = 0;
int pb = 0;
int pc = 0;
int maxi = 0;

struct dpt{
	int val;
	int p;
	int id;
};

dpt a[MAXN];
dpt b[MAXN];
dpt c[MAXN];

bool cmp(dpt x,dpt y){
	return x.p > y.p;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int n = 0;
	int t = 0;
	int m = 0;
	cin >> t;
	
	while(t--){
		ans = 0;
		pa = 1;
		pb = 1;
		pc = 1;
		memset(cnt,0,sizeof(cnt));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		cin >> n;
		m = n/2;
		
		for(int i=1;i<=n;i++){
			mini = INF;
			cin >> a[i].val >> b[i].val >> c[i].val;
			a[i].id = i;
			b[i].id = i;
			c[i].id = i;
			mini = min(mini,a[i].val);
			mini = min(mini,b[i].val);
			mini = min(mini,c[i].val);
			a[i].p = a[i].val - mini;
			b[i].p = b[i].val - mini;
			c[i].p = c[i].val - mini;
		}
		
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		
		for(int i = 1;i<=3*n;i++){
			while(cnt[a[pa].id] && pa <=n){
				pa++;
			}
			while(cnt[b[pb].id] && pb <=n){
				pb++;
			}
			while(cnt[c[pc].id] && pc <=n){
				pc++;
			}
			
			if(a[pa].val >= b[pb].val && a[pa].val >= c[pc].val){
				maxi = a[pa].val;
				cnt[a[pa].id] = 1;
			}else if(b[pb].val >= a[pa].val && b[pb].val >= c[pc].val){
				maxi = b[pb].val;
				cnt[b[pb].id] = 1;
			}else{
				maxi = c[pc].val;
				cnt[c[pc].id] = 1;
			}
			
			ans += maxi;
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}
