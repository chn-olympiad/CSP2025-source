#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int a[1000005];
//#Shang4Shan3Ruo6Shui4
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>s;
	int ans=0,cnt=0;
	for(int i = 0;s[i]!='\0';i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			cnt++;
			a[cnt]=(int)(s[i]-48);
			ans++;
		}
	}
	for(int i = 1;i <= ans;i++)
	{
		sort(a+1,a+ans+1);
	}
	for(int i = ans;i >= 1;i--)
	{
		cout <<a[i];
	}
	return 0;
}