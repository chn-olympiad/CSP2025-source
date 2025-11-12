#include<bits/stdc++.h>
using namespace std;
int a[15][15],nm[105],n,m,bb;
int main(){
	//freopen("seat.in","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>nm[i];
	}
	bb=nm[1];
	for(int i=1;i<=n*m;i++)
	{
		for(int j=2;j<=n*m;j++)
    	{
	    	if(nm[j]>nm[j-1])
	    	{
	    		int t=0;
	    		t=nm[j];
	    		nm[j]=nm[j-1];
	    		nm[j-1]=t;
			}
	    }
	}
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=n*m;j++)
    	{
	    	if(a[i][j]==bb)
	    	{
	    		cout<<i+j;
	    		break;
			}
	    }
	}
	return 0;
}
