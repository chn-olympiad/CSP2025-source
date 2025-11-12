#include <iostream>
using namespace std;
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>a;
	int n=a.size();
	for(char i='9';i>='0';i--){
		for(int j=0;j<n;j++){
			if(a[j]==i){
				cout<<i;
			}
		}
	}
	return 0;
}

