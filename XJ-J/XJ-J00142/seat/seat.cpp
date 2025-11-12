#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],r;
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
	r=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			r=i;
			break;
		}
	}
	int l=ceil(r*1.0/m),h=r%n;
	if(l%2==1){
		if(h==0)h=n;
	}else{
		h=n+1-h;
	}
	cout<<l<<" "<<h;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
