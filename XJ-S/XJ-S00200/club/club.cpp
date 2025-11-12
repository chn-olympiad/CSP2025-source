#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int n,T,m1,m2,m3,m;
long long ans,sum;
int a1[N],a2[N],a3[N];
void dfs(int x){
	if (x == n+1){
		ans = max(sum,ans);
		return;
	}
	if (m1 < m){
		sum += a1[x];m1++;
		dfs(x+1);
		sum -= a1[x];m1--;
	}
	if (m2 < m){
		sum += a2[x];m2++;
		dfs(x+1);
		sum -= a2[x];m2--;
	}
	if (m3 < m){
		sum += a3[x];m3++;
		dfs(x+1);
		sum -= a3[x];m3--;
	}
	
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n;
		m = n/2;
		for (int i = 1;i <= n;i++){
			cin >> a1[i] >> a2[i] >> a3[i];
		}
		dfs(1);
		cout << ans << endl;
		ans = 0;
	}
	return 0;
}
