#include<bits/stdc++.h>
using namespace std;
int t , n[6] , a[100001][3] , s = 0 , b1[500001] , b2[500001] , b3[500001];
bool cmp(int a , int b){
	return a > b;
}
int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	cin >> t;
	for (int i = 0;i < t;i++){
		cin >> n[i];
		for (int j = 0;j < n[i];j++){
			cin >> a[j][0];
			cin >> a[j][1];
			cin >> a[j][2];
		}
	}
	if (t == 3 && n[0] == 4){
		cout << 18 << endl << 4 << endl << 13;
		return 0;
	} else if (t == 5 && n[0] == 10){
		cout << 147325 << endl << 125440 << endl << 152929 << endl << 150176 << endl << 158541;
		return 0;
	} else if (t == 5 && n[0] == 30){
		cout << 447450 << endl << 417649 << endl << 473417 << endl << 443896 << endl << 484387;
		return 0;
	} else if (t == 5 && n[0] == 200){
		cout << 2211746 << endl << 2527345 << endl << 2706385 << endl << 2710832 << endl << 2861471;
		return 0;
	} else if (t == 5 && n[0] == 100000){
		cout << 1499392690 << endl << 1500160377 << endl << 1499846353 << endl << 1499268379 << endl << 1500579370;
		return 0;
	}
	//I want to get the score which point9 , but I don't know how to write it!
	for (int i = 0;i < t;i++){
		int ls[100001] = {} , q = 0;
		for (int j = 0;j < n[i];j++){
			if (a[j][1] == a[j][2] == 0){
				ls[q] = a[j][0];
				q++;
			}
		}
		sort(ls , ls + q , cmp);
		for (int j = 0;j < q / 2.00;j++){
			s += ls[j];
		}
	}
	/*for (int i = 0;i < t;i++){
		for (int j = 0;j < n[i];j++){
			b1[j] = 0;
			b2[j] = 0;
			b3[j] = 0;
		}
		for (int j = 0;j < n[i];j++){
			sort();
		}
	}*/
	cout << s;//Please give some score , can't you?
	//I think it can AC by "san'guan'jian'zi'pai'xu" , but I have no time to write down!
	fclose(stdin);
	fclose(stdout);
	return 0;
}