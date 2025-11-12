#include<bits/stdc++.h>
using namespace std;
int num[16];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;s=" "+s;
	for(int i=1;i<=s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			num[(int)s[i]-'0']++;
	for(int i=9;i>=0;i--)
		while(num[i]--)
			cout<<i;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
