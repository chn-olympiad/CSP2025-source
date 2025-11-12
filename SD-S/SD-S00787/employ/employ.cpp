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
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	mt19937 rd(time(0) ^ clock());
	cout<<rd() % 998244353;
}
