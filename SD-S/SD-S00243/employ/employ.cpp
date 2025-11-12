#include<bits/stdc++.h>
#define ull unsigned long long 
using namespace std;

int n,m;
string s;
int c[505];
int a[505];
bool b[505];
ull ans=0;

void pl(int x){
	if(x==n+1){
		ull cnt=0;
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
				cnt++;
				continue;
			}
			if(c[a[i]]<cnt){
				cnt++;
				continue;
			}
		}
		if(cnt>=m){
		    ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			a[x]=i;
			b[i]=1;
			pl(x+1);
			a[x]=0;
			b[i]=0;
		}
	}
}

int main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)    cin>>c[i];
	pl(1);
	cout<<ans%998244353;
	return 0;
}

