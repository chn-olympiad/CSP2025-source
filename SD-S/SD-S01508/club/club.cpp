#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct no{
	int x,y,z;
}t[1000005];
bool cmp(no a , no b){
	if(a.x == b.x){
		return a.y > b.y;
	}
	return a.x > b.x;
}
int a,b,c;
int as;
void dfs(int u , int ma){
	if(u >= n){
		as = max(ma , as);
	}
	if(a < n / 2){
		a++;
		dfs(u + 1 , ma + t[u + 1].x);
		a--;
	}
	if(b < n / 2){
		b++;
		dfs(u + 1 , ma + t[u + 1].y);
		b--;
	}
	if(c < n / 2){
		c++;
		dfs(u + 1 , ma + t[u + 1].z);
		c--;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	int q;
	cin>>q;
	while(q--){
		memset(t , 0 , sizeof(t));
		a = 0;
		b = 0;
		c = 0;
		as = 0;
		cin>>n;
		for(int i = 1;i <= n;i++){
			cin>>t[i].x>>t[i].y>>t[i].z;
			if(t[i].y != 0){
					f1 = 1;
				}
				if(t[i].z != 0){
					f2 = 1;
				}
			}
		}
		if(f1 == 0 && f2 == 0){
			sort(t + 1 , t + 1 + n , cmp);
			for(int i = 1;i <= n / 2;i++){
				as += t[i].x;
			}
			cout<<as;
			continue;
		}
		dfs(0 , 0);
		cout<<as<<"\n";
	}
	return 0;
}
