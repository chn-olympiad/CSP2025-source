#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,y,r,f=1;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	r=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==r){
			
			if(f%2!=0){
				if((i+1)%n==0){
					y=n;
					break;
				}
				y=(i+1)%n;
			}
			else{
				if((i+1)%n==0){
					y=1;
					cout<<i<<endl;
					break;
				}
				else{
					y=n-i%n;
				}
			}
			break;
		}
		if((i-1)%n==0)f++;
	}
	cout<<f<<" "<<y;
	fclose(seat.in);
	fclose(seat.out);
	return 0;
}
