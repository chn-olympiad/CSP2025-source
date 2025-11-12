#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int mod=998244353;
int n,m,c[505];
int num[505];
char s[505];
bool a[505];
int ans;
void cheat(int dep,int cnt,int fail){
	if(dep>n){
		if(cnt>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!a[i]){
			a[i]=1;
			if(fail>=c[i]) cheat(dep+1,cnt,fail+1);
			else{
				if(s[dep]=='0') fail++;
				else cnt++;
				cheat(dep+1,cnt,fail);
				if(s[dep]=='0') fail--;
				else cnt--;
			}
			a[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s+1;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=18) cheat(1,0,0);
	cout<<ans;
	return 0;
}
