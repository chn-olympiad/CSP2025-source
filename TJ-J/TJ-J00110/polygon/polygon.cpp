#include<bits/stdc++.h>
#define ll long long;
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	int sum=0,a;
	cin>>n;
	for(int i=1;i<=n;i++){
		sum+=i;
		cin>>a;
	}
	cout<<sum-3;
	return 0;
}
