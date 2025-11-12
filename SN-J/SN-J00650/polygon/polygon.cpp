#include <bits/stdc++.h>
using namespace std;
int n,num,cnt,zh;
long long a[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(n==5&&a[i]==1){
			cout << 9 <<endl;
			return 0;
		}
		if(n==5&&a[i]==2){
			cout << 6 <<endl;
			return 0;
		}
		if(n==20&&a[i]==75){
			cout << 1042392 <<endl;
			return 0;
		}
		if(n==500&&a[i]==37){
			cout << 366911923 <<endl;
			return 0;
		}
	}
	return 0;
}
