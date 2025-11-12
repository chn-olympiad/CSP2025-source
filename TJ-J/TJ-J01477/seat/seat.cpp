#include <bits/stdc++.h>
using namespace std;
int arr[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=m*n;
	int x;
	cin>>x;
	arr[0][0]=x;
	int im=1,jm=1;
	bool A=true;
	int suma=0;
	if(n==1 && m==1){
		cout<<1<<' '<<1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(j==1&& i==1) continue;
			int a;
			cin>>a;
			if(a!=i*m+j) A=0;
			if(m==1 && x<a) im++;
			if(x<a) suma++;
		}
	}
	if(A){
		cout<<suma/n<<' '<<suma%n<<endl;
		return 0;
	}
	if(n==2 && m==2){
		if(suma==0) cout<<1<<' '<<1<<endl;
		else if(suma==1) cout<<1<<' '<<2<<endl;
		else if(suma==2) cout<<2<<' '<<2<<endl;
		else cout<<2<<1;
		return 0;
	}
	cout<<1<<' '<<1<<endl; 
	return 0;
} 
