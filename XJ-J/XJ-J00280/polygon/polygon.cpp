#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("","r",stdin);
	freopen("","w",stdout);
	long long a,s;
	cin >>a >>s;
	if(a<=3)cout << 1;
	else if(3<=a<=500)cout<<a*(a-1)/2;
	return 0; 
	fclose(stdout);
}
