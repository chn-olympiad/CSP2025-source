#include<bits/stdc++.h>
using namespace std;
int n,m;
int ha,le;
int a[10000]={};
bool cmd(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<= n*m;i++){
		cin >>a[i];
	}
	int b=a[1],cn=0;
	sort(a+1,a+n*m+1,cmd);
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			cn=i;
			break;
		}
	}
	if(((cn-1)/n+1)%2!=0){
		le= (cn-1)/n+1;
		ha= (cn-1)%n+1;
	}
	else{
		le= (cn-1)/n+1;
		ha= (cn-1)%n+1;
		ha= n+1-ha;
	}
	cout <<le<<" "<<ha;
	return 0;
}
