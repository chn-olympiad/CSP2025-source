#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int k=0;
	long long int len=s.size(); 
	for(int i=0;i<=len-1;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			k++;
			cnt[k]=s[i]-'0';
		}
	}
	sort(cnt+1,cnt+k+1);
	for(int i=k;i>=1;i--)
	{
		cout<<cnt[i];
	}
	return 0;
}
