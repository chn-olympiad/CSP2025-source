#include <bits/stdc++.h>
using namespace std;
struct s{
	int j1;
	int j2;
	int j3;
	int p;
	int maxn;
}a[100020];
bool cmp(s x,s y){
	return x.p<y.p;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	int n;
	while(t--){
		cin >> n;
		memset(a,0,sizeof(a));
		int sum = 0;
		for(int i = 1;i<=n;i++){
			cin >> a[i].j1 >> a[i].j2 >> a[i].j3;	
			a[i].maxn = max(a[i].j1,max(a[i].j2,a[i].j3));
			sum +=a[i].maxn ;
			a[i].p = a[i].j1 + a[i].j2 + a[i].j3;
		}
		cout << sum <<endl;
	}
	
	return 0;
}  
