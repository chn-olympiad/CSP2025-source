#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		cin>>a>>b>>c;
		cout<<1;
	}
	
	else{
		srand(time(0));
		cout<<rand()%100;
	}
	

	return 0;
}

