#include<bits/stdc++.h>
using namespace std;
#define int64 long long
vector<char> v;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(1){
		char c;
		c=getchar();
		if((c<'0'||c>'9')&&(c<'a'||c>'z'))break;
		if(c>='0'&&c<='9')v.push_back(c);
	}
	sort(v.begin(),v.end(),greater<char>());
	int siz=v.size();
	for(int i=0;i<siz;++i){
		putchar(v[i]);
	}
	putchar('\n');
	return 0;
}
// chaotic code -> UNchaotic code Pls!
// No Cang Jie?
// This Program : 100pts