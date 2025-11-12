#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	s=" "+s;
	for(int i=1;i<s.size();++i){
		if(s[i]>='0'&&s[i]<='9'){
			++cnt[s[i]-'0'];
		}
	}
	for(int i=9;i>=0;--i){
		while(cnt[i]){
			--cnt[i];
			cout<<i;
		}
	}
/*
//freeopen
//freeopen
FUCK CCF FUCK!!!!

Fuck you dam
I love luogu
luogu
luogu
NOI
CCF
FUCK
FUCK
1145141919810
1145141919810
fclose
fclose
话说回来我是来诈骗的，预计得分400哦。
只花了赛时1h
显得没事就来诈骗了
哈哈哈哈哈哈
没想到吧
我的洛谷uid955696关注一下吧，球球了。
白遭殃的CCF
被我妈的体无完肤。
不管了，去别的地方骂吧。

我要让我的最后一题的代码最短！！！！！！！！！！！！！！！！！！！！！！！！！！！！ 
*/
}
