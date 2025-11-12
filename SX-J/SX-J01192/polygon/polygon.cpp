#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int main() {
	//freopen("polygon.in", "r", stdin);
	//freopen("polygon.out", "w", stdout);
	cin>>n;
	int mx=0;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	srand(time(0));
	int l=rand();
	cout<<rand()*79824;
	return 0;
}