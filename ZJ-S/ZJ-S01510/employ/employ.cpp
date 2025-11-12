#include<bits/stdc++.h>
using namespace std;
long long n,m;
string a;
long long c[7788];
long long numm  = 0;
long long res = 1;
int main()
{
	//HAVVK
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> a;
	for(long long i = 0;i<n;i++)
	{
		cin >> c[i];
		if(c[i]!=0)
		{
			numm++;
		}
	}
	for(long long i = numm;i>=1;i--)
	{
		res*=i;
		res%=998244353;
	}
	cout << res;
	//shijiexiangzuo hafukexiangyou tiankongshuyuhafuke!         HAVVK
	return 0;
}
