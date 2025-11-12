#include<bits/stdc++.h>
using namespace std;

struct zuowei {
	int sc;
	bool yes = 0;
};

zuowei zuoweis[105];

bool cmp(zuowei a,zuowei b) {
	return a.sc > b.sc;
}

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) {
		cin >> zuoweis[i].sc;
		zuoweis[i].yes=0;
	}
	zuoweis[1].yes=1;
	sort(zuoweis+1,zuoweis+n*m+1,cmp);
	int liea = 1, hanga = 1, pai = 1;
	bool xia = 1;
	while(zuoweis[pai].yes != 1) {
		if(xia) {
			if(hanga + 1 <= n) {
				hanga++;
			} else {
				xia = 0;
				liea++;
			}
		}
		else {
			if(hanga - 1 >= 1) {
				hanga--;
			} else {
				xia = 1;
				liea++;
			}
		}
		pai++;
	}
	cout << liea << ' ' << hanga;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}