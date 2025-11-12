#include<iostream>
#include<algorithm>
using namespace std;
const int N=15;
char s[N];
int n,m,c[N],p[N];
int chk()
{
	int res=0;
	for(int i=1;i<=n;++i)
		if(s[i]=='0')++res;
		else res+=res>=c[p[i]];
	return n-res>=m;
}
void ATRI()
{
	cin>>n>>m>>s+1;
	for(int i=1;i<=n;++i)cin>>c[i],p[i]=i;
	int ans=0;
	while(1)
	{
		ans+=chk();
		if(!next_permutation(p+1,p+n+1))break;
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ATRI();
	return 0;
}