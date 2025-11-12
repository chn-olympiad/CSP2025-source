#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],sum,b;
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sum=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==sum){
			b=i;
		}
	}
	if(b%n==0){
		if((b/n)%2==1){
			cout<<b/n<<" "<<n;
			return 0;
		}
		else{
			cout<<b/n<<" "<<1;
			return 0;
		}
	}
	else{
		if((b/n+1)%2==1){
			cout<<b/n+1<<" "<<b%n;
			return 0;
		}
		else{
			cout<<b/n+1<<" "<<m-b%n+1;
			return 0;
		}
	}
	return 0;
}
