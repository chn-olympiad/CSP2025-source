#include<bits/stdc++.h>
using namespace std;
int a[190];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int summ=a[1],sum;
	int rs=n*m;
	sort(a+1,a+rs+1);
	for(int i=1;i<=rs;i++)if(a[i]==summ){
		summ=-1;
		sum=i;
	}
	sum=rs-sum;
	int x=sum/n,y=sum%n;
	if(x%2==0)cout<<x+1<<" "<<y+1;
	else cout<<x+1<<" "<<m-y;
	return 0;
}
