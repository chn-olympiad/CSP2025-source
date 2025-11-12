#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],c,r,b,s,x=1,y=1,f=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			s=i;
			break;
		}
	}
	for(int i=1;i<s;i++){
		if(f){
			if(y<n){
				y++;
			}else{
				x++;
				f=0;
			}
		}else{
			if(y>1){
				y--;
			}else{
				x++;
				f=1;
			}
		}
	}
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
