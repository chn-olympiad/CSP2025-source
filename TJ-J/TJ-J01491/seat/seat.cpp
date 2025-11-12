#include<bits/stdc++.h>
using namespace std;
struct node{
	int fen,hao;
};
int m,n,h;
node a[200];
bool cmp(node a,node b){
	return a.fen>b.fen;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].fen;
		a[i].hao=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m*n;i++){
		if(a[i].hao==1){
				if(i%n==0){
					h=i/n;
					cout<<i/n<<" "; 
				}else{
					h=i/n+1;
					cout<<i/n+1<<" ";
				}
				if(h%2==1){
					if(i%n==0){
						cout<<n;
					}else{
						cout<<i%n;
					}
					return 0;
				}else{
					if(i%n==0){
						cout<<1;
					}else{
						cout<<n-(i%n)+1;
					}
					return 0;
				}
		}
	}
	return 0;
} 
