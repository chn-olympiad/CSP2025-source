#include<bits/stdc++.h>
using namespace std;
string s;
int len,buc[10]={0},cnt=0,p=9;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++)
	{
		if(int(s[i])-48 >=0 && int(s[i])-48<=9)
		{
			buc[int(s[i])-48]++;
			cnt++;
		}
	}
	while(cnt)
	{
		if(buc[p]--)
		{
			printf("%d",p);
			cnt--;
		}
		else p--;
	}
	return 0;
}