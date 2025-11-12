#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int a[20];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int sl=0;
	sl=strlen(s);

    for(int i=0;i<sl;i++)
    {
     if(s[i]-'0'<10)
     {
     	a[s[i]-'0']++;
	 }
	}
    for(int i=9;i>=0;)
    {
    	if(a[i]!=0)
    	{
    		cout<<i;
    		a[i]--;
		}
		else i--;
	}
	return 0;
}