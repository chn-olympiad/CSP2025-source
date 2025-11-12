/*luogu@Nahia uid:1199153
Genshin Impact uid:289015817
I love Nahida forever!*/
//中间忘了 
//暴力：疑似40pts 
#include<bits/stdc++.h>
#define ll long long
#define pii pair<string,string>
#define For(i,a,b) for(int i = a;i<=b;i++)
using namespace std;
pii a[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	For(i,1,n){
		string s,e;
		cin>>s>>e;
		a[i].first = s;
		a[i].second = e;
	}
	while(q--){
		ll ans = 0;
		string s,e;
		cin>>s>>e;
		if(s.size()!=e.size()){
			cout<<"0\n";
			continue;
		}
		For(i,1,n){
			int t = s.find(a[i].first);
			int t1 = e.find(a[i].second);
			if(t==t1&&t<s.size()){
				string q = s.substr(0,t);
				q+=a[i].second;
				q+=s.substr(t+(int)a[i].second.size());
				if(q==e) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*情字何解 怎落笔都不对 而我独缺 你一生的了解*/
/*我遇见谁 会有怎样的对白 我等的人 她在多远的未来 我听见风 来自地铁和人海 我排着队 拿着爱的号码牌*/
/*注：她指OI 
"要走啦"
"嗯"
"这个给你。"我把一块U盘递给了她。
"里面是什么？"
"所有WA掉的代码，所有超时的梦想。"
但事实上，里面只有一句话：我遇见你，是最美丽的意外。这一句，可抵千言万语。 
我噙着泪，向她挥手道别。她那灿烂的笑还留在脸上，也永远印在了我的心里。
（都给我去看我的AFO记！！！ 
*/ 
