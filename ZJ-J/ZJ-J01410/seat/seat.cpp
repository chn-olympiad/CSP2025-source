#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,rx,x,ans=1;

int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m >> rx;
	for(int i=2;i<=n*m;i++)
	{
		cin >> x;
		if(x>rx) ans++;
	}
	int l=(ans-1)/m+1,r=(ans-1)%n+1;
	cout << l << " " << (l%2?r:n-r+1);
	
	return 0;
}