#include<bits/stdc++.h>
using namespace std;
int main()
{
	srand((unsigned)time(0));
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin>>n;
	cout<<rand()%n;
	return 0;
}
