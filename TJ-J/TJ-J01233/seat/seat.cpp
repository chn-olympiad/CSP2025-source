#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long cheng[100];
bool isok[100];
long long x = 1,y = 0;
long long t = 0;
long long gx[4] = {0,1,0,1},gy[4] = {1,0,-1,0};
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	cin>>n>>m;
	for(long long i = 0;i<n*m;i++)
	{
		cin>>cheng[i];
	}
	isok[0] = true;
	for(long long i = 1;i<=n*m;i++)
	{
		for(long long j = 0;j<n*m-i;j++)
		{
			if(cheng[j]<cheng[j+1])
			{
				swap(cheng[j],cheng[j+1]);
				swap(isok[j],isok[j+1]);
			}
		}
	}
	for(long long i = 0;i<n*m;i++)
	{
		if(y == m && t == 0)
		{
			t = (t+1)%4;
			x+=gx[t];
			y+=gy[t];
			t = (t+1)%4;
		}
		else if(y == 1 && t == 2)
		{
			t = (t+1)%4;
			x+=gx[t];
			y+=gy[t];
			t = (t+1)%4;
		}
		else
		{
			x+=gx[t];
			y+=gy[t];
		}
		if(isok[i])
		{
			cout<<x<<" "<<y<<endl;
			break;
		}
	}
	return 0;
}
