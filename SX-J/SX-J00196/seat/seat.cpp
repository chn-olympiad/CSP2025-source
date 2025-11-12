#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[120],n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int ming=a[0];
	sort(a,a+n*m);
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==ming){
			if((n*m-i)%n==0)
				cout<<(n*m-i)/n<<" "<<n;
			else
				cout<<(n*m-i)/n+1<<" "<<(n*m-i)%n;
			return 0;
		}

	}
}