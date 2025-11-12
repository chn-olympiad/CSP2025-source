#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m;
struct dd{
	int num,j;
}a[N];
bool cmp(dd a,dd b){
	return a.num>b.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int d=n*m;
	for(int i=1;i<=d;i++){
		cin>>a[i].num;
		a[i].j=i;
	}
	sort(a+1,a+1+d,cmp);
	for(int i=1;i<=d;i++){
		if(a[i].j==1){
			if(((i-1)/n+1)%2==1){
				cout<<(i-1)/n+1<<" "<<(i-1)%n+1;
			}
			else{
				cout<<(i-1)/n+1<<" "<<n-(i-1)%n;
			}
			return 0;
		}
	}
}

