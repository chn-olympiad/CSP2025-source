#include <bits/stdc++.h>
#define pii pair<int,int>
#define fir first
#define sec second
#define IO ios::sync_with_stdio(0);cin.tie(0);
//#define int long long
#define clr(x) memset(x,0,sizeof(x))
#define cmax(x) memset(x,0x3f,sizeof(x))
#define inf 0x3f3f3f3f3f3f3f3fll
#define INF 0x3f3f3f3f
#define finf -0x3f3f3f3f
#define ls (x << 1)
#define rs ((x << 1) | 1)
#define mid ((l + r) >> 1)
#define maxn 1000010
#define lowbit(x) (x & (-x))
//#define mod 998244353
#define ll long long
#define endl '\n'
using namespace std;
string s;
ll a[maxn],top = 0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(auto y : s){
		if(isdigit(y)){
			a[++top] = y - '0';
		}
	}
	sort(a + 1,a + top + 1);
	for(int i = top;i >= 1;i--){
		cout << a[i];
	}
	cout << endl;
	return 0;
}
