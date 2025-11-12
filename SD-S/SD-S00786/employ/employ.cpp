/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[501];
int c[501];
int a[501];
int ans;
string o;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>o;
	int i;
	for(i=0;i<n;i++)
		s[i+1] = o[i]-'0';
	for(i=1;i<=n;i++)
		cin>>c[i],a[i] = i;
	do
	{
		int fail = 0;
		int cnt = 0;
		for(i=1;i<=n;i++)
		{
			if(fail>=c[a[i]])
			{
				fail++;
				continue;
			}
			if(!s[i])
			{
				fail++;
				continue;
			}
			cnt++;
		}
//		cout<<cnt<<endl;
		if(cnt>=m)
		{
			ans++;
//			for(i=1;i<=n;i++)
//				cout<<a[i]<<' ';
//			cout<<endl;
		}
	}while(next_permutation(a+1,a+1+n));
	cout<<ans<<endl;
	return 0;
}
