//杨俊楠 SN-S00391 西安市曲江第一中学
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	long long kk=n*m;
	if(kk<100) 
	{
		cout<<rand()%(n*m);
		return 0;
	}
	cout<<k*134620+(rand()%(kk));
	return 0;
}
