#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
using namespace std;
int n,m;
struct _{
	int x;
	bool w;
};
vector<_> a;
bool cmp(_ c,_ d){
	return c.x>d.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	fast;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		int x;
		cin>>x;
		if(i==0) a.push_back({x,1});
		else a.push_back({x,0});
	}
	sort(a.begin(),a.end(),cmp);
	int w=0;
	for(;w<a.size();w++){
		if(a[w].w==1) break;
	}
	w++;
	cout<<(w-1)/n+1<<" ";
	if((w-1)/n%2==0){
		cout<<(w-1)%n+1;
	}else{
		cout<<n-((w-1)%n+1)+1;
	}
}
