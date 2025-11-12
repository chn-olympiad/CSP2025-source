#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[10]={0};
	for(long long i=0;i<s.size();i++)
	{
		if(s[i]+'0'>=96 && s[i]+'0'<=105)
		{
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(long long j=a[i];j>0;j--)
		{
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}

