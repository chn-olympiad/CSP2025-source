//陕西省 西安市 灞桥区 滨河学校 陈昱冰 
#include <iostream>
#define ll long long
using namespace std;
int n,a[5005],num=0,sum=0,maxn=0;
signed main()
{
	//freopen("polygon.in","r",stdin)
	//freopen("polygon.out","w",stdout)
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for (int i=3;i<=n;i++)
	{
		for (int j=1;j<=i;j++)
		{
			sum+=a[j];
			maxn=max(a[j],a[j+1]);
			if (sum>2*maxn)
			{
				num++;
			}
		}
	}
	cout << num;
	return 0;
}
