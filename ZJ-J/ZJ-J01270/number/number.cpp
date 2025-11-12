#include<bits/stdc++.h>
using namespace std;
int l[1000005],cnt;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	for(int i = 0;i < s.size();i++)
	{
		if(s[i] >= '0'&&s[i] <= '9')
		{
			cnt++;
			l[cnt] = s[i] - '0';
		}
	}
	sort(l+1,l+cnt+1);
	for(int i = cnt;i >= 1;i--)
	{
		printf("%d",l[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
