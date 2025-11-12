#include<bits/stdc++.h>
using namespace std;
bool swp(int a,int b){
	return a>b;
}
int b[105],x,y,s;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>x>>y;
	cin>>b[0];
	s=b[0];
	for(int i=1;i<x*y;i++){
		cin>>b[i];
	}
	sort(b,b+(x*y),swp);
	int x1,y1;
	for(int i=0;i<x*y;i++){
		cout<<b[i]<<' ';
		
	}
	cout<<endl;
	for(int i=0;i<=x*y;i++){
		if(b[i]==s){
			y1=(i+1)/x+1;
			if((i+1)%x==0){
				y1--;
			}
			if(y1%2==1){
				x1=(i+1)%x;
			}else{
				x1=x-(i+1)%x+1;
			}
			if(x1==0){
				x1=x;
			}
			cout<<y1<<' '<<x1;
			break;
		}
	}
} 
