//考号：CN-J01099  姓名：陈墨涵   学校：西安高新一中沣东中学初中校区 
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long a[100010];
	int n=0;
	cin>>s;
	
	for (int i=0;i<=s.length();i++)
	{
        if (s[i]>='0'&&s[i]<='9')
		{
			a[n]=s[i]-'0';
			n++;
		}
	}
   for (int i=0;i<=n-2;i++)
   {
   	    for (int j=i+1;j<=n-1;j++)
   	    {
   	   	    if(a[i]<=a[j]) 
   	   	    {
   	   	        int t=a[i];
				a[i]=a[j];
				a[j]=t;    	
			}
	    }
   }
   for (int i=0;i<=n-1;i++)
   {
   	    cout<<a[i];
   }
	return 0;
}
