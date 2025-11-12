#include<bits/stdc++.h>
using namespace std;
int xn,y2n,zn;
struct jiegou{
	int x;
	int y;
	int z;
	int maxa;
	int maxi;
};
int mid(int q,int w,int e){
	if(q>w>e ||e>w>q) return w;
	if(q>e>w ||w>e>q) return e;
	if(w>q>e ||e>q>w) return q;
	if(w==q && e>w) return w;
	if(w==q && e<w) return q;
	if(w==e && q>w) return w;
	if(w==e && q<w) return e;
	if(e==q && w>e) return e;
	if(e==q && w<e) return e;
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		jiegou a[100];
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].maxa=max(max(a[i].x,a[i].y),a[i].z);
			if(a[i].maxa==a[i].x) a[i].maxi=1;
			else if(a[i].maxa==a[i].y) a[i].maxa=2;
			else a[i].maxa=3;
		}
		if(n==2){
			if(a[1].maxa!=a[2].maxa){
				cout<<a[1].maxa+a[2].maxa;
			}
			else{
				 if(mid(a[1].x,a[1].y,a[1].z)>mid(a[2].x,a[2].y,a[2].z)){
				 	cout<<mid(a[1].x,a[1].y,a[1].z)+a[2].maxa;
				 }
				 else{
				 	cout<<mid(a[2].x,a[2].y,a[2].z)+a[1].maxa;
				 }
			}
		}
		if(n==4){
			
		}
		//1 1 2   1 2 1   2 1 1 
	}
	return 0;
} 
