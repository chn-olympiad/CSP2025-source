#include<bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m,x;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
    	cin>>a[i];
	}
	x=a[1];sort(a+1,a+n*m+1);
	int i=1;
	for(;i<=n;i++)if(a[i]==x)break;
	i=n*m-i+1;
	cout<<(i-1)/n+1<<" "<<(((i-1)/n+1)%2?(i-1)%n+1:n+1-((i-1)%n+1));
	return 0;
}

