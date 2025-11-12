#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,k;
	int a[10000];
	int s=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		s=s+a[i];
	}
	cout<<s%998%244%353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

