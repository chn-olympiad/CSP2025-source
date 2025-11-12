#include <iostream>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>r;
	int a[105];
	for(int i=1;i<n;i++)
	{
		int num;
		cin>>num;
		a[num]++;
    }
    int min1;
	a[min1]++;
	int p=0;
	for(int i=100;i>min1;i--)
	{
		p+=a[i];
		cout<<p/m+1;
		cout<<" ";
	}
	if(p/m+1 & 2!=0)
	{
		cout<<p/m+1; 
	}
	return 0
}
