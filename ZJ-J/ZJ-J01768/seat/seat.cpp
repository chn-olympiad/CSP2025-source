#include<bits/stdc++.h>
using namespace std;
int n,m,a[10004];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int f=a[1];
	sort(a+1,a+n*m+1,cmp);
	int l=0,r=0;
	for(int i=1;i<=n*m;i++){
		if(i%n==1) l++;
		if(a[i]==f){
			if(l%2==1){
				r=i%n;
				if(r==0) r=n;
			}else{
				r=n-i%n+1;
			}
			cout<<l<<" "<<r;
			return 0;
		}
	}
	return 0;
}
