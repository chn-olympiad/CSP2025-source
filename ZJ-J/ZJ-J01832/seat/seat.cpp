#include<bits/stdc++.h>

#define endl putchar('\n')
#define air putchar(' ')

using namespace std;
const int N=51*51;
int a[N],k=0;
int t;
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	t=a[1];
	int k;
	sort(a+1,a+n*m+1,cmp);
	
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==t)
		{
			k=i;
			break;
		}
	}
	t=1;
	int x=1,y=1,op=1;
	while(t!=k)
	{
		if(y==m&&x%2==1)
		{
			t++;
			x++;
			op=-1;
		}
		else if(y==1&&x%2==0)
		{
			t++;
			x++;
			op=1;
		}
		else t++,y+=op;
	}
	cout<<x<<' '<<y;
	return 0;
}
/*
      A           CCC
     A A         C
    A   A       C
   AAAAAAA     C
  A       A     C
 A         A     C
A           A     CCC
*/
