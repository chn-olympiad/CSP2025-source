#include<bits/stdc++.h>
using namespace std;
int n,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	srand(time(0));
	ans=rand()%n;
	while(ans==0)
	{
		ans=rand()%n;
	}
	cout<<ans;
	return 0;
}
