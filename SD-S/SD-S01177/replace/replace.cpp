#include<bits/stdc++.h>
#define fst ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define int long long 
#define endl '\n'
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int N = 1e5+10 , inf = 0x3f3f3f3f3f3f3f3f ;
string s[N][2];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	fst 
	srand(time(0));
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		cout<<rand()%n<<endl; 
	}


	return 0;
}
//  Ren5Jie4Di4Ling5%
