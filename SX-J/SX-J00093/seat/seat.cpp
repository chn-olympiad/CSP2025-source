#include<iostream>
using namespace std;
	int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int jl;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	jl=a[1];
	while(1){
		int sum=0;
		for(int i=2;i<=n*m;i++){
			if(a[i]>a[i-1])
			{
				swap(a[i],a[i-1]);
			}
		}
		if(sum==0) break;
	}
	for(int i=1;i<=n*m;i++)
	{
		if(jl==a[i]) jl=i;
	}
	if(jl%n==0){
		if(jl/n%2==0)
		{
			cout<<jl/m<<' '<<'1';
		}
		else if(jl/n%2==1)
		{
			cout<<jl/n<<' '<<n;
		}
	}
	else if(jl%n!=0)
	{
		if(jl/n%2==0)
		{
			cout<<jl/n+1<<' '<<jl%n;
		}
		else if(jl/n%2==1)
		{
			cout<<jl/n+1<<' '<<n-jl%n;
		}
	}
	return 0;
}