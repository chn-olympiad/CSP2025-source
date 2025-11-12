#include <bits/stdc++.h>
using namespace std;

#define int long long

char s;
int a[10];
string cnt;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>s){
		if(s>='0'&&s<='9'){
			a[s-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(;a[i]>0;a[i]--){
			cnt+=(char)(i+'0');
		}
	}
	cout<<cnt;
	return 0;
}

