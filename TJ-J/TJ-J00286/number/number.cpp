#include<bits/stdc++.h>
using namespace std;
int l[10] = {0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin >> a;

	for(int i = 0;i < a.size();i++){
		if(a[i] <= 'a'){
			l[a[i] - '0'] += 1;
		}
	}
	for(int i = 9;i >= 0;i--){
		for(int j = 0;j < l[i];j++){
			cout << i;
		}
	}
	return 0;
}
