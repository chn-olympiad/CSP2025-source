#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
string s;
int a[1000005];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout); 
	
	cin>>s;
	
	int l = s.size();
	int k = 1;
	for(int i = 0; i < l; i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			a[k++] = s[i] - '0';
		}
	}
	
	sort(a + 1,a + k);
	for(int i = k - 1; i >= 1; i--)
	{
		cout<<a[i];
	}
	
	return 0;
}
