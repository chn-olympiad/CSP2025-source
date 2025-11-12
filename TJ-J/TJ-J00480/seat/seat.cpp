#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,sym;
	cin>>n>>m;
	int grade[n*m];
	
	for (int i=0;i<n*m;i++){
		cin>>grade[i];
	}
	r=grade[0];
	sort(grade,grade+n*m);
	for (int i=0;i<n*m;i++){
		if (r==grade[i]){
			sym=n*m-i;
		}
	}
	int x,y,z=0;
	if (sym%n==0){
		x=sym/n;
		z=1;
	}else{
		x=sym/n+1;
	}
	if (x%2==1){
		if (z==1){
			y=n;
		}else{
			y=sym%n;
		}
	}else{
		if (z==1){
			y=1;
		}else{
			y=n-(sym%n-1);
		}
	}
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
