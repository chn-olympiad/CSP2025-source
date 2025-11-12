#include<bits/stdc++.h>
using namespace std;
const int maxn=10001;
bool cmp1(int a,int b)
{
	return a>b;
}
int n,m;
int a[maxn],num;
int hg,le;
int r,se;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	num=n*m;
	for(int i=1;i<=num;i++)
	{
		cin >> a[i];
	}
	
	r=a[1];
	sort(a+1,a+1+num,cmp1);
	for(se=1;se<=num;se++)
	{
		if(a[se]==r)
		{
			break;
		}
	}
	
	le=se/n;
	if(le*n<se)
	{
		if(le&1)
		{
			hg=n-(se-le*n)+1;
		}
		else
		{
			hg=se-le*n;
		}
		le++;
	}
	else
	{
		if(le&1)
		{
			hg=n;
		}
		else
		{
			hg=1;
		}
	}
	cout << le << " " << hg << "\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

