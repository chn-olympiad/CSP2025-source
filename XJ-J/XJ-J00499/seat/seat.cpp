#include <iostream>
using namespace std;
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105];
	for(int i=1;i<n;i++)
	{
		int num;
		cin>>num;
		a[num]++;
    }
    int min1,hum=0;
    cin>>min1;
	a[min1]++;
	for(int i=100;i>min1;i--)
	{
		hum+=a[i];
		cout<<hum/m+1+1;
		cout<<" ";
	}
	if(hum/m+1 & 2!=0)
	{
		cout<<hum/m+1+1; 
	}
	return 0;
}
