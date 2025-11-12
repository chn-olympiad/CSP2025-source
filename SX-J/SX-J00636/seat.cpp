#include <iostream>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a,b,sum=1;
    cin>>n>>m;
    cin>>a;
    b=a;
    for(int i=1;i<=n*m-1;i++)
    {
        cin>>a;
        if(a>b)
        {
             sum++;
        }
        
    }
    cout<<sum/n+1<<" ";
    if((sum/n+1)%2==1)
    {
		cout<<sum%n;
	}
	else
	{
		cout<<n-(sum%n-1);
	}
}
