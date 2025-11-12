#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int index=0;
	char max='0';
	int count=0,ans=0;
	for(int i=0;i<s.length();i++)
		if(s[i]>='0'&&s[i]<='9')
			ans++;
	for(int i=0;i<ans;i++)
	{
		for(int j=0;j<s.length();j++)
		{
			if(s[j]>='0'&&s[j]<='9'&&s[j]>=max)    
			{
				max=s[j];
				index=j;
				count=1;
			}
		}
		cout << max;
		s[index]='a';
		if(count)
		{
			max='0';
			count=0;
		} 
		else
			break;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
