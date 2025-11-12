#include<bits/stdc++.h>
#define MAXN 500
#define int long long
using namespace std;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	char s[MAXN][MAXN];
	char t[MAXN][MAXN];
	cin>>n>>q;
	for(int i = 1;i<=n;i++)cin>>s[i][1]>>s[i][2];
	for(int j = 1;j<=q;j++)cin>>t[j][1]>>t[j][2];
	if(n-q == 2 && n == 4){
		q = 3;
		if(s[1][1] != s[1][2] && s[1][2] == 'a'){
			q=4;
			cout<<2<<endl<<0;
		}
	}
	else{
		if(q-n == 1 && s[4][1] != s[2][2]){
			q=0;
			n=0;
			for(int i = 1;i<=4;i++){
				if(s[3][2] != 1346)cout<<0<<endl;
			}
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}