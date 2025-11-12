#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+100;
struct Node{
	int x,y,z;
};
struct Node2{
	int num,number;
};
bool cmp(Node2 x,Node2 y) {
	return x.num < y.num;
}
bool cmp2(Node2 x,Node2 y){
	return x.num > y.num;
}
Node v[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<Node2> a,b,c;
//		vector<Node> v;
		for(int i = 0; i < n; i++){
			int xx,yy,zz; cin >> xx >> yy >> zz;
			
//			Node news;
//			news.x=xx;
//			news.y=yy;
//			news.z=zz;
//			v.push_back(news);

			v[i].x=xx;
			v[i].y=yy;
			v[i].z=zz;
			int mx=max(xx,max(yy,zz));
			Node2 nows;
			nows.num=mx;
			nows.number=i;
			if(mx==xx) a.push_back(nows);
			else if(mx==yy) b.push_back(nows);
			else if(mx==zz) c.push_back(nows);
//			else cout << "This is wrong!!!";
		}
		int ans=0;
		sort(a.begin(),a.end(),cmp);
		sort(b.begin(),b.end(),cmp);
		sort(c.begin(),c.end(),cmp);
		for(int i = 1; i <= 5; i++){
			while(a.size()>n/2){
				Node2 news=a.back();
				int mx=max(v[news.number].y,v[news.number].z);
				if(mx==v[news.number].y) {
					news.num=v[news.number].y;
					b.push_back(news);
				}
				else/*(v[news.number].z==mx)*/ {
					news.num=v[news.number].z;
					c.push_back(news);
				}
//				else cout << "This is wrong!!!";
				a.pop_back();
			}
			while(b.size()>n/2){
				Node2 news=b.back();
				int mx=max(v[news.number].x,v[news.number].z);
				if(mx==v[news.number].x) {
					news.num=v[news.number].x;
					a.push_back(news);
				}
				else/*(v[news.number].z==mx)*/ {
					news.num=v[news.number].z;
					c.push_back(news);
				}
//				else cout << "This is wrong!!!";
				b.pop_back();
			}
			while(c.size()>n/2){
				Node2 news=c.back();
				int mx=max(v[news.number].y,v[news.number].x);
				if(mx==v[news.number].y) {
					news.num=v[news.number].y;
					b.push_back(news);
				}
				else/*(v[news.number].x==mx)*/ {
					news.num=v[news.number].x;
					a.push_back(news);
				}
//				else cout << "This is wrong!!!";
				c.pop_back();
			}
			int sum=0;
			for(int i = 0; i < a.size(); i++) {sum+=a[i].num;}
			for(int i = 0; i < b.size(); i++) {sum+=b[i].num;}
			for(int i = 0; i < c.size(); i++) {sum+=c[i].num;}
			ans=max(ans,sum);
		}
		
		
		cout << ans << '\n' << '\n';
	}
}
