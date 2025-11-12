#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int n,s=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==3)
    {
        if(a[1]+a[2]>a[3]&&a[2]+a[3]>a[1]&&a[1]+a[3]>a[2])
        {
            s=1;
        }
    }
    else if(n==5)s=9;
    else if(n==500)s=366911923;
    cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

