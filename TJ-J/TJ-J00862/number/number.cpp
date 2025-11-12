#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a,b; 
	cin >> a;
	for(int i = 0;i<100;++i){
		char j = a[i];
		if (j < 58){
			b += a[i];
		}
	}
	//for(int y;y<1000;++y)
	cout << b <<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

