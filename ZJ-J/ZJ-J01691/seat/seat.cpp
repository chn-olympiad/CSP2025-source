#include <bits/stdc++.h>
using namespace std;
struct Node{
	int num,score;
};
int n,m;
Node a[210];
inline bool cmp(Node x,Node y){return x.score>y.score;}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;++i){
		a[i].num=i;
		cin>>a[i].score;
	}
	sort(a+1,a+n*m+1,cmp);
//	for (int i=1;i<=n*m;++i) cout<<a[i].score<<' ';
	int res=0;
	for (int i=1;i<=n*m;++i){
		if (a[i].num==1) res=i; 
	}
	if (res%n==0){
		int c=res/n;
		if (c&1) cout<<c<<' '<<m;
		else cout<<c<<' '<<1;  
	} 
	else{
		int c=res/n+1;
		if (c&1) cout<<c<<' '<<res%n;
		else cout<<c<<' '<<m-(res%n)+1;
	}
	return 0; 
} 
