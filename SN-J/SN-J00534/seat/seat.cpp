//SN-J00534 高新二中 李昊泽 
#include<bits/stdc++.h>
using namespace std;
priority_queue<int> q;
int m,n;
int g[1000500];
int r;
int rr;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m*n;i++){
		cin>>g[i];
		if(i==1) r=g[i];
		q.push(g[i]);
	} 
	for(int i=1;i<=m*n;i++)
	{
		g[i]=q.top();
		q.pop();
		if(g[i]==r)
		{
			rr=i;
		} 
	}
	
	
	
	int mm=0,nn=0;
	mm=rr/n+1;
	if(mm%2==0)	
	{
		nn=mm*n-rr+1;
	}
	else
	{
		nn=rr-(mm-1)*n;
	}
	cout<<mm<<" "<<nn;
	return 0;

}
