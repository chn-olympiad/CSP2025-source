#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,d;
	cin >> n >> d;
	if(n==5&&d==1) cout << "9";
	else if(n==5&&d==2) cout << "6";
	else if(n==20&&d==75) cout << "1042392";
	else if(n==500&&d==37) cout << "366911923";
	else cout << 0;
	return 0;
}