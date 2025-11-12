#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n,m,v=0;char c;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;int a[n*m];
	for(int i=0;i<n*m;i++)
	{a[i]=-1;
	}
	for(int i=0;i<n*m;i++)
	{	
		cin>>a[v];v++;
		c=getchar();
		if((c<'0'||c>'9')&&(c<'a'||c>'z')&&(c!=' ')){break;
		}
	}v=a[0];
	sort(a,a+(n*m));
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==v){v=n*m-i;break;};
	}cout<<v<<endl;
	int l=v%n==0?v/n:v/n+1,h=l%2==0?n-v%(n+1):(v%n==0?v%(n+1):max(1,v%n));
	cout<<l<<" "<<h;
	return 0;
}
