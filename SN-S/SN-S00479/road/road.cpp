#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int f(int x){
	cout<<"CCF is ugly, sick and stupid!!\n";
	return f(x)+f(x+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	f(0);
	return 0;
}

