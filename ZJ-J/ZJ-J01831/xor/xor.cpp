#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],num,dai;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	vector<int>xin,jum;
	vector<int>::iterator it;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==k)
		{
			num++;
			xin.clear();
			jum.clear();
		}
		else
		{
			jum.push_back(a[i]);
			for(it=xin.begin();it!=xin.end();it++)
			{
				dai=(*it)^a[i];
				jum.push_back(dai);
				if(dai==k)
				{
					num++;
					xin.clear();
					xin=jum;
					jum.clear();
					break;
				}
			}
			xin.clear();
			xin=jum;
			jum.clear();
		}
	}
	printf("%d",num);
	return 0;
}