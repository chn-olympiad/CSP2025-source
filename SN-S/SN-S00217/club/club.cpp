#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 100000;
struct Member
{
	int a[3];
	int l;
} A[N + 17];
vector<int> B[3];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> A[i].a[0] >> A[i].a[1] >> A[i].a[2];
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			ans += max({A[i].a[0], A[i].a[1], A[i].a[2]});
			if (A[i].a[0] >= max(A[i].a[1], A[i].a[2]))
			{
				B[0].push_back(i);
				A[i].l = A[i].a[0] - max(A[i].a[1], A[i].a[2]);
			}
			else if (A[i].a[1] >= max(A[i].a[2], A[i].a[0]))
			{
				B[1].push_back(i);
				A[i].l = A[i].a[1] - max(A[i].a[2], A[i].a[0]);
			}
			else if (A[i].a[2] >= max(A[i].a[0], A[i].a[1]))
			{
				B[2].push_back(i);
				A[i].l = A[i].a[2] - max(A[i].a[0], A[i].a[1]);
			}
		}
		int p = -1;
		for (int i = 0; i < 3; i++)
			if (int(B[i].size()) > n / 2) p = i;
		if (p != -1)
		{
			sort(B[p].begin(), B[p].end(), [](int a, int b){ return A[a].l < A[b].l; });
			int k = int(B[p].size()) - n / 2;
			for (int i = 0; i < k; i++)
				ans -= A[B[p][i]].l;
		}
		cout << ans << endl;
		for (int i = 0; i < 3; i++) B[i].clear();
	}
	return 0;
}
