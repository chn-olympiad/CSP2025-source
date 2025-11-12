// 王梓宇 SN-J00767 西安市曲江第二中学
#include <iostream>
#include <algorithm>
using namespace std;
string S;
int j = 1, ans = 0;
char a[1000001];
bool cmp(char x, char y)
{
	return x > y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	
	cin >> S;
	for (int i = 0;i < S.size();++i){
		char c = S[i];
		if (c >= 48 && c < 58){
			a[j] = c;
			ans++;
			++j;
		}
	}	
	sort(a + 1, a + ans + 1, cmp);
	for (int i = 1;i <= ans;i++)	
		cout << a[i];
	return 0;
}
