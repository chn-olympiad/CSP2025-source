#include <fstream>
#include <cmath>
using namespace std;
ifstream cin("seat2.in");
ofstream cout("seat.out");
int m,n;
int a[101];
int main()
{
	cin>>m>>n;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1],b;
	for(int i=1;i<=n*m;i++)
		for(int j=i+1;j<=n*m;j++)
			for(int k=1;k<=n*m;k++)
				if(a[k]<a[i])
					swap(a[k],a[i]);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x)
			b=i;
	}
	int c=b/m,d=b%m;
	if(b%m!=0)c++;
	cout<<c<<' ';
	if(c%2==0)
		cout<<abs(n-b);
	else
		cout<<d;
	return 0;
}
