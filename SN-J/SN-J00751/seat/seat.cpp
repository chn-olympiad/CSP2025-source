#include <bits/stdc++.h>
using namespace std;
int a[110],x[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,z=0;
	cin >> n >> m;
	z=n*m;
	for(int i=1;i<=z;i++){
		cin >>a[i];
	}
	int p=0;
	int dd=a[1];
	sort(a,a+z+1);
	int s21=0;
	for(int i=z;i>=1;i--){
		s21++;
		if(a[i]==dd){
			 p=s21;
			break;
		}
	}
	if(p%n==0){
		if((p/n)%2==0){
			cout <<p/n<<" "<<1;
		}
		else
		{
			cout <<p/n  <<" "<<n; 
		}
	}
	else
	{
		if((p/n+1)%2==0){
			cout <<p/n+1<<" "<<(p%n)+1;
		}
		else
		{
			cout <<p/n+1<<" "<<p%n;
		}
	}
}
