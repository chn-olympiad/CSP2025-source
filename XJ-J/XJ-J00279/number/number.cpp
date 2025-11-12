#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
char a[N];
long long len,num[N],cnt;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>a;
    len=strlen(a);
    for(int i=0;i<=len;i++)
    {
    	if(isdigit(a[i]))
    	{
    		if(a[i]=='0')
    		{
    			num[++cnt]=0;
			}
			else if(a[i]=='1')
    		{
    			num[++cnt]=1;
			}
			else if(a[i]=='2')
    		{
    			num[++cnt]=2;
			}
			else if(a[i]=='3')
    		{
    			num[++cnt]=3;
			}
			else if(a[i]=='4')
    		{
    			num[++cnt]=4;
			}
			else if(a[i]=='5')
    		{
    			num[++cnt]=5;
			}
			else if(a[i]=='6')
    		{
    			num[++cnt]=6;
			}
			else if(a[i]=='7')
    		{
    			num[++cnt]=7;
			}
			else if(a[i]=='8')
    		{
    			num[++cnt]=8;
			}
			else if(a[i]=='9')
    		{
    			num[++cnt]=9;
			}
		}
	}
	sort(num+1,num+1+cnt);
	reverse(num+1,num+1+cnt);
	for(int i=1;i<=cnt;i++)
	{
		cout<<num[i];
	}
    return 0;
}
