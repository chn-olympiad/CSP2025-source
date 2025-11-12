#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[11][11];
    int b[11][11];
	int n,m;
	cin>>n>>m;
	int num=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	int s=a[1][1];
	int s1=1,s2=1;
for(int i=1;i<=n;i++)
	{
		int num=a[i][1];
		for(int j=1;j<=m;j++)
		{
			if(num<a[i][j])
			{
				num=a[i][j];
				a[i][j]=0; 
			}
			b[s1][s2]=num;
		}
		s1++;
		s2++;
	}
    for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(num==a[i][j])
			{
				int s3=i,s3=j;
				int s4=1,s5=1;
	            if(s3>n){
		        s4=s4+s3/n;
		        s5=2;
		         if(j){
		         	
				 }
	           }
			}
		}
	}
	cout<<s4<<" "<<s5;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
