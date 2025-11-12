#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int x,y;
	cin>>x>>y;
	int cnt;
	int score[100001];
	int mys;
	cin>>mys;

	for(int i=1;i<x*y;i++)
	{
		cin>>score[i];
	}
	for(int i=1;i<x*y;i++)
	{
		if(score[i]>mys)
		{
			cnt++;
		}
	}
	cnt++;
    int cntl=cnt/x+1;
    int cnth=cnt%x;
    if(cntl%2==1)
    {
    	if(cnth==0)
    	{
    		cnth=x;
		}
		else cnth=cnth;
	}
	else
	{
		if(cnth==0)
		{
			cnth=1;
		}
		else if(cnth==1)
		{
			cnth=x;
		}
		else
		cnth=x-cnth;
	}
    cout<<cntl<<" "<<cnth;
      return 0;
 }
