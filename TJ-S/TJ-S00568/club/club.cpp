#include<bits/stdc++.h>
using namespace std;
int n,maxn,ans,a1,a2,a3,t;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1;i <= n;++i)
		{
			cin >> a1 >> a2 >>a3;
			maxn = max(a1,max(a2,a3));
			ans += maxn;
		}	
		cout << ans <<"\n";
	}
	
}
                                                   
