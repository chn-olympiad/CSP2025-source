#include<bits/stdc++.h>
using namespace std;
int a[1005],t,n,m,na=1,ma=1;
bool cmp(int c,int d)
{
	return c>d;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			cout<<ma<<' '<<na;
			return 0;
		}
		if(ma%2==1){
			if(na==n) ma++;
			else na++;
		}
		else{
			if(na==1) ma++;
			else na--;
		}
	}
	return 0;
}