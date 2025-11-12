#include <iostream>
using namespace std;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	int sti[n], max=0;
	for(int i=0; i<3; i++){
		cin >> sti[i];
		if(sti[i] > max) max = sti[i];
	}
	if(sti[0] + sti[1] + sti[2] > max*2) cout << 1;
	else cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
