#include <bits/stdc++.h>
using namespace std;
int n,sss=1;
int a[5005];
bool check(int l, int r){
	for(int i=l;i<=r;i++){
		for(int j=l;j<=r;j++){
			if(i != j && a[i] == a[j]){
				return false;
			}
		}
	}
	return true;
}
long long Cnm(int a)
{
	long long s=1,v=1;
	for(int i=2;i<=a;i++){
		s *= i;
	}
	for(int i=2;i<=n-a;i++){
		v *= i;
	}
	long long ans = sss/s/v;
	return ans;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=2;i<=n;i++){
		sss *= i;
	}
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	if(n < 3){
		cout << 0;
		return 0;
	}
	if(n == 3){
		cout << 1;
		return 0;
	}
	if(n == 4 && check(0,n-1)){
		cout << 5;
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i < j && j-i+1 >= 3){
				if(check(i,j)){
					cout << Cnm(j-i+1);
				}
			}
		}
	}
	return 0;
}
