#include<bits/stdc++.h>
using namespace std;
int num[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,numa,c=1,na,nm,a;cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>num[i];
		numa=num[0];
	}
	for(int i=1;i<n*m;i++){
		if(numa<num[i]){
			c++;
		}
	}
	a=c%(2*n);
	if(a==1 or a==2 or a==3 or a==4){
		na=a;
	}else{
		na=a+n-1;
	}
	if(double(c/n)==double(c/n)*n){
		nm=c/n;
	}else{
		nm=c/n+1;
	}
	cout<<nm<<" "<<na;
	fclose(stdin);
	fclose(stdout);
	return 0;
}  
          
