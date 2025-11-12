#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[1000010],tot;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	s=' '+s;
	int n=s.size();
	for(int i=1;i<=n;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[++tot]=s[i]-'0';
		}
	}
	sort(a+1,a+1+tot,cmp);
	if(a[1]==0) cout<<0;
	else{
		for(int i=1;i<=tot;i++){
			cout<<a[i];
		}
	}
	return 0;
}
