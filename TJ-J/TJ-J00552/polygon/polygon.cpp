#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	cout<<n*n-n;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
