#include<bits/stdc++.h>
#define int long long
#define inf (int)0x3f3f3f3f3f3f3f3f
#define sup (int)0xc0c0c0c0c0c0c0c0
#define pro (string)"number"

using namespace std;
const int e=1e6+10;

char s[e];
int a[e],top;

void file_read();

void solve(){
	for(int i=1;s[i]!='\0';i++)
		if('0'<=s[i]&&s[i]<='9')
			a[++top]=s[i]-'0';
	
	sort(a+1,a+top+1,greater<int>());
	
	return;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	file_read();
	
	cin>>s+1;
	
	solve();
	
	if(a[1]==0){
		cout<<"0\n";
		return 0;
	}
	for(int i=1;i<=top;i++)
		cout<<a[i];
	cout<<'\n';

	return 0;
}

void file_read(){
	#ifdef pro
	freopen((pro+".in").c_str(),"r",stdin);
	freopen((pro+".out").c_str(),"w",stdout);
	#endif

	return;
}

