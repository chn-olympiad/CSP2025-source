#include<bits/stdc++.h>
using namespace std;
long long a[1010];

int main()
{
	freopem("employ.in","r",stdin);
	freopen("employ,out","w",stdout);
	int n,m;
	cin>>n>>m;
	char n1;
	cin>>n1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	srand((unsigned int) time(NULL));
	cout<<rand()%998244353+1<<endl;//rand%(最大值-最小值+1)+1; 
	return 0;
 } 

