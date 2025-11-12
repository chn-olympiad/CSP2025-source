#include <bits/stdc++.h>
using namespace std;
int a[500];
struct zb{
	int x;
	int y;
}s[500];
int main(){
	int n,m;
	freopen("seat.in","r",stdin);
	cin>>n>>m;
	int aaa=0;
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				aaa++;
				s[aaa].x=i;
				s[aaa].y=j;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				aaa++;
				s[aaa].x=i;
				s[aaa].y=j;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int bbb=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m,j=1;i>=1;i--,j++){
		if(a[i]==bbb){
			freopen("seat.out","w",stdout);
			cout<<s[j].x<<" "<<s[j].y;
			break;
		}
	}
	return 0;
}
