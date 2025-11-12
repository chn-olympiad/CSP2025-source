#include<bits/stdc++.h>
using namespace std;
int n,m,a[1010];
bool cmp(int a,int b)
{
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
	{
		cin >> a[i];
	}
	int k=a[1];
	sort(a+1,a+1+n*m,cmp);
	int i=1,r=1,c=1;
	while(k!=a[i])
	{
		i++;
		c+=r/n;
		r%=n;
		r++;
	}
	if(c%2==0)
	{
		cout << c << " " << n-r+1;
	}
	else
	{
		cout << c << " " << r;
	}
	return 0;
}
