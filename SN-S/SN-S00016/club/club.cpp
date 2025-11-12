#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t, n;
struct node{
	int x,y,z;
}a[N];

int cmp(node a, node b){
	if(a.x != b.x){
		return a.x > b.x;
	}
	else{
		if(a.y != b.y){
			return a.y > b.y;
		}
		else{
			return a.z > b.z;
		}
	}
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		bool f = 0, f1 = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			if(a[i].y != 0 || a[i].z != 0) f = 1;
		}
		sort(a+1,a+n+1,cmp);
		int k = n/2;
		if(f == 0){
			for(int i = 1; i <= k; i++){
				ans += a[i].x;
			}
		}
		
		cout << ans << "\n";
	}
	
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
