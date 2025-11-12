#include<iostream>
#include<random>
using namespace std;
mt19937 rd(random_device{}());
void ATRI()
{
	int n=1e4,m=1e6,k=10,w=1e9;cout<<n<<" "<<m<<" "<<k<<"\n";
	for(int i=1;i<=m;++i)cout<<rd()%n+1<<" "<<rd()%n+1<<" "<<rd()%w+1<<"\n";
	while(k--)
	{
		cout<<rd()%w+1<<" ";
		for(int i=1;i<=n;++i)cout<<rd()%w+1<<" \n"[i==n];
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ATRI();
	return 0;
}