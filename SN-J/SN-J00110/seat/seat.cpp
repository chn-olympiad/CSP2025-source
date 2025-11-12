//SN-J00110 刘思辰 西安高新一中沣东中学初中校区 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,a[101],c,w=1,l,h;
	cin>>m>>n;
	cin>>c;
	for(int i=1;i<m*n;i++)
	{
		cin>>a[i];
		if(a[i]>c) w++;
	}
	if(w<=n) {
		h=w;
		l=1;
	}
	else 
	{
	if(w%n==0) 
	{
		l=w/n;
		if(l%2==0) h=1;
		else h=n;
	}
	else 
	{
		
	l=w/n+1;
	if(l%2==0) h=n-(w%n-1);
	else h=1+(w%n-1);
    } 
    }
    cout<<l<<" "<<h;
}
