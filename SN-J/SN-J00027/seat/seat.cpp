#include<bits/stdc++.h>
using namespace std;
int n,m;
struct ks{
	int a,x,h,l;
}oier[105];
bool cmp(ks y,ks z){
	return y.a>z.a;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>oier[i].a;
		oier[i].x=i;
	}
	sort(oier+1,oier+1+n*m,cmp);
	for(int i=1,k=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				oier[k].h=j;
				oier[k].l=i;
				k++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				oier[k].h=j;
				oier[k].l=i;
				k++;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(oier[i].x==1){
			cout<<oier[i].l<<" "<<oier[i].h;
			return 0;
		}
	}
}
