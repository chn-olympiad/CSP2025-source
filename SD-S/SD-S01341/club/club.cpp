#include<bits/stdc++.h>
#include<cstdio>
#define ll long long
using namespace std;
const int N = 100005;
struct Node{
	int a,b,c;
	int Cost_ab;
	int Cost_ac;
	int Cost_bc;
	int now;
}t[N];
int T,n;
ll ans;
bool cmp1(Node x,Node y){
	int x_Cost = min(x.Cost_ab,x.Cost_ac);
	int y_Cost = min(y.Cost_ab,y.Cost_ac);
	if(x_Cost == y_Cost)
		return x.a < y.a;
	return x_Cost > y_Cost;
}
bool cmp2(Node x,Node y){
	return x.Cost_bc > y.Cost_bc;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans = 0;
		scanf("%d",&n);
		int cnt1 = n;
		int cnt2 = 0;
		int cnt3 = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d%d%d",&t[i].a,&t[i].b,&t[i].c);
			t[i].Cost_ab = t[i].b-t[i].a;
			t[i].Cost_ac = t[i].c-t[i].a;
			t[i].Cost_bc = t[i].c-t[i].b;
			t[i].now = 1;
		}
		//更优的去B/C 
		for(int i = 1;i <= n;i++){
			if(t[i].Cost_ab >= 0 || t[i].Cost_ac >= 0){
				t[i].now = 2;
				cnt1--;
				cnt2++;
			}
		}
		ans = 0;
		//如果更优去了还不行 
		if(cnt1 > n/2){
			sort(t+1,t+n+1,cmp1);
			for(int i = 1;i <= n;i++){
				if(cnt1 <= n/2)
					break;
				if(t[i].now != 1)
					continue;
				t[i].now = 2;
				cnt1--;
				cnt2++;
			}
		}	
		//处理B/C,更优互去
		sort(t+1,t+n+1,cmp2);
		for(int i = 1;i <= n;i++){
			if(t[i].now == 2 && (cnt2 > n/2 || (cnt3 < n/2 && t[i].Cost_bc>0))){
				cnt2--;
				cnt3++;
				t[i].now = 3;
			}
		}
		ans = 0;
		for(int i = 1;i <= n;i++){
			if(t[i].now == 1)
				ans += t[i].a;
			if(t[i].now == 2)
				ans += t[i].b; 
			if(t[i].now == 3)
				ans += t[i].c;
		}
		printf("%d\n",ans);
	}
	return 0;
}
