#include <bits/stdc++.h>
using namespace std;
char a[1000],b[1000];   
int n=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    for(int i=1;i<=100;i++)
    cin>>a[i];
    for(int i=1;i<=100;i++)
    {
    if(a[i]<=57)
    {
    b[n]=a[i];
    n++;
	}
	}
	sort(b+1,b+n+1);
	for(int i=n;i>=1;i++)
	cout<<b[i];
    return 0;
}
