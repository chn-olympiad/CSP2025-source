#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	int a[n+101];
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	int s=0;
	for(int i=3;i<=n;i++){
		s+=i;
	}
	cout << s;
	return 0;
} 
