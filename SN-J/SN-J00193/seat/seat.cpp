#include<bits/stdc++.h>
using namespace std;
int n,m;
struct s{
	int a,b;
}ss[102];
bool cmp(s x,s y){
	return x.a>y.a;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>ss[i].a;
		ss[i].b=i;
	}
	sort(ss+1,ss+n*m+1,cmp);
	for(int i=1;i<=m*n;i++){
		if(ss[i].b==1){
			if(i<=n){
				cout<<1<<' '<<i;
			}else{
				cout<<i/n+1<<' ';
				if(i/n%2||(!(i/n%2)&&((i%n)==0))){
					cout<<n-i%n+1;
				}else{
					cout<<i%n;
				}
			}
			return 0;
		}
	}
	return 0;
}
