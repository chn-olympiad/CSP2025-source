#include <iostream>
using namespace std;
int a[500];
long long num;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	for(int i = 0; i <= n.size()-1; ++i) {
		a[n[i]]++;
	}
	for(int i = '9'; i >= '0'; --i) {
		for(int j = 1; j <= a[i]; ++j) {
			if(j!=1&&i=='0'&&num==0){
				//呜呜哇哇
			} else {
				printf("%c",i);
			}
			num+=(i-'0');
		}
	}
	return 0;
}