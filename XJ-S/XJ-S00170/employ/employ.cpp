#include<bits/stdc++.h>
using namespace std;
long long int i,j,n,m,a[1000005],s,x=1,y=1,b[1000005];
char c[1000005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
	cin>>c[i];
	cin>>b[i];
	s+=c[i]-'0';
    }
    if(s==n)
    {
    	for(i=1;i<=n;i++)
    	{
    		x*=i;
		}
		for(i=1;i<=n-m;i++)
		{
			y*=i;
		}
		s+=x/y;
	}
	cout<<s;
	return 0;
}

