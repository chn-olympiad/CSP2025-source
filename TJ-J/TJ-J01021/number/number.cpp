#include<iostream>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int b[1004];
    int bn=0;
    
    int n=a.size();

    for(int i=0;i<=n-1;i++)
    {
    	if(a[i]>='0'&&a[i]<='9')
    	{
    		b[bn]=a[i]-'0';
    		bn++;
		}
	}
	for(int i=0;i<=bn-1;i++)
	{
		int maxn=0;
		int gai;
		for(int j=0;j<=bn-1;j++)
		{
			if(b[j]>maxn)
			{
				maxn=b[j];
				gai=j;
			}
			
		}
		b[gai]=0;
		cout<<maxn;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


































