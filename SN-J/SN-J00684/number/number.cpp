//汝艺-SN-J00684-临渭示范学校
#include <bits/stdc++.h>
using namespace std;
long long S,i,x[100005],a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>S;
	while(S!=0)
	{
		x[i]=S%10;
		a[x[i]]++;
		S=S/10;
		i++;
	}
	for(int k=9;k>=0;k--)
	{
		for(int c=1;c<=a[k];c++)
		{
			cout<<k;
		}
	}
	return 0;
}
