#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=0,m=0;
	cin>>n>>m;
	int seat[120]={0};
	for(int i=1;i<=n*m;i++){
		cin>>seat[i];
	}
	int r=seat[1];
	sort(seat+1,seat+1+n*m);
	//for(int i=1;i<=n*m;i++){
	//	cout<<seat[i];
	//}
	//cout<<endl<<r;
	int ans=0;
	for(int i=n*m;i>=1;i--){
		if(r==seat[i]){
			//cout<<endl<<seat[i];
			ans=n*m-i+1;
			break;
		}
	}
	int g=0;
	//cout<<endl<<ans<<endl;
	if(ans%n==0){
		g=ans/n;
		cout<<ans/n<<' ';
	}else{
		g=ans/n+1;
		cout<<ans/n+1<<' ';
	} 
	//cout<<g;
	//cout<<ans<<endl; 
	if(g%2==1){
		cout<<ans%n;
	} 
	else{
		cout<<n-ans%n+1;
	} 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2 2
99 100 97 98
*//*
3 3
94 95 96 97 98 99 100 93 32
*//*
5 5
12 1 2 3 4 5 6 7 8 9 10 11 13 14 15 16 17 18 19 20 21 22 23 24 25
*/

