#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	for(;c>'9'||c<'0';c=getchar())if(c=='-')f=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
vector<int>v;
signed main(){
	v.push_back(1);v.push_back(2);v.push_back(3);
	v.pop_back();
	for(auto e:v)cout<<e<<" ";
	return 0;
}
