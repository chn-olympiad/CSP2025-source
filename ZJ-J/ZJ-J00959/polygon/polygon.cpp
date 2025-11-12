#include<bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n;
int a[10005],sum[10005];
long long f[5050];
long long ans;
long long calc(int x){
	long long res = 1;
	for(int i = 2;i <= x;i++) res = (res*2+1)%p;
	return (res-x)%p;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++) sum[i] = sum[i-1]+a[i];
	sort(a+1,a+n+1);
	if(max(a[1],max(a[2],a[3]))*2 < a[1]+a[2]+a[3]) ans = 1;
	for(int T = 4;T <= n;T++){
		int m = a[T];
		memset(f,0,sizeof(f));
		f[a[1]]++;
		f[a[2]]++;
		if(a[1]+a[2] <= m) f[a[1]+a[2]]++;
		for(int i = 3;i < T;i++){
			for(int j = m;j >= a[i];j--){
				if(f[j-a[i]]) f[j]= (f[j]+f[j-a[i]])%p;
			}
		}
		long long num = 0;
		for(int i = 0;i <= m;i++) num += f[i];
		num-=2;
		//cout << num << endl;
		ans = ((ans+calc(T-1))%p-num)%p;
	}
	cout << ans;
}
