#include<bits/stdc++.h>
using namespace std;
int main(){
	int s;
	int ans[30];
	int a[30];
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i <= s;i++){
		if(a[i] >= '0' && a[i] <= '9')
		{
			s = a[i];
		}
		ans[i] = max(a[i],a[i+1]);
		ans[i+ 1] = max (a[i+1],a[i+2]);

	}
	cout << ans;
	
}
