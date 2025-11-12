#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define in insert
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
const int N = 1e5 + 10;
struct node{
	int x,y,z;
}a[N];
bool vis[N];
int p[N];
int n;
int cnt1;
int cnt2;
int cnt3;
int find_max1(node x){
	if(x.x >= x.y&&x.x >= x.z){
		return 1;
	}
	else if(x.y >= x.x&&x.y >= x.z){
		return 2;
	}
	else return 3;
}
int find_max2(node x){
	int p = find_max1(x);
	if(p == 1){
		if(x.y >= x.z)return 2;
		else return 3;
	}
	else if(p == 2){
		if(x.x >= x.z)return 1;
		else return 3;
	}
	else {
		if(x.x >= x.y)return 1;
		else return 2;
	}
}
int find_max3(node x){
	int p1 = find_max1(x),p2 = find_max2(x);
	if(p1 == 1&&p2 == 2)return 3;
	else if(p1 == 1&&p2 == 3)return 2;
	else if(p1 == 2&&p2 == 3)return 1;
	else if(p1 == 2&&p2 == 1)return 3;
	else if(p1 == 3&&p2 == 1)return 2;
	else if(p1 == 3&&p2 == 2)return 1;
}
bool cmp1(int x,int y){
	return a[x].x > a[y].x;
}
bool cp1(int x,int y){
	return a[x].x < a[y].x;
}
bool cmp2(int x,int y){
	return a[x].y > a[y].y;
}
bool cp2(int x,int y){
	return a[x].y < a[y].y;
}
bool cmp3(int x,int y){
	return a[x].z > a[y].z;
}
bool cp3(int x,int y){
	return a[x].z < a[y].z;
}
int get_size(int pos){
	if(pos == 1)return cnt1;
	else if(pos == 2)return cnt2;
	else return cnt3;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin>>T;
	while(T--){
//		memset(vis,0,sizeof(vis));
		cin>>n;
		ll ans = 0;
		vector<int>a1,a2,a3;
		for(int i = 1;i <= n;++i){
			int x,y,z;
			cin>>x>>y>>z;
			a[i] = {x,y,z};
			ans += max(x,max(y,z));
			p[i] = find_max1(a[i]);
		}
		cnt1 = cnt2 = cnt3 = 0;
		for(int i = 1;i <= n;++i){
			if(p[i] == 1)cnt1++,a1.pb(i);
			else if(p[i] == 2)cnt2++,a2.pb(i);
			else cnt3++,a3.pb(i);
		}
//		for(int i = 1;i <= n;++i)cerr<<p[i]<<" ";
//		cerr<<'\n';
		int m = n / 2;
		int ans1 = 0;
//		cout<<ans<<"\n";
		if(cnt1 > m){
//			sort(a1.begin(),a1.end(),cmp2);
//			sort(a1.begin(),a1.end(),cp1);
			vector<int>v1,v2;
			for(int i = 0;i < cnt1;++i){
				int pos = a1[i];
				v1.pb(a[pos].x - a[pos].y);
				v2.pb(a[pos].x - a[pos].z);
			}
			vector<int>v;
			for(int i = 0;i < cnt1;++i){
//				cout<<v1[i]<<" "<<v2[i]<<'\n';
				v.pb(min(v1[i],v2[i]));
			}
			sort(v.begin(),v.end());
			for(int i = 0;i < cnt1 - m;++i){
				ans -= v[i];
			}
//			ans -= ans1;
		}
		else if(cnt2 > m){
//			sort(a2.begin(),a2.end(),cmp1);
//			sort(a2.begin(),a2.end(),cp2);
			vector<int>v1,v2;
			for(int i = 0;i < cnt2;++i){
				int pos = a2[i];
				v1.pb(a[pos].y - a[pos].x);
				v2.pb(a[pos].y - a[pos].z);
			}
			vector<int>v;
			for(int i = 0;i < cnt2;++i){
				v.pb(min(v1[i],v2[i]));
			}
			sort(v.begin(),v.end());
			for(int i = 0;i < cnt2 - m;++i){
				ans -= v[i];
			}
		}
		else if(cnt3 > m){
//			sort(a3.begin(),a3.end(),cmp1);
//			sort(a3.begin(),a3.end(),cp3);
			vector<int>v1,v2;
			for(int i = 0;i < cnt3;++i){
				int pos = a3[i];
				v1.pb(a[pos].z - a[pos].y);
				v2.pb(a[pos].z - a[pos].x);
			}
			vector<int>v;
			for(int i = 0;i < cnt3;++i){
				v.pb(min(v1[i],v2[i]));
			}
			sort(v.begin(),v.end());
			for(int i = 0;i < cnt3 - m;++i){
				ans -= v[i];
			}
		}
		cout<<ans<<'\n';
	}
}
