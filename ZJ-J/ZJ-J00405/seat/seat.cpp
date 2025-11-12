#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int sc,id;
};
Node a[110];
bool cmp(Node x,Node y)
{
	return x.sc>y.sc;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int cur=n*m;
	for(int i=1;i<=cur;i++)
	{
		cin>>a[i].sc;
		a[i].id=i;
	}
	sort(a+1,a+cur+1,cmp);
	int lie=1,hang=0;
	for(int i=1;i<=cur;i++)
	{
		if(lie%2==1)
		{
			if(hang==0) hang++;
			else if(hang<n) hang++;
			else lie++;
		}
		else
		{
			if(hang>1) hang--;
			else lie++;
		}
		if(a[i].id==1)
		{
			cout<<lie<<" "<<hang<<endl;
			break;
		}
	}
	return 0;
}
