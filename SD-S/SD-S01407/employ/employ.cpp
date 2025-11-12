#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,m;
string s;
int a[510];
int cnt,cnt1,ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='1') cnt++;
	}
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]==0){
			cnt1++;
		}
	}
	if(cnt==len){
		int m=n-cnt1;
		int x=1,y=1; 
		for(int i=m+1;i<=n;i++){
			x*=i;
			x%=N;
		}
		for(int i=2;i<=n-m;i++){
			y*=i;
			y%=N;
		}
		ans=x/y;
		cout << ans;
	}else{
		cout << 0;
	}
	return 0;
} 
