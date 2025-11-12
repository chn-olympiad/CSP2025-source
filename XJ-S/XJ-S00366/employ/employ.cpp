#include<iostream>
#include<string.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,ans;
string s;
int a[N],vis[N],r[N];
void f(int now){
	if(now>n){
		int cnt=0,sum=0;
		for(int i=1;i<=n;i++){
			if(cnt<a[r[i]]&&s[i-1]=='1') sum++;
			else cnt++;
		}
		if(sum>=m) ans++;
		ans%=mod;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			r[now]=i;
			f(now+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdout);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
	    cin>>a[i];
	} 
    f(1);
    cout<<ans;
	return 0;
}
