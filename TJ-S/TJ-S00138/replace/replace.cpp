#include<bits/stdc++.h>
using namespace std;
const int N = 5e2 + 10;
int n, q;
string a, b, q1, q2;
string arr1[N], arr2[N];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> a >> b;
		arr1[i] = a;
		arr2[i] = b;
	}
	while (q){
		int sum = 0;
		bool flag = false;
		cin >> q1 >> q2;
		for (int i = 1; i <= n; i++){
			if (q1 == arr2[i] && q1 == q2){
				flag = true;
				sum++;
			}else if (q2 == arr1[i] && q1 == q2){
				flag = true;
				sum++;
			}else {
				flag = false;
			}
			if (flag == false){
				cout << "0" << endl;
				break;
			}else {
				cout << sum << endl;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
