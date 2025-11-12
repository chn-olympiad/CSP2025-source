#include<bits/stdc++.h>
using namespace std;
int n, T, a[100005], b[100005], c[100005];
bool ta=true,tb=true;
long long dfs(int num, int sum1, int sum2, int sum3, long long sum) {
	num++;
	if(num>n)return sum;
	long long Sum=sum;
	if(a[num]>=b[num]||a[num]>=c[num])if(sum1<n/2)Sum=max(Sum, dfs(num, sum1+1, sum2, sum3, sum+a[num]));
	if(b[num]>=a[num]||b[num]>=c[num])if(sum2<n/2)Sum=max(Sum, dfs(num, sum1, sum2+1, sum3, sum+b[num]));
	if(c[num]>=a[num]||c[num]>=b[num])if(sum3<n/2)Sum=max(Sum, dfs(num, sum1, sum2, sum3+1, sum+c[num]));
	return Sum;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--) {
		cin >> n;
		if(n <= 30) {
			for(int i = 1; i <= n; i++)
				cin >> a[i] >> b[i] >> c[i];
			long long ans = dfs(0,0,0,0,0);
			cout << ans << endl;
		}
		else {
			for(int i = 1; i <= n; i++) {
				cin >> a[i] >> b[i] >> c[i];
				if(b[i]!=0)ta=false;
				if(c[i]!=0)tb=ta=false;
			}
			if(ta) {
				sort(a + 1, a+1 + n);			
				long long ans=0;
				for(int i = 1; i <= n/2; i++)
					ans += a[i];
				cout << ans;
			}
		}
	}
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
