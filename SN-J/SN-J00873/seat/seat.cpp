#include<bits/stdc++.h>
using namespace std;
int b[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int r=b[1],d=0;	
	sort(b+1,b+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(b[i]==r){
			d=i;
			break;
		}
	}
	if(d%n!=0){
		int f=d/n+1;
		cout<<f<<" ";
		if(f%2==0){
			cout<<n-d%n+1;
		}
		else{
			cout<<d%n;
		}	
	}
	else{
		int f=d/n;
		cout<<f<<" ";
		if(f%2==0){
			cout<<"1";
		}
		else{
			cout<<n;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
