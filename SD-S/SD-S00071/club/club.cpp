#include<bits/stdc++.h>
using namespace std;
struct Node{
	short lei;
	int id,num;
}a[100009],b[100009],c[100009];
bool cmp(Node x,Node y){
	return x.num>y.num;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].num>>b[i].num>>c[i].num;
			a[i].id=b[i].id=c[i].id=i;
			a[i].lei=1;b[i].lei=2;c[i].lei=3;
		}
		int ans,A,B,C;
		ans=A=B=C=0;
		for(int i=1;i<=n;i++){
			sort(a+1,a+1+n,cmp);
			sort(b+1,b+1+n,cmp);
			sort(c+1,c+1+n,cmp);
			if(A>=ceil(n/2)) a[1].num=-1;
			if(B>=ceil(n/2)) b[1].num=-1;
			if(C>=ceil(n/2)) c[1].num=-1;
			Node u;
			if(cmp(a[1],b[1])){
				if(cmp(a[1],c[1])){
					u=a[1];
				}else{
					u=c[1];
				}
			}else{
				if(cmp(b[1],c[1])){
					u=b[1];
				}else{
					u=c[1];
				}
			}
			if(u.lei==1){
				ans+=a[1].num;
				a[1].num=-1;
				A++;
				bool AA=1,BB=0,CC=0;
				for(int i=1;i<=n;i++){
					if(AA&&BB&&CC) break;
					if(b[i].id==a[1].id){
						b[i].num=-1;
						BB=1;
					}
					if(c[i].id==a[1].id){
						c[i].num=-1;
						CC=1;
					}
				}
			}else if(u.lei==2){
				ans+=b[1].num;
				b[1].num=-1;
				B++;
				bool AA=0,BB=1,CC=0;
				for(int i=1;i<=n;i++){
					if(AA&&BB&&CC) break;
					if(a[i].id==b[1].id){
						a[i].num=-1;
						AA=1;
					}
					if(c[i].id==b[1].id){
						c[i].num=-1;
						CC=1;
					}
				}								
			}else{
				ans+=c[1].num;
				c[1].num=-1;
				C++;
				bool AA=0,BB=0,CC=1;
				for(int i=1;i<=n;i++){
					if(AA&&BB&&CC) break;
					if(b[i].id==c[1].id){
						b[i].num=-1;
						BB=1;
					}
					if(a[i].id==c[1].id){
						a[i].num=-1;
						AA=1;
					}
				}								
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}


