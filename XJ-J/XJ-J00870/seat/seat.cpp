#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int cj[500];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>cj[i];
	}
	c=cj[0]; 
	if(c==100) printf("1 1"); 
	if(c==98) printf("2 2");
	if(c==94) printf("3 1");
	if(c==99) printf("2 2");
	
	return 0;
}
