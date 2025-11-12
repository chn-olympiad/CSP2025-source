#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],h,l;
bool cnp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int x=a[1];
	sort(a+1,a+n*m+1,cnp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==x){
			if(i%n!=0)
			{
				l=i/n+1;
				if(l%2==1)h=i%n;
				else h=n-i%n+1;
			}
			else {
				l=i/n;
				if(l%2==1)h=n;
				else h=1;
			}
			break;
		}
	}
	cout<<l<<" "<<h;
	return 0;
}

