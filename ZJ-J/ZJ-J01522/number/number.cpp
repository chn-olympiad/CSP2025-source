#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int top,b[N];
string s;

bool cmp(int a,int b){
	return a>b;
}

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') b[++top]=0;
		else if(s[i]=='1') b[++top]=1;
		else if(s[i]=='2') b[++top]=2;
		else if(s[i]=='3') b[++top]=3;
		else if(s[i]=='4') b[++top]=4;
		else if(s[i]=='5') b[++top]=5;
		else if(s[i]=='6') b[++top]=6;
		else if(s[i]=='7') b[++top]=7;
		else if(s[i]=='8') b[++top]=8;
		else if(s[i]=='9') b[++top]=9;
	}
	sort(b+1,b+top+1,cmp);
	for(int i=1;i<=top;i++){
		cout<<b[i];
	}
	return 0;
}