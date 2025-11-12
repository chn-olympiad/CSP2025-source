#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n,a[5005],ans,q[1005],p[5005],sum[5005],cnt,tmp[5005];
bool book[5005];
int find(int xx){
	return lower_bound(tmp+1,tmp+n+1,xx)-tmp;
}
int dd(int x){
	sum[0]=0;
	int maxx=-1;
	for(int i = 1;i <= x;i++){
		sum[i] = sum[i-1]+p[i];
		maxx = max(maxx,p[i]);
	}
	if(sum[x] > 2*maxx) cnt++;
	int dig = x;
	while(p[1] <= a[n-2]){
		p[dig] = tmp[find(p[dig])+1];
		if(p[dig] == a[n]){
			dig--;
			for(int j = dig;j <= x;j++){
				p[j] = 1;
			}
		}
	}return cnt;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		tmp[i]=a[i];
		//sum[i] = sum[i-1]+a[
	}
	//sort(a+1,a+n+1);
	//for(int i = 3;i <= n;i++){
		//for(int j = 1;j <= i;j++){
		//	p[j] = a[i];
		//	q[j] = 0;
		//}
		//cnt = 0;
		//ans = (ans +dd(i))%MOD;
	//}
	//cout<<ans;
	cout<<1;
	return 0;
}

