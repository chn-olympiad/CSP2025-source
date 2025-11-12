#include <bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int m,id;
}a[100010],b[100010],c[100010];
bool cmp(node x, node y){
	if(x.m != y.m) return x.m > y.m;
	else return x.id < y.id;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1; i <= n; i++){
			int max1 = 0;
			cin >> a[i].m >> b[i].m >> c[i].m;
			a[i].id = i;
			b[i].id = i;
			c[i].id = i;
			
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		if(c[1].m == 0 && b[1].m == 0){
			int ans1 = 0;
			for(int i = 1; i <= n/2;i++){
				ans1+=a[i].m;
			}
			cout << ans1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
