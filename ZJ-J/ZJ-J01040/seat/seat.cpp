#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[150];
int x,y;
int cnt;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	cnt=1;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])
			cnt++;
	}
	x=cnt/n;
	if(cnt%n!=0)
		x++;
	if(x%2==0)
		y=x*n-cnt+1;
	else
		y=cnt-n*(x-1);
	cout<<x<<" "<<y;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}