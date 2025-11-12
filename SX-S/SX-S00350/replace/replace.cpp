#include <bits/stdc++.h>
using namespace std;

struct w
{
	string st1,st2;
}a1[200100],a2[200100];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);
	cout.tie(nullptr);
	int q,n;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a1[i].st1>>a1[i].st2;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>a2[i].st1>>a2[i].st2;
	}
	return 0;
}
