#include<bits/stdc++.h>
using namespace std;

int a,sa[15];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0; i<= sizeof(s);i++)
		if(s[i] == '0')
		{
			sa[0]++;
		}
		else if(s[i]=='1')
		{
			sa[1]++;
		}
		else if(s[i]=='2')
		{
			sa[2]++;
		}
		else if(s[i]=='3')
		{
			sa[3]++;
		}
		else if(s[i]=='4')
		{
			sa[4]++;
		}
		else if(s[i]=='5')
		{
			sa[5]++;
		}
		else if(s[i]=='6')
		{
			sa[6]++;
		}
		else if(s[i]=='7')
		{
			sa[7]++;
		}
		else if(s[i]=='8')
		{
			sa[8]++;
		}
		else if(s[i]=='9')
		{
			sa[9]++;
		}
	for(int j = 9; j>= 0;j--)
	{
		while(sa[j]>0)
		{
			cout << j;
			sa[j]--;
		}
	}
	return 0;	
} 
