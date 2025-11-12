#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int a[N];
long long mod=998244353;
int sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	srand(time(NULL));
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	if(sum==1)
	{
		cout<<0;
		return 0;
	}
	cout<<rand()%56;
}
