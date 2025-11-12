#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N];
int cmp(int A,int B){
	return A>B;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	int t=n*m;
	for(int i=1;i<=t;i++)
		cin>>a[i];
	int x=a[1];
	int xp=0;
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++){
		if(a[i]==x)
			xp=i;
	}
	int l,h;
	if(xp%n==0)
		l=xp/n;
	else
		l=xp/n+1;
	if(l%2==0){
		if(xp%n==0)
			h=1;
		else
		    h=n-(xp%n)+1;
	}
	else{
		if(xp%n==0)
		    h=n;
		else
		    h=xp%n;
	}
	cout<<l<<" "<<h;
	return 0;
}
