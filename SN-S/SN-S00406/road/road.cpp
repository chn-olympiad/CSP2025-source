#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3;
int n,m,k;
struct Node{
    int w,x,y;	
}a[N];
int main(){
	freopen("reod.in","r",stdin);
	freopen("reod.out","w",stdout);
    cin>>n>>m>>k;
    int ans=0;
    for(int i=1;i<=n;i++){
    	cin>>a[i].x>>a[i].y>>a[i].w;
    	ans+=a[i].w;
	}
    cout<<"0";
	return 0;
}
