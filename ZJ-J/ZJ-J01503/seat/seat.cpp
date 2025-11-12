#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=105;
struct node{
	int num,x;
}a[N];
int n,m;
int l,r;
bool cmp(node f,node s){
	return f.x>s.x;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;a[i].num=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].num==1){
			l=i/n;
			if(i%n!=0)l++;
			r=i%n;
			if(r==0)r=n;
			if(l%2==0){
				r=n-r+1;
			}
			break;
		}
	}
	cout<<l<<" "<<r;
	return 0;
}