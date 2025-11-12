#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 7;

int T, n, vis[N];

int ja, jb, jc, sum;

struct Node{
	int a, b, c;
}arr[N];

struct Edge {
	int id, w;
	bool operator < (const Edge& s) const{
		return w < s.w;
	}
};

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin >> T;
	
	while(T--) {
		sum = 0;
		cin >> n;
		int tmp = n / 2;
		set<Edge> aa, bb, cc;
		for(int i = 1; i <= n; i++) {
			cin >> arr[i].a >> arr[i].b >> arr[i].c;
			if(arr[i].a > arr[i].b && arr[i].a > arr[i].c) ja++, aa.insert({i, arr[i].a}), sum += arr[i].a;
			else if(arr[i].b > arr[i].a && arr[i].b > arr[i].c) jb++, bb.insert({i, arr[i].b}), sum += arr[i].b;
			else if(arr[i].c > arr[i].b && arr[i].c > arr[i].a) jc++, cc.insert({i, arr[i].c}), sum += arr[i].c;
			else if(arr[i].a == arr[i].b) {
				if(jb > ja) ja++, vis[i] = 1, aa.insert({i, arr[i].a}), sum += arr[i].a;
				else jb++, vis[i] = 2, vis[i] = 2, bb.insert({i, arr[i].b}), sum += arr[i].b;
			}else if(arr[i].a == arr[i].c) {
				if(ja > jc) jc++, vis[i] = 3, cc.insert({i, arr[i].c}), sum += arr[i].c;
				else ja++, vis[i] = 1, aa.insert({i, arr[i].a}), sum += arr[i].a;
			}else if(arr[i].c == arr[i].b){
				if(jb > jc) jc++, vis[i] = 3, cc.insert({i, arr[i].c}), sum += arr[i].c;
				else jb++, vis[i] = 2, bb.insert({i, arr[i].b}), sum += arr[i].b;
			}
		}
		
		if(ja > tmp) {
			for(Edge i : aa) {
				int ssum = sum;
				ssum -= i.w;
				if(arr[i.id].b > arr[i.id].c) {
					ssum += arr[i.id].b;
					ja--, i.w = INT_MAX, sum = ssum, jb++, bb.insert({i.id, arr[i.id].b});
				}else if(arr[i.id].c > arr[i.id].b){
					ssum += arr[i.id].c;
					ja--, i.w = INT_MAX, sum = ssum, jc++, cc.insert({i.id, arr[i.id].c});
				}else {
					ssum += arr[i.id].b;
					if(jb < jc) ja--, i.w = INT_MAX, sum = ssum, jb++, bb.insert({i.id, arr[i.id].b});
					else vis[i.id] = 2, i.w = INT_MAX, sum = ssum, jc++, cc.insert({i.id, arr[i.id].c});
				}
			} 
		}else if(jb > tmp) {
			for(Edge i : bb) {
				int ssum = sum;
				ssum -= i.w;
				if(arr[i.id].a > arr[i.id].c) {
					ssum += arr[i.id].a;
					jb--, i.w = INT_MAX, sum = ssum, ja++, aa.insert({i.id, arr[i.id].a});
				}else if(arr[i.id].a < arr[i.id].c){
					ssum += arr[i.id].c;
					jb--, i.w = INT_MAX, sum = ssum, jc++, cc.insert({i.id, arr[i.id].c});
				}else {
					ssum += arr[i.id].a;
					if(ja < jc) jb--, i.w = INT_MAX, sum = ssum, ja++, aa.insert({i.id, arr[i.id].a});
					else jb--, i.w = INT_MAX, sum = ssum, jc++, cc.insert({i.id, arr[i.id].c});
				}
			} 
		}else {
			for(Edge i : cc) {
				int ssum = sum;
				ssum -= i.w;
				if(arr[i.id].b > arr[i.id].a) {
					ssum += arr[i.id].b;
					jc--, i.w = INT_MAX, sum = ssum, jb++, bb.insert({i.id, arr[i.id].b});
				}else if(arr[i.id].b < arr[i.id].a){
					ssum += arr[i.id].a;
					jc--, i.w = INT_MAX, sum = ssum, ja++, aa.insert({i.id, arr[i.id].a});
				}else {
					ssum += arr[i.id].b;	
					if(ja < jb) jc--, i.w = INT_MAX, sum = ssum, ja++, aa.insert({i.id, arr[i.id].a});
					else jc--, i.w = INT_MAX, sum = ssum, jb++, bb.insert({i.id, arr[i.id].b});
				}
			} 
		}
		
		cout << sum << endl;
	}
	return 0;
} 
