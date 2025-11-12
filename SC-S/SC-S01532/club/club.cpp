#include<bits/stdc++.h>
using namespace std;
int T,n;
long long ans = 0;
struct node{
	int d1;
	int d2;
	int d3;
	int delt;
	int maxn;
}a[100005],a1[100005],a2[100005],a3[100005];
node init(node x){
	int tmp[4];
	tmp[1] = x.d1;
	tmp[2] = x.d2;
	tmp[3] = x.d3;
	sort(tmp+1,tmp+4);
	x.delt = tmp[3]-tmp[2];
	x.maxn = tmp[3];
	return x;
}
bool cmp(node x,node y){
	return x.delt < y.delt;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		ans = 0;
		int l1 = 0,l2 = 0,l3 = 0;
		cin >> n;
		for(int i = 1;i<=n;i++){
			cin >> a[i].d1 >> a[i].d2 >> a[i].d3;
			a[i] = init(a[i]);
		}
		for(int i = 1;i <= n;i++){
			if(a[i].maxn == a[i].d1){
				a1[++l1] = a[i];
			}
			else if(a[i].maxn == a[i].d2){
				a2[++l2] = a[i];
			}
			else if(a[i].maxn == a[i].d3){
				a3[++l3] = a[i];
			}
			ans+=a[i].maxn;
		}
		sort(a1+1,a1+l1+1,cmp);
		sort(a2+1,a2+l2+1,cmp);
		sort(a3+1,a3+l3+1,cmp);
		if(l1 > n/2){
			for(int i = 1;n/2+i <= l1;i++){
				ans -= a1[i].delt;
			}
		}
		else if(l2 > n/2){
			for(int i = 1;n/2+i <= l2;i++){
				ans -= a2[i].delt;
			}
		}
		else if(l3 > n/2){
			for(int i = 1;n/2+i <= l3;i++){
				ans -= a3[i].delt;
			}
		}
		cout << ans << endl;
	}
	return 0;
}