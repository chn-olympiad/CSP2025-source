#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum[500030];
int vis[500030];
inline ll Sum(int l,int r){
	return sum[r]^sum[l-1];
}
int n,k;
struct node{
	int l,r;
	int len;
	
	bool operator> (const node &b) const{
		return len>b.len;
	}
};
priority_queue<node, vector<node>, greater<node> > heap; 
vector<node> ans;
inline bool check(node &t){
	for(auto x :ans) if(!(x.r<t.l || t.r<x.l)) return 0;
	return 1;
}

ll flag;//
ll SUM;//
int TEMP;//
ll TT;//
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>sum[i];
		SUM+=sum[i];//
		if(sum[i]==1){//
			flag++;
			TEMP++;
		}else{
			TT+=TEMP/2;
			TEMP=0;
		}//
		sum[i]=sum[i]^sum[i-1];
	}
	if(SUM<=n){//
		TT+=TEMP/2;
		TT+=(n-flag);
		if(k>1) cout<<0;
		else if(k==1) cout<<flag;
		else cout<<TT;
		return 0;
		/*
		35 0
		1 1 0 0 0 1 0 0 1 0 1 0 0 1 1 1 0 1 0 1 1 1 0 1 0 1 1 1 1 1 0 1 1 0
		
		*/
	}//
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(Sum(i,j)==k) heap.push({i,j,j-i+1});
		}
	}
	while(!heap.empty()){
		auto t=heap.top();
		//cout<<t.l<<':'<<t.r<<'|'<<!check(t)<<'\n';
		heap.pop();
		
		if(!check(t)) continue;
		ans.push_back(t);
	}
	cout<<ans.size();
//	
//	cout<<'\n';
//	for(auto x : ans){
//		cout<<x.l<<':'<<x.r<<'\t';
//	}
//	cout<<'\n';
	return 0;
}

