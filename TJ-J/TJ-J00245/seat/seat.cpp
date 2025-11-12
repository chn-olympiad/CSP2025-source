#include<bits/stdc++.h>
using namespace std;
int seat[1000][1000];
int score[1000000];
int main()
{
	int x=1,y=1,n,m,cnt=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>score[i];
	}
	sort(a,a+cnt,cmp);
	while(true)
	{
		if(cnt==n*m)break;
		 
		for(int i=1;i<=n;i++)
		{
		a[cnt]=seat[x][y];
		x+=1;
		cnt++;	
		if(seat[x][y]==a[1])break;
		}
		if(cnt==n*m)break;
		y++;
		cnt++;
		if(seat[x][y]==a[1])break;
		for(int i=n;i>=1;i--)
		{
			a[cnt]=seat[x][y];
			x-=1;
			cnt++;
			if(seat[x][y]==a[1])break;
		}
		y++;
		cnt++;
		if(seat[x][y]==a[1])break;
	}
	cout<<x<<" "<<y; 
	return 0;
} 
