#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n-2;i++){
		sum+=i;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}