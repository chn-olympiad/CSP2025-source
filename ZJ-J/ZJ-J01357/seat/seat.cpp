#include<bits/stdc++.h>
using namespace std;
int n,m;
struct ks{
	int bh,nm;
}a[1010];
bool cmp(ks l243S,ks L243s){
	return l243S.nm>L243s.nm;
}
int x=1,y=1,k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].nm;
		a[i].bh=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(k=1;k<=n*m;k++){
		if(a[k].bh==1){
			cout<<x<<' '<<y;
			return 0;
		}
		if(x%2==1){
			y++;
		}else y--;
		if(y>n||y<1){
			if(x%2==0){
				y++;
			}else y--;
			x++;
		}
	}
	return 0;
}
