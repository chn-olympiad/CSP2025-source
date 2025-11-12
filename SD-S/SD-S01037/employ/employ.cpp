#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans,cnt,num,dy;
ll mx;
string str;
ll a[502],b[502],c[502]; 
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	ll i,j,ii;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>str;
	for(i=0;i<n;i++)
	{
		a[i+1]=str[i]-'0',c[i+1]=i+1;
		if(a[i+1]==1)  mx++;
	}
	if(mx<m)
	{
		cout<<0;
		return 0;
	}
	for(i=1;i<=n;i++)  cin>>b[i];
	do{
		cnt=0,num=0,dy=0;
		for(i=1;i<=n;i++)
		{
			dy++;
//			cout<<i+num<<" "<<c[i+num]<<" "<<b[c[i+num]]<<endl; 
			if(num>=b[c[i]])
			{
				num++;dy--;continue;
			}
			if(a[dy]==1)  cnt++;
			if(a[dy]==0)  num++;
		}
		if(cnt>=m)  ans++;
//		cout<<endl<<endl;
//		for(i=1;i<=n;i++)  cout<<c[i]<<" ";
//		cout<<endl;
	}while(next_permutation(c+1,c+1+n));
	cout<<ans;
	return 0;
}
