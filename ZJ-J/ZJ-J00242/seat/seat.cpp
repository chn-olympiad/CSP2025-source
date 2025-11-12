#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,x,y,cnt,num;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m>>a;
	for(int i=2;i<=n*m;i++) 
    {
    	cin>>b;
    	if(b>a) num++;
	}
	num++;
	x=1;y=1;cnt=1;
	while(cnt<num)
	{
		if(y&1) 
		{
			if(x<n) x++;
			  else y++;
		}
		else
		{
			if(x>1) x--;
			  else y++;
		}
		cnt++;
	}
	cout<<y<<" "<<x<<'\n';
	return 0;
}