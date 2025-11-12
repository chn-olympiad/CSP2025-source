#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101];
int cnt,x;
int cnt2;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cnt++;
			cin>>a[cnt];
		}
	}
	x=a[1];
	sort(a+1,a+cnt+1,greater<int>());
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				cnt2++;
				if(a[cnt2]==x){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				cnt2++;
				if(a[cnt2]==x){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
