#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],R,t;
bool comp(int a,int b){
	return a>b;
}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=0;i<n*m;i++){
	cin>>a[i];
}
R=a[0];
sort(a,a+n*m,comp);
for(int i=0;i<n*m;i++){
	if(a[i]==R){
		t=i;
		break;
	}
}
int hang,lie=t/n+1;
if(lie%2==1){
	hang=t%n+1;
}else{
	hang=n-t%n;
}
cout<<lie<<" "<<hang;
fclose(stdin);
fclose(stdout);	
	
	return 0;
}