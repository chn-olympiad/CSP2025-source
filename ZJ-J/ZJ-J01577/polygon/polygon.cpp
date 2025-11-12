#include <bits/stdc++.h>
using namespace std;

int n;
int a[5005]; 
const int M = 998244353;
int ans = 0;


int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	if(n < 3) cout << 0;
	else if(n == 3)
	{
		if(a[1] + a[2] + a[3] > 2 * max(a[1],max(a[2],a[3])))
		{
			cout << 1;
		}
		else cout << 0;
	}
	
	return 0;
}
