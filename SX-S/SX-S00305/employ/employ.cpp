#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn=1000;
const int modz=998244353;
int n,m;
int test[maxn];
int u=0;
int per[maxn];
long long ans=1;
string str;
int main() {
	
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>str;
	for(int i=0;i<n;i++){
		if(str[i]=='1'){
			u++;
		} 
	}
	if(u==n){
		for(int i=n;i>=1;i--){
			ans=((ans*(i%modz)+modz)%modz+modz)%modz;
		}
		
	}
	cout<<ans<<endl;

	return 0;
}
