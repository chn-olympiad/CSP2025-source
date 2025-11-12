#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
char a[1000005];
int b[100005]={0};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i=1,cnt=1;
	while(cin>>a[i])
	{
		if(a[i]>='0'&&a[i]<'a')
		{
			b[cnt]=a[i]-'0';
			cnt++;
		}
		i++;
    }
	sort(b+1,b+cnt+1,cmp);
    for(i=1;i<=cnt-1;i++)
    {
    	cout<<b[i];
	}
	return 0;
 } 
