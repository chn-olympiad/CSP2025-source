#include<bits/stdc++.h>
#define int long long
using namespace std;
int b[1000010],x,f;
char a;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>a){
		if(a>='0'&&a<='9')b[++x]=a-'0';
	}sort(b+1,b+x+1);
	while(x){
		if(b[x]!=0)f=1;
		if(b[x]==0&&f==0){
			cout<<0;
			return 0;
		}
		cout<<b[x--];
	}
	return 0;
}
