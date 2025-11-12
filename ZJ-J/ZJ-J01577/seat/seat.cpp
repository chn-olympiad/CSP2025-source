#include <bits/stdc++.h>
using namespace std;
int n,m;

int a[105];

int main(){
		
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
		
	cin >> n >> m;
	
	for(int i = 1;i <= n * m;i++)
	{
		cin >> a[i];
	}
	
	int key = a[1];
	int pai = 1;

	for(int i = 1;i <= n * m;i++) 
	{
		if(a[i] > key) pai++;
	}
	
	int ans;
	if(pai % n == 0)
	{
		ans = pai / n;
	}
	else ans = pai / n + 1;
	
	cout << ans << "\n";
	
	if(ans % 2 == 1)
	{
		if(pai % n == 0)
		{
			cout << n;
		}
		else cout << pai % n;
	}
	else
	{
		if(pai % n == 0)
		{
			cout << 1;
			
		}
		else
		{
			cout << n + 1 - pai % n;
		}
	}
	return 0;
}
