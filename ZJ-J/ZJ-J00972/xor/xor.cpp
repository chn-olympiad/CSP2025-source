#include<bits/stdc++.h>
#define ll long long
#define forr(a, b, k) for (int i = (a); i <= (b); i += (k))
using namespace std;
const int N = 5e5 + 10;
struct node{
	int l, r;
	bool flag;
	int qwe;
}op[N];
int T;
int n, r;
int a[N];
int ans = 0;
int cc[N];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> r;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cc[a[i]]++;
	}
	if(r == 1 || r == 0) {
		if(r == 1)
		{
			cout << cc[1];
		}else{
			cout << cc[1] / 2;
		}
		return 0;
	}
	int i = 1, j = 1;
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		int j = i;
		for (; j <= n; j++)
		{
			sum ^= a[j];
			if(sum == r)
			{
				break;
			}
		}
		if(sum == r)
		{
//			cout << i << " " << j << "\n";
//			cout << '\n';
			bool po = false;
			node p;
			for (int k = i; k <= j; k++) if(op[k].flag == true) {
				po = true;
				p = op[k];
				break;
			}
			if(p.r - p.l + 1 > j - i + 1) 
			{
//				cerr << "op";
				for (int k = p.l ; k <= p.r; k++) op[k].flag = false, op[k].l = op[k].l = k;
				for (int k = i; k <= j; k++) {
					op[k].flag = true;
					op[k].l = i;
					op[k].r = j;
					op[k].qwe = 0;
				}
			} else if(!po){
				for (int k = i; k <= j; k++) {
					op[k].flag = true;
					op[k].l = i;
					op[k].r = j;
					op[k].qwe = 0;
				}
				ans++;
			}
			
//			for (int k = 1; k <= n; k++) cout << (op[k].flag == true ? 1 : 0) << " ";
		}
	}
	cout << ans << '\n';
}

