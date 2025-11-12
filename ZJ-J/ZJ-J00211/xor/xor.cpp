#include<bits/stdc++.h>
using namespace std;
int a[500001];
bool b[500001];
int t=1;	
int n=0,k=0;
struct point
{
	int x;
	int y;
}q[500001];
int bft(int i,int j,int s)
{
	if(s==k)
	{
		if(b[i]&&b[j])
		{
			return 0;
		}
		q[t].x=i;
		q[t].y=j;
		t++;
		for(int e=i;e<=j;e++)
		{
			b[e]=true;
		}
		return 0;
	}
	else if(j>=n)
	{
		return 0;
	}
	else
	{
		if(!b[i]&&!b[j]&&!b[j+1])
		{
			bft(i,j+1,s^a[j+1]);
		}	 
	}
	return 0;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{  
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		bft(i,i,a[i]);
	}
	cout<<t-1<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
 } 
