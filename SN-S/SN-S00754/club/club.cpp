//SN-S00754  陈钰婉  西安高新第一中学 
//最后一版本！ 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+10;
int T,n;
struct node{
	int x,y,z;
	int mx,mn;
	int pos;
}a[maxn];
bool cmp1(node a,node b){
	return a.mx-a.mn>b.mx-b.mn; 
}
vector<node> x,y,z;

void init(){
	x.clear(),y.clear(),z.clear();
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		init();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].mx=max({a[i].x,a[i].y,a[i].z});
			if(a[i].mx==a[i].x) a[i].mn=max(a[i].y,a[i].z);
			if(a[i].mx==a[i].y) a[i].mn=max(a[i].x,a[i].z);
			if(a[i].mx==a[i].z) a[i].mn=max(a[i].x,a[i].y);
		}
		sort(a+1,a+1+n,cmp1);
		
		for(int i=1;i<=n;i++){
			if(a[i].x>=max(a[i].y,a[i].z)){
				if(x.size()<n/2) a[i].pos=1,x.push_back(a[i]);
				else{
					if(a[i].y>a[i].z){
						if(y.size()<n/2) a[i].pos=2,y.push_back(a[i]);
						else a[i].pos=3,z.push_back(a[i]);
					}
					else{
						if(z.size()<n/2) a[i].pos=3,z.push_back(a[i]);
						else a[i].pos=2,y.push_back(a[i]);
					}
				}
			}
			else if(a[i].y>=max(a[i].x,a[i].z)){
				if(y.size()<n/2) a[i].pos=2,y.push_back(a[i]);
				else{
					if(a[i].z>a[i].z){
						if(z.size()<n/2) a[i].pos=1,x.push_back(a[i]);
						else a[i].pos=3,z.push_back(a[i]);
					}
					else{
						if(x.size()<n/2) a[i].pos=1,x.push_back(a[i]);
						else a[i].pos=3,z.push_back(a[i]);
					}
				}
			}
			else if(a[i].z>=max(a[i].y,a[i].z)){
				if(z.size()<n/2) a[i].pos=3,z.push_back(a[i]);
				else{
					if(a[i].x>a[i].y){
						if(x.size()<n/2) a[i].pos=1,x.push_back(a[i]);
						else a[i].pos=2,y.push_back(a[i]);
					}
					else{
						if(y.size()<n/2) a[i].pos=2,y.push_back(a[i]);
						else a[i].pos=1,x.push_back(a[i]);
					}
				}
			}
		}
		int ans=0;
		for(auto i:x) ans+=i.x;
		for(auto i:y) ans+=i.y;
		for(auto i:z) ans+=i.z;
		cout<<ans<<'\n';
	}
}
/*
2
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
