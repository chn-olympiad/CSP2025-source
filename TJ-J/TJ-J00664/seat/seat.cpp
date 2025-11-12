#include<bits/stdc++.h>
using namespace std;
struct jgt{
	int fs;
	int id;
}a[1005];
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].fs;
		a[i].id=i;
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		for(int j=m;j>0;j--){
			if(a[i+j].id==1){
				cout<<i<<" "<<j+i;
			}
		}
	}
	return 0;
}
