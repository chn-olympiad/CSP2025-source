#include <bits/stdc++.h>
#define down false
#define up true
using namespace std;
int n,m,a[100010];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	/*输入环节*/
	cin>>n>>m;
	for(int i=1; i<=n*m; i++)
	{
		cin>>a[i];
	}
	/*求出排名*/ 
	int rank=1;
	for(int i=1; i<=n*m; i++)
	{
		if(a[i]>a[1]) rank++;
	}
	/*进行排列*/ 
	int /*行数*/ln=1, /*列数*/col=1;
	bool dir=down;
	for(int i=1; i<rank; i++)
	{
		if(dir==down && ln==n)
		{
			dir=up;
			col++;
		}
		else if(dir==up && ln==1)
		{
			dir=down;
			col++;
		}		
		else if(dir==down)
		{
			ln++;
		}
		else if(dir==up)
		{
			ln--;
		}
	} 
	cout<<col<<" "<<ln;
	return 0;	
}
