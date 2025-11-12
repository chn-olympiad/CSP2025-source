#include <bits/stdc++.h>
using namespace std;

const int mx = 21000;

int t, k = 0, ans = 0, s1 = 0, s2 = 0, s3 = 0, y[mx], e[mx], s[mx];
long long n, flag = 0;

struct man {
	long long yi, er, san, shu, biao;
} a[mx], ma[mx], bi[mx];

bool cmp(man x, man z) {
	return x.shu > z.shu;
}
int b[mx], cnt;

void work(int i) {
	ans = 0;
	if (bi[i].yi == 1) {
//				for(int j=1;j<=y.size();++j)
//				{
//					if(y[j]==1)
//						cnt+=ma[j].yi;
//					if(y[j]==2)
//						cnt+=ma[j].er;
//					if(y[j]==3)
//						cnt+=ma[j].san;
//				}
//				if(cnt)
//				{
//					s1++;
//					y[l]=bi[i].yi;
//				}
		s1++;
		if (s1 > n / 2) {
			//cout << "A";
			if (bi[i].er == 2) {
				s2++;
				if (s2 > n / 2) {
					s3++;
					ans += ma[i].san;
				} else
					ans += ma[i].er;
			}
			if (bi[i].er == 3) {
				s3++;
				if (s3 > n / 2) {
					s2++;
					ans += ma[i].san;
				} else
					ans += ma[i].er;
			}
		} else
			ans += ma[i].yi;
	}
	if (bi[i].yi == 2) {
		s2++;
		if (s2 > n / 2) {
			//cout << "A";
			if (bi[i].er == 1) {
				s1++;
				if (s1 > n / 2) {
					s3++;
					ans += ma[i].san;
				} else
					ans += ma[i].er;
			}
			if (bi[i].er == 3) {
				s3++;
				if (s3 > n / 2) {
					s1++;
					ans += ma[i].san;
				} else
					ans += ma[i].er;
			}
		} else
			ans += ma[i].yi;
	}
	if (bi[i].yi == 3) {
		s3++;
		if (s3 > n / 2) {
			//cout << "A";
			if (bi[i].er == 2) {
				s2++;
				if (s2 > n / 2) {
					s1++;
					ans += ma[i].san;
				} else
					ans += ma[i].er;
			}
			if (bi[i].er == 1) {
				s1++;
				if (s1 > n / 2) {
					s2++;
					ans += ma[i].san;
				} else
					ans += ma[i].er;
			}
		} else
			ans += ma[i].yi;
	}

}

void xu() {

}


int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			memset(a, 0, sizeof a);
			cin >> a[1].shu >> a[2].shu >> a[3].shu;
			a[1].biao = 1;
			a[2].biao = 2;
			a[3].biao = 3;
			sort(a + 1, a + 3 + 1, cmp);
			bi[i].yi = a[1].biao;
			bi[i].er = a[2].biao;
			bi[i].san = a[3].biao;
			ma[i].yi = a[1].shu;
			ma[i].er = a[2].shu;
			ma[i].san = a[3].shu;
//			cout << ma[1].shu << ma[2].shu << ma[3].shu;
//			cout << bi[i].yi << bi[i].er << bi[i].san;
			work(i);
			cnt += ans;
			k = max(cnt, k);
//			swap(bi[i].yi, bi[i].er);
//			swap(ma[i].yi, ma[i].er);
//			work(i);
//			k = max(cnt, k);

//
//
//
//			work(i);
//			cnt = 0;
//			cnt += ans;
//			swap(bi[i].yi, bi[i].san);
//			swap(ma[i].yi, ma[i].san);
//			k = max(cnt, k);
//			work(i);
//			cnt += ans;
//			swap(bi[i].er, bi[i].san);
//			swap(ma[i].er, ma[i].san);
//			k = max(cnt, k);
//			work(i);
//			cnt += ans;
//			swap(bi[i].yi, bi[i].san);
//			swap(ma[i].yi, ma[i].san);
//			k = max(cnt, k);
//			work(i);
//			cnt += ans;
//			swap(bi[i].er, bi[i].san);
//			swap(ma[i].er, ma[i].san);
//			k = max(cnt, k);
//			work(i);
//			cnt += ans;
//			swap(bi[i].yi, bi[i].san);
//			swap(ma[i].yi, ma[i].san);
//			k = max(cnt, k);
		}


	}
	cout << k << "\n";
	return 0;
}


