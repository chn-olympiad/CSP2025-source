#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a1,u,x=1,y=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a1=a[1];
	//cout<<"a1:"<<a1<<endl;
	sort(a+1,a+1+n*m,cmp);
	//for(int i=1;i<=n*m;i++) cout<<a[i]<<" ";
	//cout<<endl;
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			u=i;
			break;
		}
	}
	//cout<<u<<endl;
	for(int i=1;i<u;i++){
		if(y==m){
			if(x%2==1){
	//			cout<<"a ";
				x++;
			}else{
	//			cout<<"b ";
				y--;
			}
		}else if(y==1){
			if(x%2==0){
	//			cout<<"c ";
				x++;
			}else{
	//			cout<<"d ";
				y++;
			}
		}else{
			if(x%2==1){
	//			cout<<"e ";
				y++;
			}else{
	//			cout<<"f ";
				y--;
			}
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
