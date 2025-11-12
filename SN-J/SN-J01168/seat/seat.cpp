//SN-J01168 ¬нич–щ 
#include <bits/stdc++.h>
using namespace std;
int n,m,s;
int a[110];
bool cmp(int x,int y){
	return x>y;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
		if(i==1) s=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			int c,r;
			if(i%n==0) c=i/n;
			else c=i/n+1;
			if(c%2==0){
				if(i%n==0) r=1;
				else r=n-(i%n)+1;
			}
			if(c%2==1){
				if(i%n==0) r=n;
				else r=i%n;
			}
			cout << c << " " << r;
			break;
		}
	}
	return 0;
}
