#include<bits/stdc++.h>
using namespace std;
int n,m,a[101];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int nm=n*m;
	for(int i=1;i<=nm;i++)cin>>a[i];
	int num=a[1];
	sort(a+1,a+nm+1,cmp);
	int hang=1,lie=1;
	for(int i=1;i<=nm;i++)
	{
		if(a[i]==num)
		{
			cout<<lie<<" "<<hang;
			return 0;
		}
		if(lie%2==1)
		{
			if(hang==n)lie++;
			else hang++;
		}
		else
		{
			if(hang==1)lie++;
			else hang--;
		}
	}
	return 0;
}
