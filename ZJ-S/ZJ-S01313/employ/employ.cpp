#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long a[15],n,m,c[1005],ans;
char str[1000005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>str+1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=10){
		for(int i=1;i<=n;i++){
			a[i]=i;
		}
		do{
			int x=0,y=0;
			for(int i=1;i<=n;i++){
				if(str[i]=='0'||c[a[i]]<=x){
					x++;
				}
				else{
					y++;
				}
			}
			if(y>=m){
				ans++;
			}
		}while(next_permutation(a+1,a+1+n));
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
}
//chzx_lfw AKIOI!!!!!
