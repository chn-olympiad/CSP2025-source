#include<iostream>
#include<random>
using namespace std;
mt19937 rd(random_device{}());
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n=rd()%5+1,m=rd()%(n+1);cout<<n<<" "<<m<<"\n";
	for(int i=1;i<=n;++i)cout<<"01"[rd()&1];
	cout<<"\n";
	for(int i=1;i<=n;++i)cout<<rd()%(n+1)<<" \n"[i==n];
	return 0;
}