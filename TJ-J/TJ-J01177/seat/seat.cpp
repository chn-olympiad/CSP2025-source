#include<bits/stdc++.h>
using namespace std;
struct node{
	int shuzhi;
	int weizhi;
}a[105];
bool cmp(node x,node y){
	return x.shuzhi>y.shuzhi;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int nm=n*m;
	for(int i=1;i<=nm;i++){
		cin>>a[i].shuzhi;
		a[i].weizhi=i;
	}
	sort(a+1,a+nm+1,cmp);
	for(int i=1;i<=nm;i++){
		if(a[i].weizhi==1){
			int ans1=(i/n)+1,ans2=0;
			if(i%n==0) ans1--;
			if(ans1%2==1){
				ans2=i%n;
			}
			if(ans1%2==0){
				ans2=n-(i%n);
			}
			if(ans1%2==1&&ans2==0) ans2=n;
			cout<<ans1<<" "<<ans2;
		}
	}
	return 0;
}
