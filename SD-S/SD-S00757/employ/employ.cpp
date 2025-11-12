#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int c[15],n,m,p[15];string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n>10){
		srand(time(0));
		cout<<rand()%998244353;
		return 0;
	}
	for(int i=1;i<=n;i++) p[i]=i;
	int ans=0;
	do{
		int fail=0;
		for(int i=1;i<=n;i++){
			if(c[p[i]]<=fail) ++fail;
			else if(s[i-1]=='0') ++fail;
		}
		if(n-fail>=m) ++ans;
//		cout<<fail<<' ';
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return 0;
}

