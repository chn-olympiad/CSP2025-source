#include<bits/stdc++.h>
using namespace std;
int n;
const int mod = 998244353;
void n_lessthan_3(){
	if(n <= 2){
		cout << 0;
		return ;
	}
	int a[n+1],sum = 0,maxx = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		sum+=a[i];
		maxx=max(maxx,a[i]);
	}
	if(sum > 2*maxx){
		cout << 1;
	}
	else{
		cout << 0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if(n <= 3){
		n_lessthan_3();
	}
	else{
		int num = 1;
		for(int i = 3;i <= n;i++){
			num = (num*i)%mod;
		}
		cout << num;
	} 
	return 0;
}
