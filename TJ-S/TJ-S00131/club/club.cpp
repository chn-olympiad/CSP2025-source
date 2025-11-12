#include <bits/stdc++.h>
using namespace std;
const int nu = 1e5;
int manx(int a, int b) {
	if (a > b) return a;
	return b;
}
int mnin(int a, int b) {
	if (a < b) return a;
	return b;
}
int main() {
	freopem("club.in", "r", stdin);
	freopem("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		vector<int> ad; //a地址 
		vector<int> bd; //b地址 
		vector<int> cd; //c地址 
		int sum[3*n], al = 0, bl = 0, cl = 0;//总an
		int a0 = 0, a1 = 0, a2 = 0;//人数 
		vector<int> np;
		if (n == nu) {
			for (int j = 0; j < n; j++) {
				vector<int> an(n);
				int maxn = 0;
				cin >> an[0] >> an[1] >> an[2];
				maxn = an[0];
				ad.push_back(maxn);
				al++;
				a0 += maxn;
				if (al > (n/2)) {
					al--;
					int minn = ad[0];
					int pp = 0;
					bool flag = true;
					for (int p = 0; p < ad.size(); p++) {
						for (int kk = 0; kk < np.size(); kk++) {if (p == np[kk]) flag = false;}
						if ((ad[p] < minn) && flag) {
							minn = ad[p]; pp = p;
						}
						flag = true;
					}
					a0 -= minn;
					np.push_back(pp);
				}
			}cout << a0 << "\n";
		}
		else {
		for (int j = 0; j < n; j++) {
			vector<int> an(n);
			int maxn = 0;
			cin >> an[0] >> an[1] >> an[2];
			sum[0+j*3] = an[0]; sum[2+j*3] = an[2]; sum[1+j*3] = an[1];
			maxn = manx(manx(an[0], an[1]), an[2]);
			if (maxn == an[0]) {
				ad.push_back(j);
				al++;
				if (al > (n / 2)) {
					int minn = ad[0];
					al--;
					//an[0] = 0;
					maxn = manx(an[1], an[2]);
					if (maxn == an[1]) {
						bd.push_back(j);bl++; 
						if (bl > (n/2)) {bl--;cd.push_back(j);cl++;a2 += an[2];}
						else a1 += an[1];
					}
					else {
						cd.push_back(j);cl++;
						if (cl > (n/2)) {cl--;bd.push_back(j);bl++;a1 += an[1];}
						else a2 += an[2];
					}
				}
				else a0 += an[0];
			}
			else if (maxn == an[1]) {
				bd.push_back(j);
				bl++;
				if (bl > (n / 2)) {
					bl--;
					//an[1] = 0;
					maxn = manx(an[0], an[2]);
					if (maxn == an[0]) {
						ad.push_back(j);al++;
						if (al > (n/2)) {al--;cd.push_back(j);cl++;a2 += an[2];}
						else a0 += an[0];
					}
					else {
						cd.push_back(j);cl++;
						if (cl > (n/2)) {cl--;ad.push_back(j);al++;a0 += an[0];}
						else a2 += an[2];
					}
				}
				else a1 += an[1];
			}
			else if (maxn == an[2]) {
				cd.push_back(j);
				al++;
				if (cl > (n / 2)) {
					cl--;
					//an[2] = 0;
					maxn = manx(an[1], an[0]);
					if (maxn == an[1]) {
						bd.push_back(j);bl++;
						if (bl > (n/2)) {bl--;ad.push_back(j);al++;a0 += an[0];}
						else a1 += an[1];
					}
					else {
						ad.push_back(j);al++;
						if (al > (n/2)) {al--;bd.push_back(j);bl++;a1 += an[1];}
						else a0 += an[0];
					}
				}
				else a2 += an[2];
			}
			//abc += maxn;
		}
		cout << a0+a1+a2 << "\n";}
	}
	return 0;
}
