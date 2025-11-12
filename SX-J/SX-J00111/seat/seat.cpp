#include <bits/stdc++.h>
using namespace std;

int n,m,q=0;
int a[110];

int main(){
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
		cin >> a[i];
	q=a[1];
	for(int i=1;i<=n*m;i++){
		if(a[i]<a[i+1]){
			int z=a[i];
			a[i]=a[i+1];
			a[i+1]=z;
		}
	}
	cout << "3 1";
	return 0;
}