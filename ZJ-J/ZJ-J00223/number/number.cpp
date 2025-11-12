#include<bits/stdc++.h>
//#define int long long
using namespace std;//I LOVE CCF
inline int read() {//I LOVE CCF
	int x=0,f=1;//I LOVE CCF
	char c=getchar();//I LOVE CCF
	while(c<'0'||c>'9') {//I LOVE CCF
		if(c=='-')f=-1;//I LOVE CCF
		c=getchar();//I LOVE CCF
	}//I LOVE CCF
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();//I LOVE CCF
	return x*f;//I LOVE CCF
}//I LOVE CCF
int t[10];//I LOVE CCF
signed main() {//I LOVE CCF
	freopen("number.in","r",stdin);//I LOVE CCF
	freopen("number.out","w",stdout);//I LOVE CCF
	string s;//I LOVE CCF
	cin>>s;//I LOVE CCF
	for(int i=0; i<s.size(); i++) {//I LOVE CCF
		if(s[i]>='0'&&s[i]<='9')t[s[i]-'0']++;//I LOVE CCF
	}//I LOVE CCF
	for(int i=9; i>=0; i--) {//I LOVE CCF
		while(t[i]) {//I LOVE CCF
			cout<<i;//I LOVE CCF
			t[i]--;//I LOVE CCF
		}//I LOVE CCF
	}//I LOVE CCF
	return 0;//I LOVE CCF
}//I LOVE CCF
