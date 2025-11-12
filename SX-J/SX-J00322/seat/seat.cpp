#include<bits/stdc++.h>
using namespace std;
int n,m;
int rf,rw;
int b[100005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n*m;i++) cin>>b[i];
	rf=b[0];
	sort(b,b+n*m,greater<int>());
	for(int i=0;i<n*m;i++)
	{
		if(b[i]==rf)
		{
			rw=i;
			break;
		}
	}
	int x=rw/n;
	cout<<x+1<<" ";
	if(x%2==0) cout<<rw-x*n+1;
	else cout<<n-rw+x*n;
	return 0;
}