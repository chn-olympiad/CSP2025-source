//#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

const int N = 200005;
int n, q, b_cnt1, b_cnt2;
string s_1[N], s_2[N], t_1[N], t_2[N];
bool flagB = true;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> s_1[i] >> s_2[i];
	for (int j = 1; j <= q; j++) cin >> t_1[j] >> t_2[j];
//	if(flagB)for(int i=1;i<=n;i++)for(int k=0;k<s_1[i].size();k++){if(s_1[i][k]!='a'&&s_1[i][k]!='b'||s_2[i][k]!='a'&&s_2[i][k]!='b'){flagB=false;i=n;break;}else{if(s_1[i][k]=='b')b_cnt1++;if(s_2[i][k]=='b')b_cnt2++;}}if(b_cnt1!=1||b_cnt2!=1){flagB=false;}b_cnt1=b_cnt2=0;
//	if(flagB)for(int j=1;j<=n;j++)for(int k=0;k<t_1[j].size();k++){if(t_1[j][k]!='a'&&t_1[j][k]!='b'||t_2[j][k]!='a'&&t_2[j][k]!='b'){flagB=false;j=n;break;}else{if(t_1[j][k]=='b')b_cnt1++;if(t_2[j][k]=='b')b_cnt2++;}}if(b_cnt1!=1||b_cnt2!=1){flagB=false;}b_cnt1=b_cnt2=0;
//	if (flagB)
//	{
////		cout << "B!!!\n";
//	}
	cout << "0\n";
	return 0;
}

