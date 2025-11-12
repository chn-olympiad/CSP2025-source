#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+100;
struct Node{
	string x,y;
};
Node pis[N],questions[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q; cin >> n >> q;
	for(int i = 1; i <= n; i++){
		string a,b; cin >> a >> b;
		Node news;
		news.x=a;news.y=b;
		pis[i]=news;
	}
	for(int i = 1; i <= q; i++){
		string a,b; cin >> a >> b;
		Node news;
		news.x=a;news.y=b;
		questions[i]=news;
	}
	for(int i = 1; i <= q; i++){
		string xx,yy;
		xx=questions[i].x;
		yy=questions[i].y;
		int cnt=0;
		for(int j = 1; j <= n; j++){
			int l=0;
			string sj1,sj2;
			sj1=pis[j].x;
			sj2=pis[j].y;
			string xxx=xx;
			while(xxx.find(sj1,l)!=-1){
				l=xxx.find(sj1,l);
				string a,b;
				a=xxx.substr(0,l);
				l+=sj1.size();
				b=xxx.substr(l);
				string ss=a+sj2+b;
//				cout << ss << '\n';
				if(ss==yy){
					cnt++;
					break;
				}
			}
		}
		cout << cnt << '\n';
	}
}
