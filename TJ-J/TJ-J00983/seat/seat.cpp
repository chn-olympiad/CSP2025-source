#include <bits/stdc++.h>
using namespace std;
int n,m,s,x,ct=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m >> s;
	for(int i=1;i<n*m;i++)
	{
		cin >> x;
		if(x>s)
		{
			ct++;
		}
	}
	if((ct-1)/n%2==0)
	{
		cout << (ct-1)/n+1 << " " << (ct-1)%n+1;
	}
	else
	{
		cout << (ct-1)/n+1 << " " << n-ct%n+1;
	}
	return 0;
}
