//考号：SN-J01111 姓名：陈柏霖   学校：西安市曲江第一中学 
#include <bits/stdc++.h>
using namespace std;

bool bigg(int x,int y)
{
	if(x>y) return true;
	else return false;
}

int locate(int a[],int n,int x)
{
	int L=0;
	int R=n-1;
	int mid=(L+R)/2;
	while(L<=R);
	{
		mid=floor((L+R)/2);
		if(a[mid]>x) L=mid;
		else if(x=a[mid]) return mid;
		else if(a[mid]<x) R=mid;
	}
	return mid;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;//n hang m lie
	cin>>n>>m;
	int s[m*n]={};
	int xR;
	for(int i=0;i<n*m;i++)
	{
		cin>>s[i];
	}
	xR=s[0];
	sort(s,s+m*n,bigg);
	int loc=locate(s,m*n,xR);
	cout<<loc<<endl;
	int c=loc/(n)+1;
	int r;
	if(c%2==1) r=(loc)-(c-1)*n;
	else r=n+1-(loc-(c-1)*n);
	cout<<c<<" "<<r;
	return 0;
} 
