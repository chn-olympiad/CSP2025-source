#include<bits/stdc++.h>
#define int long long int
using namespace std;
int mp[25][25],n,m,grade,a[1000];
signed main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	 cin>>a[i];
	grade=a[1];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	int i=1,j=1;
	for(int cnt=1;cnt<=n*m;cnt++)
	{
	 if(a[cnt]==grade)
	 {
      cout<<i<<" "<<j;
	  return 0;
	 }
	 if(j==m&&i%2==1)
	  j=m+1,i++;
	 else if(j==1&&i%2==0)
	  j=0,i++;
	 if(i%2==1)
	  j++;
	 else
	  j--;
	}
	return 0;
}
