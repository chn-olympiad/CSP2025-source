#include<iostream>
using namespace std;
int main(){
	freopen("number.in ","r",stdin);
	freopen("number.out ","w",stdout);
	int m,k;
	cin>>m;
	k=m%10;
	m=m/10;
	cout<<m;
	fclose(stdin);
		fclose(stdout);
	


	return 0;
}
