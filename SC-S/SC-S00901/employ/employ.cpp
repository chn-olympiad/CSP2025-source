#include<bits/stdc++.h>
#define M 998244353
using namespace std;
int n,m,a[505];
long long t=1;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i) cin>>a[i];
	if(m==1){
		if(s[0]=='1'){
			while(n>0) t=(t*(n--))%M;
			cout<<t;
		}
		else{
			int x=0;
			for(int i=1;i<=n;++i)
				if(a[i]==0) x++;
			for(int i=n-1;i;--i) t=(t*i)%M;
			cout<<(t*(n-x))%M;
		}
	}
	else{
		while(n>0) t=(t*(n--))%M;
		cout<<t;
	}
	return 0;
}