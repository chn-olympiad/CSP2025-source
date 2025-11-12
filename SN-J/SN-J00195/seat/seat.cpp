//吴泊成 SN-J00195 西安市曲江第一中学 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[205],o,r,h,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	o=a[1];
	sort(a+1,a+n*m+1);
	
	for(int i=n*m,j=1;i>=1;i--,j++){
		if(a[i]==o){
			r=j;
			break;
		}
	}
	int sh=r/n;
	int yu=r%n;
	if(yu==0){
		l=sh;
	}
	else l=sh+1;
	if(l%2==0){
		if(yu==0) h=1;
		else h=n-yu+1;
	}
	else{
		if(yu==0) h=n;
		else h=yu;
	}
	cout<<l<<" "<<h;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
