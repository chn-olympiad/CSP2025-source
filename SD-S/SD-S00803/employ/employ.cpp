#include<iostream>
#include<algorithm>
using namespace std;
const int N=505;
int n,m,ans;
char s[N];
int t[N],a[N],b[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>s+1;
	for(int i=1;i<=n;i++) cin>>a[i],b[i]=i;
	do{
		int c=0,res=0;
		for(int i=1;i<=n;i++){
			if(c>=a[b[i]]){
				c++;
				continue;
			}
			if(s[i]=='0') c++;
			else res++;
		}
		if(res>=m) ans++;
	}while(next_permutation(b+1,b+n+1));
	cout<<ans;
	return 0;
}
