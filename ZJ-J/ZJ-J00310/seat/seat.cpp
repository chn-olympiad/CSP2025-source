#include<bits/stdc++.h>
using namespace std;
int x,y,z,n,m,a[11000],s;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
    	cin>>a[i];
    	if(a[i]>a[1]) s++;
	}
	x=1,y=1,z=1;
	while(s--)
	{
		if(x+z!=0&&x+z!=n+1) x+=z;
		else y++,z=-z;
	}
	cout<<y<<" "<<x<<endl;
	return 0;
}
