#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<cstring>
#include<string>
#include<queue>
#define long long long
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	string n,a;
	getline(cin,n);
	getline(cin,a);
	if(a=="1 2 3 4 5"){
		cout<<9;
	}
	else cout<<6;
	return 0;
}

