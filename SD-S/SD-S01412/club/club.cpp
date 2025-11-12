#include<bits/stdc++.h>
#define int long long
#define mid n/2
#define g() getchar()
using namespace std;
const int N=1e5+19;
int aa[N][4];
int n;
int maxx=-11;
void solve(int i,int num,int a,int b,int c){
	if(i==n+1){
		maxx=max(maxx,num);
		return ;
	}
	if(a<mid)solve(i+1,num+aa[i][1],a+1,b,c);
	if(b<mid)solve(i+1,num+aa[i][2],a,b+1,c);
	if(c<mid)solve(i+1,num+aa[i][3],a,b,c+1);
}
signed main(){
	ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		maxx=-11;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>aa[i][1]>>aa[i][2]>>aa[i][3];
		}
		solve(1,0,0,0,0);
		cout<<maxx<<endl;
	}
	return 0;
}

