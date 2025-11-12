#include <fstream>
#include <set>
using namespace std;
ifstream cin("polygon1.in");
ofstream cout("polygon.out");
int n,a[5001],sum=0,t[5001];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ut=3;
	for(int i=1;i<=n-ut;i++){
		for(int j=1;j<=ut;j++)
			t[j]=a[i+j-1];
		for(int j=1;j<n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=n-j;l<=n;l++)
					if(a[j]<a[k])
						swap(t[j],t[k]);
		int op=0;
		for(int j=1;j<=ut;j++)
			op+=a[i+j-1];
		if(op>t[1]*2)
			sum++;
	}
	cout<<sum%998%244%353;
	return 0;
}
