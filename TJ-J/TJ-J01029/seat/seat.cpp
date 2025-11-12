#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int s[n*m];
	for(int i=0;i<=n*m;i++){
		cin>>s[i];
	}
	cin >> n;
	cin >> m;
	cout << n <<" "<< m;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
