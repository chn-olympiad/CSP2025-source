#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m,g,s,l=1,h=1;
	cin>>n>>m;
	s=n*m;
	int a[1000];
	for(int i=0;i<s;i++){
		cin>>a[i];
	}
	g=a[0];
	sort(a,a+s,cmp);
	for(int i=0;i<s;i++){
	    if(a[i]==g){
			cout<<l<<" "<<h;
			break;
		}
		if(h==n&&l<=m){
			l++;
		}
		else if(h==1&&l>1){
			l++;
		}
		if(h>n){
			h=h-2;
		}
		if(h==n){
			h--;
		}
		else{
			h++;
		}
	}
}
