#include<bits/stdc++.h>
using namespace std;
int point[1000];

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	double n,m,t;
	cin>>n>>m;
	int num=n*m,ren,rem;
	int i;
	for(i=1;i<=num;i++)
	{
		cin>>point[i];
		if(i==1) t=point[i];
	}
	sort(point+1,point+num+1,cmp);

	int l=1,r=num,mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(point[mid]<t) r=mid-1;
		if(point[mid]>t) l=mid+1;
		if(point[mid]==t) break;
	}
	if(point[mid]!=t)
	{
		if(point[l]==t) mid=l;
		else mid=r;
	}
	int row1=n,line1=m;
	if(mid<=row1) rem=1;
	else if(mid/row1==line1) rem=row1;
	else if(mid%row1==0) rem=mid/n;
	else rem=mid/n+1;
	
	
	int tem=mid%row1,tem2=row1%mid;
	if(rem%2==1)
	{
		if(tem==0) ren=row1;
		else ren=tem;
	}else
	{
		if(tem==0) ren=1;
		else ren=row1-tem+1;
	}
	
	
	cout<<rem<<" "<<ren;
	return 0;
 } 
