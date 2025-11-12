#include<bits/stdc++.h>
using namespace std;
struct abc{
	int s;
	bool h;
};
abc a[1010];
bool cmp(abc x,abc y){
	return x.s>y.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	int n,m;
	cin>>n>>m;
	cin>>a[1].s;
	a[1].h=1;
	for(int i=2;i<=n*m;i++){
		cin>>a[i].s;
		a[i].h=0;
	}
	sort(a+1,a+n*m+1,cmp);
	int xx=1,yy=1;
	int d=0;
	bool f=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			yy=0;
			for(int j=1;j<=n;j++){
				d++;
				yy++;
				if(a[d].h==1){
					cout<<xx<<" "<<yy<<endl;
					f=1;
					break;
				}
			}
		}else{
			yy=n+1;
			for(int j=n;j>=1;j--){
				d++;
				yy--;
				if(a[d].h==1){
					cout<<xx<<" "<<yy<<endl;
					f=1;
					break;
				}
			}
		}
		xx++;
		if(f){
			break;
		}
	}
	return 0;
}
