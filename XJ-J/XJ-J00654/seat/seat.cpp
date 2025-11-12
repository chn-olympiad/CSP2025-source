#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int s[10][10]={};
	int m,n;
	cin>>n>>m;
	int e[m*n]={};
	for(int i=1;i<=n*m;i++){
		cin>>e[i];	
	}
	int count=1;
	for(int i=2;i<=m*n;i++){
		if(e[1]<e[i]) count++;
	}
	int c,r;
	r=count%(2*n);
	if(count%(2*n)>n) r=(2*n)-r+1;
	c=count/(2*n)+1;
	if(count%(2*n)>n) c++;
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
