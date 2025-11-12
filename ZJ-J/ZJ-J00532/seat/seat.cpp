#include<bits/stdc++.h>
using namespace std;
const int N=107;
const int M=107;
int n,m;
int A[N],C[M];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>A[i];
	for(int i=1;i<=n*m;i++)
		C[A[i]]++;
	int ans=0;
	for(int i=100;i>=A[1];i--)
	{
		ans+=C[i];
	}
	int c=(ans-1)/n+1,r;
	if(c&1)
		r=(ans-1)%n+1;
	else
		r=c*n-ans+1;
	cout << c<<' '<<r<<endl;
	return 0;
}
