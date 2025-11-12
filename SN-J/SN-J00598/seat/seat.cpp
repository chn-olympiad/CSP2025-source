#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int n,m,a[1005],w,aa,l,r;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	w=n*m;
	for(int i=1;i<=w;i++){
		cin>>a[i];
	}
	aa=a[1];
	sort(a+1,a+w+1,cmp);
	for(int i=1;i<=w;i++){
		if(a[i]==aa){
			if(i%n==0){
				l=i/n;
				r=n;
				break;
			}else if(i%n!=0){
				l=i/n+1;
				r=i%n;
	 			break;
			}
		}
	}
	cout<<l<<' '<<r;
	return 0;
}
