#include<bits/stdc++.h>
using namespace std;
int n,m;
struct seats{
	int cj,id;
}seat[1000];
bool cmp(seats a,seats b){
	return a.cj>b.cj;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>seat[i].cj;
		seat[i].id=i;
	}
	sort(seat,seat+n*m,cmp);
	int c=1,r=0;
	for(int i=0;i<n*m;i++){
		if((r==1&&c%2==0)||(r==n&&c%2==1)){
			c++;
		} 
		else if(c%2){
			r++;	
		}
		else if(c%2==0){
			r--;
		}
		if(seat[i].id==0){
			cout<<c<<' '<<r;
			break;
		}
	}
	return 0;
} 
