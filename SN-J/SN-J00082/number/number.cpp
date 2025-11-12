#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,o,n) for(int i = o;i <= n;i++)
#define dep(i,o,n) for(int i = o;i >= n;i--)
#define mem(x,p) memset(x,p,sizeof x)

char c;
int a[10];

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	while(cin>>c){
		if('0'<=c&&c<='9'){
			a[c-'0']++;
		}
	}
	int f=1;
	dep(i,9,0){
		if(i==0&&f){
			putchar('0');
			return 0;
		}
		rep(j,1,a[i]) putchar(i+'0');
		if(a[i]) f=0;
	}
}

