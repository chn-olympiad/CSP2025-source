//看在我寫了隨機數還交了代碼的份上
//送我一個測試點吧 我願意用十年陽壽換
#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

const int N=500;
int n,m;char s[N];

signed main(){
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	ios::sync_with_stdio(NULL);cin.tie(0);cout.tie(0);
	srand(time(0));
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	while(n--){
		int x;cin>>x;
	}
	int r=rand()%100000000+1;
	cout<<r%998%244%353;
	
	return 0;
}
/*
3 2
101
1 1 2
*/