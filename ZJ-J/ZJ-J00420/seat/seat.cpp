#include<bits/stdc++.h>
using namespace std;
int n,m,Y,b;int g,h,X,o;
int a[1001],s[1001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	X=n*m;
	for(int i=1;i<=X;i++){
		cin>>a[i];
	}
	Y=a[1];
	sort(a+1,a+X+1);
	for(int i=1,j=X;i<=X;j--,i++){
		s[j]=a[i];
	}
	for(int i=1;i<=X;i++){
		if(s[i]==Y){
			Y=i;
			break;
		}
	}
	g=Y/n;
	h=Y%n;
	if(h>0){
		g++;
	}
	else{
		h=n;
	}
	b=g%2;
	if(b==0){
		h=n-h+1;
	}
	cout<<g<<" "<<h<<endl;
	return 0;
}