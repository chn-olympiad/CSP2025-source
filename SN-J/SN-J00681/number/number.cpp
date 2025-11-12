#include <bits/stdc++.h>
#define int long long
using namespace std;
#include <list>
char n[1000005];
list<int>l1;
int s;

signed main() {
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin >> n;
	for(int i = 0; i < 1000005; i++)
	{
		if(n[i] == 1 || n[i] == 2 || n[i] == 3 || n[i] == 4 || n[i] == 5 || n[i] == 6 || n[i] == 7 || n[i] == 8 || n[i] ==9 || n[i] == 0)
		{
			l1.push_back(n[i]);
		}	
	}
	s = l1.size();
	sort(l1.begin(), l1.end());
	for(int j = 0; j <= s; j++)
	{
		cout << l1[j];
	} 
	return 0;
}
