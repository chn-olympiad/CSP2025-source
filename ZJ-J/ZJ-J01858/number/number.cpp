#include<bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	int x=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			x++;
			a[s[i]-'0']++;
		}
	}
	if(x==a[0])cout<<0;
	else 
	for(int i=9;i>=0;i--)
		for(int j=1;j<=a[i];j++)cout<<i;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//#Shang4Shan3Ruo6Shui4
