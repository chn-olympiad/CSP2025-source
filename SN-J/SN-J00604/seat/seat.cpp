//杨俊楠 SN-J00604 西安市曲江第一中学 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+1];
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int R=a[1],indR=0;
	
	sort(a+1,a+1+m*n);
	for(int i=m*n;i>0;i--)
	{
		//cout<<a[i]<<" ";
		if(a[i]==R) indR=m*n-i+1;
		//cout<<indR<<"<indR ";
	}
	
	int seatx,seaty;
	seatx=indR/n;
	int st=n;
	if(indR%n!=0)
	{
		seatx++;
		st=0;
	 } 
	int tep=indR%n;
	if(seatx%2==1) 
	{
		seaty=indR%n+st;
	}
	else if(seatx%2==0)
	{
		seaty=n-indR%n+1+st;
	}
	cout<<seatx<<" "<<seaty;
	return 0;
}
