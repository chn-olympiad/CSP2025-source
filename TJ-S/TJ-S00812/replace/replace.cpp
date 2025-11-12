#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[300000],b[300000];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q ;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] >> b[i] ;
	}
	while(q)
	{
		q--;
		string a1,a2;
		int ans=0; 
		cin >> a1 >> a2 ;
		for(int i=1;i<=n;i++)
		{
			if(a1==a[i]&&a2==b[i])
			{
				ans++;
			}
		}
		cout << ans << endl ;
	} 
	return 0;
}
