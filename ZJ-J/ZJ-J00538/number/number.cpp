#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
#define endl "\n"
#define N -114514
#define int long long
#define MAX 1145141919810 
#define TXYAKIOI 7891
using namespace std;
string a;
int xx[30];
inline void Enchanted(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>a;
	rep(i,0,a.size()-1)
		if('0'<=a[i]&&'9'>=a[i])++xx[a[i]-'0'];
	dep(i,9,0)
		rep(j,1,xx[i])
			cout<<i;
}
signed main(){Enchanted();return 0;}
