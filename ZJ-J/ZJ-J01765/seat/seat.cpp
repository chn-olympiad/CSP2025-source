#include<bits/stdc++.h>
using namespace std;
const int N=205;
int n,m,a[N],k,r,j,ac,ar;
bool Cmp(int a,int b){return a>b;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>r;
	k=n*m;
	a[1]=r;
	for(int i=2;i<=k;i++)
		cin>>a[i];
	sort(a+1,a+k+1,Cmp);
	for(int i=1;i<=k;i++)
	{
		if(a[i]==r)
		{
			j=i;
			break;
		}
	}
	ac=(j-1)/n;
	cout<<ac+1<<" ";
	ar=j%n;
	if(!ar)
		ar=n;
	if(ac%2)
		ar=n+1-ar;
	cout<<ar;
	return 0;
}
