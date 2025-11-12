#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	return x>y;
}
int l,r,y;
int n,m,w,a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	w=n*m;
	for(int i=1;i<=w;i++) cin>>a[i];
	y=a[1];
	sort(a+1,a+1+w,cmp);
	r=1;
	for(int i=1;i<=w;i++){
		if(r%2==1) l++;
		else l--;
		if(l==n+1&&r%2==1){
			r++,l--;
		}else if(l==0&&r%2==0){
			r++,l++;
		}
		if(a[i]==y){
			cout<<r<<" "<<l;
			return 0;
		}
	}
}
