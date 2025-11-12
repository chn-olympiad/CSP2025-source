#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t;
	int sum;
	int max;
	int n1,n2,n3;
	cin>>t>>n;
	string a;
	for(int j=1;j<=t;j++){
		sum=0;
		max=0;
		for(int i=1;i<=n;i++){
			cin>>n1>>n2>>n3;
			if(n1>n2 && n1>n3) max=n1;
			else if(n2>n1 && n2>n3) max=n2;
			else 
				max=n3;
			sum+=max;
		}
		cout<<sum<<endl;
	}
	return 0;
} 
