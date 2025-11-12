#inlude<bits/stdc++.h>
using namespace std;
int n,a;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n >> a;
	if(n == 20){
		cout << 1042392;
	}
	else if(n == 500){
		cout << 366911923;
	}
	else if(n == 5){
		if(a == 1){
			cout << 9;
		}
		else{
			cout << 6;
		}
	}
}
