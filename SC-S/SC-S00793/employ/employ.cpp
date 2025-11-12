#include<bits/stdc++.h>
using namespace std;

const int N=500;
int a[N+10];

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n,m; cin>>n>>m;
	string q;
	for(int i=1;i<=n;i++) cin>>a[i];

	sort(a+1,a+n+1);
	
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i+1]){
			sum=sum+2;
		}
	}
	cout<<sum;

	return 0;
}
