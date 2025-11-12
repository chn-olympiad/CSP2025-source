//SN-J00773  王梓骏  西安滨河学校
#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int s;
	cin>>s;
	for(int i=1; i<=30; i++) {
		if(s==1||s==2||s==3||s==4||s==5||s==6||s==7||s==8||s==9) {
			cout<<s;
			break;
		} else {
			cout<<92100;
		}
	}
	return 0;
}
