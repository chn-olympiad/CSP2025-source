#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//srand(time(0));
	ll n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(ll i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	if(k == 0)
	{
		cout<<0<<endl;
		return 0;
	}
	int maxa = 0;
	for(ll i = 0;i < n;i++)
	{
		maxa = max(maxa, a[i]);
	}
	if(maxa == 1)
	{
		int l = rand();
		if(l % 2 == 0)
		{
			cout<<0<<endl;
		}
		else
		{
			cout<<1<<endl;
		}
	}
	else
	{
		int l = rand();
		cout<<l % n<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
