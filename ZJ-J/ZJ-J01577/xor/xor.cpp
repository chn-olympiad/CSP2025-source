#include <bits/stdc++.h>
using namespace std;
int n;
int a[500005],k;

bool check(int x)
{
	int num = -1;
	int sum = 0;
	for(int i = 1;i <= n;i++)
	{
		if(num == -1) num = a[i];
		else
		{
			num ^= a[i];	
		}
		
		if(num == k)
		{
			sum++;
			num = -1;
		}
		
	}
	
	if(sum >= x) return 1;
	else return 0;
	
}

int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	scanf("%d",&n);
	scanf("%d",&k);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	int l = 0,r = n + 1,ans;
	
	while(l <= r)
	{
		int mid = (l + r) / 2;
		
		if(check(mid))
		{
			l = mid + 1;
			ans = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	
	cout << ans;
	
	return 0;
}
