#include <bits/stdc++.h>
using namespace std;
int t;
int maxn = -1;
int mmax;
int a_index,b_index,c_index;  
struct du{
	int a,b,c;
}a[10001];
int n;
int ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i = 1;i <= t;i++){    
		cin >> n;
		for(int j = 1;j <= n;j++){        
			cin >> a[j].a >> a[j].b >> a[j].c;
		}
		for(int z = 1;z <= n;z++){		
			mmax = max(max(a[z].a,a[z].b),a[z].c);
			ans += mmax;
		}
		cout << ans << endl;
		ans = 0;	
	}
	return 0;
}
