#include<iostream>
using namespace std;
int n,m,c[505];
bool s[505];
inline int jc(int n)
{
	int sum=1;
	while(n--)
		sum*=n;
	return sum;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++)
		cin>>c[i];
	cout<<1+jc(n-1);
	return 0;
}
