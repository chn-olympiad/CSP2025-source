#include<bits/stdc++.h>
using namespace std;
long long a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
    int ans=n*m;
    for(int i=1;i<=ans;i++)
    cin>>a[i];
    int h=a[1];
    int k;
    sort(a+1,a+ans+1);
    int sum=1;
    for(long long i=1;i<=ans;i++)
    {
        if(h==a[i])
        k=sum;
        sum++;
	}
	int x=1,y=0;
   for(long long i=1;i<=ans;i++)
   {
   if(y==n)
   {
   	    if(x==1||x==3||x==5||x==7||x==9)
   	    {
        y=n+1;
		x++;
		}
        else if(x==2||x==4||x==6||x==8)
        {
        y=0;
        x++;
        }

    }
   if(x==1||x==3||x==5||x==7||x==9)
   {
       y++;
   }
   else if(x==2||x==4||x==6||x==8)
   {
   	y--;
   }
   if(a[i]==h)
   cout<<y<<" "<<x<<endl;
   }

	return 0;
}