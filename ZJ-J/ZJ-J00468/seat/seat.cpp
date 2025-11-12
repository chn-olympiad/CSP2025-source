#include<bits/stdc++.h>

#define int long long
#define N 15
#define cint const int
using namespace std;
struct node{
	int v,i;
}a[N*N];
int n,m;
bool cmp(node p,node q){
	return p.v>q.v;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].v;
        a[i].i=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].i==1){
			int x=i%n;
	        int y=i/n+(x!=0);
	        if(!x)x=n;
	        if(y&1){
	        	cout<<y<<" "<<x<<"\n";
	        	return 0;
			}
			else{
				cout<<y<<" "<<(n+1-x)<<"\n";
				return 0;
			}
		}
	}
	return 0;
}
/*
1 ≤ n,m ≤ 10
*/
