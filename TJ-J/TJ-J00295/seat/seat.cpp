#include<bits/stdc++.h>
using namespace std;
struct node{
	int v;
	int r,c;
}b[110];
int cmp(node a,node b){
	return a.v>b.v;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i].v;
	}
	int p=b[1].v;
	sort(b+1,b+n*m+1,cmp);
	b[1].r=1;
	b[1].c=1;
	for(int i=2;i<=n*m;i++){
		if(b[i-1].r>1&&b[i-1].c==1&&b[i-1].c!=b[i-2].c||b[i-1].c==n&&b[i-1].r==b[i-2].r){
			b[i].r=b[i-1].r+1;
			b[i].c=b[i-1].c;
		}
		else{
			b[i].r=b[i-1].r;
			if(b[i].r%2!=0){
				b[i].c=b[i-1].c+1;
			}
			else{
				b[i].c=b[i-1].c-1;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(b[i].v==p){
			cout<<b[i].r<<" "<<b[i].c;
			return 0;
		}
	}
	return 0;
}
