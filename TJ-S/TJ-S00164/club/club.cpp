#include <bits/stdc++.h>
using namespace std;
int lover[10002][5];
//int teams[5]={0,0,0,0};
int dp(int i) {
	int max_love = 0;
	for (int j = 1;j <= 3;j++) { 
		if (lover[i][j] > max_love) {
			//if (teams[j] < 2) {
			max_love = lover[i][j];
				//teams[j]++;
				//cout << "Debug:apeend:" << teams[j] << ' ' << j << ' ' << lover[i][j] << ' ' << max_love << endl;
			//break;
			
		}
	}
	return max_love;
}
/*
int dp1(int i) {
	int max_love = 0; 
	if (lover[i] > max_love) {
		if (teams[j] < 2) {
			max_love = lover_1[i];
			teams[j]++;
			cout << "Debug:apeend:" << teams[j] << ' ' << j << ' ' << lover[i][j] << ' ' << max_love << endl;
			break;
		}
		else {
			cout << "Debug:now:" << lover[i][j] << endl;
			lover[i][j] = 0;
			cout << "Debug:finding_next:" << teams[j] << ' ' << j << ' ' << lover[i][j] << endl;
			max_love = dp(i);
		}
	}
}
	return max_love;
	//love += max_love;
}*/
int f() {
	int n;
	cin >> n;
	//cin >> lover_1[i] >> lover_2[i] >> lover_3[i];
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= 3;j++)
			cin >> lover[i][j];
	//sort(lover_1+1, lover_1+n+1, greater<int>());
	//sort(lover_2+1, lover_2+n+1, greater<int>());
	//sort(lover_3+1, lover_3+n+1, greater<int>());
	/*for (int i = 1;i <= n;i++) {
		cout << lover_1[i] << ' ' << lover_2[i] << ' ' << lover_3[i] << endl;
	}*/
	/*int love = 0;
	for (int i = 1;i <= n;i++) { 
		love += dp(i);
	}*/
	//return lover_1[1] + lover_1[2] + lover_2[1] + lover_2[2] + lover_3[1] + lover_3[2];
	int love = 0;
	for (int i = 1;i <= n;i++)
		love += dp(i);
	return love;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	cin >> t;
	for (int i = 1;i <= t;t++) {
		cout << f() << endl;
	}
	return 0;
}
