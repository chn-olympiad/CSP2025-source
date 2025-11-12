#include <bits/stdc++.h>
using namespace std;
int a[1005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1],ki;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){ki=i;break;}
	}
	//cout<<ki<<endl;
	int x=1,y=1,z=1;
	if(z==ki){
		cout<<x<<" "<<y;return 0;
	}
	for(;x<=n;x++){
		if(x%2==1){
			y=1;
			for(;y<=m;y++,z++){
				//cout<<x<<" "<<y<<" "<<z<<endl;
				if(z==ki){
					cout<<x<<" "<<y;return 0;
				}
			}
		}
		else{
			y=m;
			for(;y>=1;y--,z++){
				//cout<<x<<" "<<y<<" "<<z<<endl;
				if(z==ki){
					cout<<x<<" "<<y;return 0;
				}
			}
		}
	}
}