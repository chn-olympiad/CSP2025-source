#include <bits/stdc++.h>
using namespace std;
int n,m,t,a[10010],x=1,z;

bool cmp1(int x,int y){
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
	t=a[1];
	sort(a+1,a+m*n+1,cmp1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			z=i;
		}
	}
	if(z<=n){
		cout<<x<<" "<<z;
	}
	else{
		cout<<x+z/n<<" ";
		if((x+z/n)%2==0){
			if(z%n==0){
				cout<<1;
			}
			else{
				cout<<n-z%n+1;
			}
		}
		else{
			if(z%n==0){
				cout<<n;
			}
			else{
				cout<<z%n;
			}
		}
	}
	return 0;
 }
