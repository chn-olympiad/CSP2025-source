// 辅轮中学 淡楚懿 SN-J00692 
#include <bits/stdc++.h>
using namespace std;

int TTT = 1, n;
string p, s;

bool cmp(char x, char y) {return x > y;}

void mian()
{
	cin >> p;
	for(int i = 0; i < p.size(); i++)
		if(p[i] >= '0' && p[i] <= '9') s += p[i];
	sort(s.begin(), s.end(), cmp);
	cout << s;
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
//	cin >> TTT;
	while(TTT--) mian();
	return 0;
}
/* 
上联：T1T2易如反掌 
下联：T3T4简似呼吸 
横批：轻松AK 
*/
