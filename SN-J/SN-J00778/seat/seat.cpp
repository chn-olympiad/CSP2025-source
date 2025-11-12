#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int p=n*m;
	int c;
	int y;
	int g=1;
	int n1,m1;
	for(int i=1;i<p;i++){
		cin>>c;
		if(i>0){
			if(c>y){
				g++;
			}
		}
		y=c;
	}
	m1=c/m;
	int u=c%m;
	if(n>m){
		n1=u-n;
	}else{
		n1=n-u;
	}
	cout<<n<<" "<<m;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
