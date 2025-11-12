#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

const int N = 100000;

int n,m;
string s;
int c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i ++ ) cin >> c[i]; 
	sort(c + 1,c + 1 + n);
	
	int ans = 0;
	for(int i = 1; i <= n; i ++){
		if(c[i] != c[i - 1]) ans ++; 
	}
	
	cout << ans << endl;
	return 0;
}
 
