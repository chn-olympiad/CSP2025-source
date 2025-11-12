#include <bits/stdc++.h>
using namespace std;
int n,m,z,h,a[110],cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			z=a[i];
		}
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==z){
			h=i;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				cnt++;
				if(h==cnt){
					cout<<i<<" "<<j;
					break;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				cnt++;
				if(h==cnt){
					cout<<i<<" "<<j;
					break;
				}
			}
		}
	}
	return 0;
}
