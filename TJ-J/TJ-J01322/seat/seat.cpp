
#include<bits/stdc++.h>
using namespace std;
int a[5000][5000]={0};

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,R,b[50000],c[50000],z[5000];
	cin>>n>>m;                             
	for(int i = 1; i <= n*m;i++)  
	{
		cin>>b[i];
		c[i] = b[i];
	}
	R = b[1];
	for(int j = 0; j <= n*m-1;j++)  
	{
		int man = 0,man_id = 0,ji = n*m-j;
	
		for(int i = 0; i <= ji-1-j;i++) 
		{	
	
			if(b[i] > man)
			{
				man = b[i];
				man_id = i;
			} 
		}		
		z[j] = man;
		for(int i = 0; i <= ji-1-j;i++)  
		{
				b[i] = 0;
		}	
		int j1 = -1;
		for(int i = 0; i <= ji-1-j;i++)  
		{
			if(i != man_id)
			{j1++;}
			if(i != man_id)
			{
				b[j1] = c[i];
			}
			
		} 
		
	} 
	int n1 = 1,m1 = 1; 
	for(int i = 1; i <= n*m;i++)  
	{
	 	a[n1][m1] = z[i];
	 	m1++;
	 	if(m1 > m)
	 	{
	 		n1++;
	 		m1 = 1;
		 }
	} 
	n1 = 1,m1 = 1; 
	for(int i = 1; i <= n*m;i++)  
	{
	 	if(a[n1][m1] == R)
	 	{
		 	cout << n1<<" "<<m1;
		 	return 0;
		} 
	 	m1++;
	 	if(m1 > m)
	 	{
	 		n1++;
	 		m1 = 1;
		 }
	} 
	return 0;
}
