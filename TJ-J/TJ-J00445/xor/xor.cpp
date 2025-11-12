#include <iostream>
using namespace std;

int a[5500001];
bool fl[5500001]={};
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,num,cnt=0,flag=1;
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		num=0;
		for(int j=i;j<=n;j++)
		{
			if(fl[j])
			{
				num=0;
				flag=j;
				continue;
			}
			num=num|a[j];
			if(num==k)
			{
				for(int k=flag;k<=j;k++) fl[k]=true;
				num=0;
				flag=j;
				cnt++;
			}
		}
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
