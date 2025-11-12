#include<bits/stdc++.h>
#include<string>
#include<algorithm>
using namespace std;
int a[1000005],b[1000005],num;
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	if(s[0] == 5) cout << 5;
	else
	{
		int j = 1,lens = 0;
		for(int i = 0;;i++)
		{
			if((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z'))
			{
				lens++;
			}
			else break;
		} 
		for(int i = 0;i < lens;i++)
		{
			if(s[i] >= '0' && s[i] <= '9')
			{
				a[j] = s[i];
				j++;
			}
		}
		for(int i = 1;i < lens;i++)
		{
			if((a[i] - 48) >= 0)
			{
				a[i] = a[i] - 48;
				num++;
	
			}
			else break;
		}
	
		int k = 1;
		sort(a + 1,a + lens + 1);
		for(int i = lens ;i >= 0;i--)
		{
			if((a[i] >= 0) && (k <= num)) 
			{
				cout  << a[i] < " ";
				k++;
			}
		}
		return 0;
	}		
	}
