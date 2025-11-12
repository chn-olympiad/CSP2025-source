#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 200;
int a[N] , vis[N];
int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	int n , k;
	cin >> n >> k;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}	
	int c = 0;
	for(int i = 1; i <= n; i ++){
		int s = 0;
		if(vis[i]){
			//cout << "///////////////////////////////" << endl;
			continue;
		}
		for(int j = i; j <= n; j ++){
			//if(vis[j]){
				//cout << "****************" << endl;
				//;
			//}
			if(i == j) s = a[i];
			else {
				s = s ^ a[j];
			}
			//cout << i << " " << j << " " << s << " " <<a[i] << endl;
			if(s == k){
				for(int k = i; k <= j; k ++){
					vis[k] = 1;
					//cout << k << " ";
				}
				cout << endl;
				c ++;
				break;
				//cout << i << " " << j << " " << s << " " << " "<< c << " " << endl;
			}
		}
	}
	cout << c;
	return 0;
}
