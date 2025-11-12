#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int b[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int k=b[1];
	sort(b+1,b+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(b[i]==k){
			k=i;
			break;
		}
	}
	int x,y;
	if(k%n==0){
		x=k/n;
	}
	else{
		x=(k-k%n)/n+1;
	}
	int c=k-(x-1)*n;
	if(x%2==0){
		y=n-c+1;
	}
	else{
		y=c;
	}
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
