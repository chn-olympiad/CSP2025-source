#include<bits/stdc++.h>
using namespace std;
int b[15];
bool cmp (int x,int y)
{
	return x > y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a; 
	cin >> a;
	for(int i = 0; i < a.size(); i++ )
	{
		if(a[i] >= '0' && a[i] <= '9')
		{
			b[a[i]-'0']++;
			
		}
	}
	for( int i = 9;i >= 0;i--)
	{
		if( b[i] != 0)
		{
			for(int j = 1; j <= b[i];j++)
			cout << i;
		}
	}
	
	return 0;
 } 
