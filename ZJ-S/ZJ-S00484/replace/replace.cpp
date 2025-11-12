#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=b;i++)
#define UF(i,a,b) for(int i=a;i>=b;i--)
#define look_memory cerr<<abs(&M2-&M1)/1024.0/1024<<'\n'
#define look_time cerr<<(clock()-Time)*1.0/CLOCKS_PER_SEC<<'\n'
using namespace std;
#define LL long long
bool M1;
const int N=2e5+100;
const int M=5e6+100;
int n,q;
namespace Sub_A{
	const int MAXN=1010;
	string s1[MAXN],s2[MAXN];
	void solve_A(){
		for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
		while(q--){
			int res=0;
			string ss1,ss2;
			cin>>ss1>>ss2;
			for(int i=1;i<=n;i++){
				
			}
		}
	}
}
void solve(){
	cin>>n>>q;
	if(n<=1000&&q<=2000){
		Sub_A::solve_A();
	}
}
bool M2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int Time=clock();
	int T=1;
//  cin>>T;
	while(T--){
		solve();
	}
	look_memory;
	look_time;
	return 0;
}
