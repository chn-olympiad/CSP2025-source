#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll st[100];
void solve(){
	string s;
	cin>>s;
	ll n=s.size();
	for(ll i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			st[s[i]-'0']++;
		}
	}
	string ans="";
	for(ll i=9;i>=0;i--){
		while(st[i]>0){
			st[i]--;
			ans+=(char)(i+'0');
		}
	}
	cout<<ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	solve();
	return 0;
}
/*
	csp-j 2025 游记
	感觉今年的题都比较简单...
	本以为一小时能拿300pts
	谁知道一小时ak...
	剩下时间做甚么呢？
	于是写篇游记，纪念我不(bushi)平凡的三年 oi 生涯
	从五年级开始学，一直很平凡
	甚至学了1年初赛都过不了
	第二年拼尽全力无法战胜小木棍，但仍喜提 1=
	s组确实很有强度，拼尽全力 2=
	这是第三年：
	经过一年初二，个人感觉思维快速提升
	经过50场ABC的历练，我已成长为切(水题)能手
	可每次遇到计数题都无法战胜
	e.g.有一次ABC C放了一道简单计数，我做了将近半小时，快乐掉大分...
	j组这次逆序开题
	看到T4 我的心情不必多说
	我回想起我加练的哪些计数题
	回想起无数个奋战调题直到12pm 的深夜
	难道今天还要继续输吗？
	不可能！
	冥冥中：脑海不自觉传来一个声音：正难则反
	终于切了！ 
*/
