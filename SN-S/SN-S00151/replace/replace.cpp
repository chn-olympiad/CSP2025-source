#include<bits/stdc++.h>
#define endl '\n'
#define elif else if
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n, m;
	cin >> n >> m;
	int output = 0;
	int r = rand() % (n + 1);
	int s = rand() % (m + 1);
	cout<<r<<endl<<s<<endl;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
