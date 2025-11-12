#include <bits/stdc++.h>
using namespace std;

struct member{
	int like1, like2, like3;
	int id;
	bool add;
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int tmax = n / 2;
		int club1[n], club2[n], club3[n];
		int maxone[n];
		member mem[n];
		
		
		for(int i = 0; i < n; i++){
			mem[i].id = i;
			mem[i].add = false;
			cin >> mem[i].like1 >> mem[i].like2 >> mem[i].like3;
		}
		
		int max2 = 0;
		max2 = mem[0].like1 + mem[1].like2;
		max2 = max(max2, mem[0].like1 + mem[1].like3);
		max2 = max(max2, mem[0].like2 + mem[1].like3);
		max2 = max(max2, mem[0].like2 + mem[1].like1);
		max2 = max(max2, mem[0].like3 + mem[1].like1);
		max2 = max(max2, mem[0].like3 + mem[1].like2);
		cout << max2 << endl;
	} 
	
	return 0;
}
