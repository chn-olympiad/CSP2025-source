#include <bits/stdc++.h>
using namespace std;
struct T{
	int pj1;
	int pj2;
	int pj3;
}a[200005];
int s[200005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++){
		long long sum=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j].pj1>>a[j].pj2>>a[j].pj3;
			s[j]=a[j].pj1+a[j].pj2+a[j].pj3;
		}
		sort(s+1,s+n+1,greater<int>());
		int cs=n/2;
		for(int j=1;j<=cs;j++){
			sum+=s[j];
		}
		cout<<sum<<endl;
		memset(s,0,sizeof(s));
	}
	return 0;
}
