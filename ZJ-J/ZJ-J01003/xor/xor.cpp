#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 5e5+10;
i64 n,k;
i64 Arr[N];
i64 XorArr[N];
i64 XorMem[N];
bool book[N];
i64 dfs(i64 BeginPoint){
	//cout<<BeginPoint<<endl;
	i64 ans = 0;
	for(int i=BeginPoint;i<=n;i++){
		for(int j=n;j>=i;j--){
			if((XorArr[j] xor XorArr[i-1]) == k){
				if(!book[j+1]){
					book[j+1] = true;
					XorMem[j+1] = dfs(j+1)+1;
				}
				ans = max(ans,XorMem[j+1]);
			}
		}
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> Arr[i];
	}
	XorArr[1] = Arr[1];
	for(int i=2;i<=n;i++){
		XorArr[i] = XorArr[i-1] xor Arr[i];
	}
	cout << dfs(1);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}