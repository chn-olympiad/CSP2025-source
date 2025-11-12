#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e4+10;
const int MOD = 998244353;
i64 n;
i64 Arr[N];
i64 ans = 0;
i64 dfs(i64 MaxNum,i64 SumNum,i64 BeginPoint,i64 Select,i64 Need){
	if(Select == Need){
		if(SumNum > MaxNum * 2){
			return 1;
		}
		return 0;
	}
	i64 ans = 0;
	for(int i=BeginPoint;i<=n;i++){
		if((n-i) < (Need-Select-1)) break;
		ans += dfs(max(MaxNum,Arr[i]),SumNum+Arr[i],i+1,Select+1,Need);
		ans %= MOD;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> Arr[i];
	}
	for(int i=3;i<=n;i++){
		ans += dfs(0,0,1,0,i);
	}
	cout << ans ;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}