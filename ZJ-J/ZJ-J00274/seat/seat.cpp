#include<bits/stdc++.h>
using namespace std;
bool bmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=0,m=0,a[105]={};
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	int r=a[0],x=0,y=0,flag=1;
	sort(a,a+105,bmp);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++){
			if(a[i*n+j]==r){
				x=i+1;
				if(i%2==0)y=j+1;
				else y=n-j;
				flag=0;
				break;
			}
		}
		if(flag==0){
			break;
		}
	}
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
