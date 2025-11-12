#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,cnt,l,sum,s,b,c;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++)
	{
		cin>>l;
		if(i==1) {
			s=l;
		}
		a[l]++;
	}
	for(int i=100;i>=1;i--)
	{
		if(a[i]!=0){
			cnt++;
		}
		if(i==s)
		{
			break;
		}
	}
	if(cnt%n==0)
	{
		c=(cnt/n);
		if(n%2==0) {
			cout<<1<<" "<<n;
		}else{
			cout<<n<<" "<<n;
		}
	}
	else {
		c=(cnt/n)+1;
		b=cnt/n;
		if((b+1)%2==0)
		{
			cout<<c<<" "<<n+1-(cnt%n);
		}
		else{
			cout<<c<<" "<<cnt%n;
		}
	}
	return 0;
}
