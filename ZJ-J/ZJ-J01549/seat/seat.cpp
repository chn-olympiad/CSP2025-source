#include<bits/stdc++.h>
using namespace std;
long long n,m,s[101],mc=1,hang,lie;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>s[i];
		if(i!=1&&s[i]>s[1])
		{
			mc++;	
		}
	}
	lie=mc/n+1;
	if(mc%n==0)lie--;
	if((mc/n)%2==1)hang=m-mc%n+1;
	else hang=mc%n;
	cout<<lie<<" "<<hang;
	return 0;
}
