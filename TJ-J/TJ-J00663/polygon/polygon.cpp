#include <bits/stdc++.h>
using namespace std;
int n,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	if(n == 3){
		sort(a + 1,a + 1 + n);//四道题我有三道全用了sort。
		if(a[1] + a[2] > a[3]) cout << 1;
		else cout << 0; 
	}
	return 0;
}//这咋出的题啊难度跨越那么大 
