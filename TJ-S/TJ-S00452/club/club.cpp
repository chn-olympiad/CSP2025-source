#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+7;
int n;
struct Node{
	int a;
	int b;
	int c;
};
Node s[N];
int T;
bool cmpa(int i,int j){
	return abs(s[i].a-max(s[i].b,s[i].c))<abs(s[j].a-max(s[j].b,s[j].c));
}
bool cmpb(int i,int j){
	return abs(s[i].b-max(s[i].a,s[i].c))<abs(s[j].b-max(s[j].a,s[j].c));
}
bool cmpc(int i,int j){
	return abs(s[i].c-max(s[i].b,s[i].a))<abs(s[j].c-max(s[j].b,s[j].a));
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		vector<int> a;
		vector<int> b;
		vector<int> c;
		for(int i=1;i<=n;++i){
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].a>=s[i].b && s[i].a>=s[i].c){
				a.push_back(i);
			}
			else if(s[i].b>=s[i].a && s[i].b>=s[i].c){
				b.push_back(i);
			}
			else{
				c.push_back(i);
			}
		}
		sort(a.begin(),a.end(),cmpa);
		sort(b.begin(),b.end(),cmpb);
		sort(c.begin(),c.end(),cmpc);
		if(a.size()>(n/2)){
			for(int i=0;i<a.size()-(n>>1);++i){
				if(s[a[i]].b>s[a[i]].c){
					b.push_back(a[i]);
				}
				else{
					c.push_back(a[i]);
				}
			}
		}
		if(b.size()>(n/2)){
			for(int i=0;i<b.size()-(n>>1);++i){
				if(s[b[i]].a>s[b[i]].c){
					a.push_back(b[i]);
				}
				else{
					c.push_back(b[i]);
				}
			}
		}
		if(c.size()>(n/2)){
			for(int i=0;i<c.size()-(n>>1);++i){
				if(s[c[i]].b>s[c[i]].a){
					b.push_back(c[i]);
				}
				else{
					a.push_back(c[i]);
				}
			}
		}
		int ans=0;
		for(int i=a.size()-1;i>=max(0LL,(int)a.size()-(n/2));--i){
			ans+=s[a[i]].a;
		}
		for(int i=b.size()-1;i>=max(0LL,(int)b.size()-(n/2));--i){
			ans+=s[b[i]].b;
		}
		for(int i=c.size()-1;i>=max(0LL,(int)c.size()-(n/2));--i){
			ans+=s[c[i]].c;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
