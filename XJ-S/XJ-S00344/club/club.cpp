#include<bits/stdc++.h>
using namespace std;
int n;
struct cy
{
	int a,b,c;
};

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cy arr[n];
		for(int a=0;a<n;a++)
			cin>>arr[a].a>>arr[a].b>>arr[a].c;
	}
	return 0;
}

