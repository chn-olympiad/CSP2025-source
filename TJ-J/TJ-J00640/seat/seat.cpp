#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int cj;
	int num;
}a[101];
bool cmp(node x,node y){
	return x.cj>y.cj;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].cj;
		a[i].num=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].num==1){
			if(i%n==0){
				cout<<i/n<<" ";
				if(i/n%2==0){
					//cout<<1;
					break;
				}
				else{
					//cout<<n;
					break;
				}
			}
			else{
				cout<<i/n+1<<" ";
				if((i/n+1)%2==1){
					//cout<<i%n;
					break;
				}
				else{
					//cout<<n-i%n+1;
					break;
				}
			}
		}
	}
	return 0;
}
