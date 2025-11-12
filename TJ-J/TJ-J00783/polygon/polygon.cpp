#include<bits/stdc++.h>
using namespace std;
int n;
long long  sum;
struct a {
	int v;
};
a num [5005];
bool cmp (a x,a  y ) {
	return x.v > y.v;

}
a fen[5005];
int fensum1,fensum2;
int main () {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> num[i].v;
	}
	sort(num,num+n,cmp);

//	for (int i=1; i<n; i++) {
//		fensum=0;
//		for (int j=0; j<i; j++) {
//			fen[j].v=num[j].v;
//			fensum+=fen[j].v;
//		}
//		sort(fen,fen+i,cmp);
//		int max = fen[0].v;
//		if (fensum>max*2) {
//			sum++;
//		}
//	}
	for (int i=1; i<=n; i++) {
		for (int j=0; j<i; j++) {
			fensum1=0;
			for (int k=j; k<=i; k++) {
				fen[k].v=num[k].v;
				fensum1+=fen[k].v;
				fensum2++;
			}
			sort(fen,fen+i,cmp);
			int max = fen[0].v;
			if (fensum1>max*2&&fensum2>=3) {
				sum++;
			}
		}
	}
	cout << sum+n%998244353;
	return 0;
}
