#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n,sum=0,s[100005],a[100005];
    cin>>n;
    for(int i=1;i<=sum;i++)
    {
        cin>>s[i];
    }
    for(int i=1;i<=sum;i++)
    {
    	cin>>a[i];
    }
    if(sum<=2)
    {
        cout<<n;
	}
	else
	{
		cout<<sum;
    }
	cout<<""<<endl;
	return 0;
    fclose(stdin);
    fclose(stdout);
}

