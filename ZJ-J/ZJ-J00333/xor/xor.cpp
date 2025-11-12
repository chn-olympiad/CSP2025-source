#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[1001]={},c=0;
	int s[1001]={},t[1001]={};
    cin>>n>>k;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
        a[i]=a[i-1] xor a[i];
    }
    for(int i = 1;i<=n;i++)
    {
    	for(int j = 1;j<=n-i+1;j++)
    	{
    		if(a[j-1] xor a[j+i-1]==k&&t[j+i-1]-t[j-1]==1)
    		{
    			c++;
    			s[j]++;
    			s[j+i-1]++;
			}
			t[j]=t[j-1]+s[j];
		}
	}
	cout<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
