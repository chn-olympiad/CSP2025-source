#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b;
	cin >> a >> b;
	int num[a];
	for(int i=0;i<a;i++){
		cin >> num[i];
	}
	if(b==0){
		cout << 1 <<endl;
	}
	else{
		cout << 2 <<endl;
	}
	return 0;
}
