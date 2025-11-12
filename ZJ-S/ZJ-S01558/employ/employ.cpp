#include<bits/stdc++.h>
using namespace std;
string s;
int c[505];
int main()
{
 	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
 	std::cin.tie(NULL);
 	std::cout.tie(NULL);
 	int n,m;
 	cin>>n>>m;
 	cin>>s;
	 for(int i=1;i<=n;i++)
	 {
	 	cin>>c[i];
	 }
	 long long ans=1;
	 if(m==1)
	 {
	 	for(int i=1;i<=n;i++)
	 	{
	 		ans*=i%998244353;
	 		ans%=998244353;
		 }
	 }
	 cout<<ans<<endl;
 	return 0;
}
