#include<iostream>
#include<random>
using namespace std;
mt19937 rd(random_device{}());
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n=2e5,m=2e5;cout<<n<<" "<<m<<"\n";
	for(int i=1;i<=n;++i)
	{
		// for(int j=1;j<=12;++j)cout<<char(rd()%26+'a');
		for(int j=1;j<=12;++j)cout<<'a';
		cout<<" ";
		// for(int j=1;j<=12;++j)cout<<char(rd()%26+'a');
		for(int j=1;j<=12;++j)cout<<'a';
		cout<<"\n";
	}
	for(int i=1;i<=m;++i)
	{
		// for(int j=1;j<=12;++j)cout<<char(rd()%26+'a');
		for(int j=1;j<=12;++j)cout<<'a';
		cout<<" ";
		// for(int j=1;j<=12;++j)cout<<char(rd()%26+'a');
		for(int j=1;j<=12;++j)cout<<'a';
		cout<<"\n";
	}
	return 0;
}