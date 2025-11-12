#include<bits/stdc++.h>
using namespace std;
int m,n,c,r;
int b[101];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int ans=b[1];
	sort(b+1,b+n*m+1,cmp);
	int k;	
	for(int i=1;i<=n*m;i++){
		if(b[i]==ans){
			k=i;
			break;
		}
	}
	if(k%n!=0){
		c=k/n+1;
	}
	else{
		c=k/n;
	}
	if(c%2!=0){
		r=k-(n*(c-1));
	}
	else{
		r=n+1-(k-(n*(c-1)));
	}
	cout<<c<<' '<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
