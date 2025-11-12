#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("seat1.in","r",stdin);
	freopen("seat1.ans","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=20;i++){
		cout<<n*m;
	} 
	dclose("seat1.in","r",stdin);
	dclose("seat1.ans","w",stdout);
	return 0;
}
