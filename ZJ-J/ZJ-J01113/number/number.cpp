#include<bits/stdc++.h>
using namespace std;
int box[100];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size(),i;
	for(i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			int a=s[i]-'0';
			box[a]++;//Ͱ 
		}
	}
	for(i=9;i>=0;i--)
	{
		while(box[i])
		{
			cout<<i;
			box[i]--;
		}
	}
	return 0;
}
