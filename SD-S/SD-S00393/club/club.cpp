#include <bits/stdc++.h>
using namespace std;
#define int long long
#define LYT ios::sync_with_stdio(0),cin.tie(0)
#define x first
#define y second
#define ddd cout<<"Ddd";
const int N = 1e5 + 10;
struct node{
	int u,v,w;
}a[N];
void solve(){
	int n;
	cin >> n;
	int suma = 0,sumb = 0,sumc = 0;
	int ans = 0;
	priority_queue <pair<int,int>> qa,qb,qc; 
	for(int i = 1;i <= n;i++){
		cin >> a[i].u >> a[i].v >> a[i].w;
		if(a[i].u >= a[i].v && a[i].u >= a[i].w){
			suma++;
			ans += a[i].u;
			int aa = a[i].v - a[i].u,bb = a[i].w - a[i].u;
			qa.push({max(aa,bb),6});
		}else if(a[i].v >= a[i].u && a[i].v >= a[i].w){
			sumb++;
			ans += a[i].v;
			int aa = a[i].u - a[i].v,bb = a[i].w - a[i].v;
			qb.push({max(aa,bb),11});
		}else if(a[i].w >= a[i].u && a[i].w >= a[i].v){
			sumc++;
			ans += a[i].w;
			int aa = a[i].u - a[i].w,bb = a[i].v - a[i].w;
			qc.push({max(aa,bb),3});
		}
	}
	//cout << suma << " " << sumb << " " << sumc << " "; 
	while(suma > n / 2){
		while(!qa.empty()){
			int sum = -qa.top().x,id = qa.top().y;
			qa.pop();
			ans -= sum;
			suma--; 
			break;
		}
	} 
	while(sumb > n / 2){	
		while(!qb.empty()){
			int sum = -qb.top().x,id = qb.top().y;
			qb.pop();
			ans -= sum;
			sumb--; 
			break;
		}		
	}
	while(sumc > n / 2){	
		while(!qc.empty()){
			int sum = -qc.top().x,id = qc.top().y;
			qc.pop();
			ans -= sum;
			sumc--; 
			break;
		}
	}
	//cout << suma << " " << sumb << " " << sumc << " ";
	cout << ans << "\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--) solve(); 
	return 0;
} 
/*
1
8

*/ 
