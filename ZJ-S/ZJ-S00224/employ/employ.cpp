#include <bits/stdc++.h>
#define fr1(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define md %998244353
using namespace std;
const int maxn=5e2+5;
int n,m,hito[maxn];
bool used[maxn];
string s;
long long ans=0;
void work(int i,int l) {
	if(i>n&&l<=n-m) {
		ans=(ans+1)md;
		return;
	} else {
		if(l>n-m){
		return;
		}
		fr1(j,1,n){
			if(used[j])continue;
			else 
			{
				used[j]=1;
				if(s[i-1]=='0'||hito[j]<=l)l++;
				work(i+1,l);
				used[j]=0;
				if(s[i-1]=='0'||hito[j]<=l)l--;
			}
		}
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	fr1(i,1,n)cin>>hito[i];
	work(1,0);
	cout<<ans;
	return 0;
}
