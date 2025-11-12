#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	int a1,a2,a3,a4;
	cin>>a1>>a2>>a3>>a4;
	if(a3<a1 || a3<a2 || a3<a4 || a2<a1 || a1<a4)
	cout<<"1 2 ";
	else if(a2<a1 || a2<a3 || a2<a4 || a1<a3 || a1<a4)
	cout<<"2 2 ";
	else  if(a1<a2 || a1<a3 || a1<a4 || a2<a3<a4)
	cout<<"2 1 ";
	else if(a4<a1 || a4<a3 || a4<a2 || a3<a1 || a2<a1)
	cout<<"1 1 ";
	return 0;
}
