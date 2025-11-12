#include<bits/stdc++.h>
using namespace std;
int c,r,f;
int a[200];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>c>>r;
	for(int i=1;i<=c*r;i++)
		cin>>a[i];
	f=a[1];
	sort(a+1,a+c*r+1,cmp);
	int h=1,l=1,k=0;
	for(int i=1;i<=c*r;i++){
		if(a[i]==f) break;
		if(k==0){
			if(h==c) l++,k=1;
			else h++;
		}
		else{
			if(h==1) l++,k=0;
			else h--;
		}
	}
	cout<<l<<" "<<h;
	return 0;
}