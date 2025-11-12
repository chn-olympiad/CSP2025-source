#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int a[N],b[N];
int n,mx;
bool cz(int x){
	n%2==0;
	x<=n/2;
	return true;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("ciub.out","w",stdout);
	 cin>>n;
	 for(int i=1;i<=n;i++){
	 	cin>>b[i];
	 }
	 for(int i=1;i<=n;i++){
	 	int x;
	 	if(cz(1)){
	 	x=b[i];
		 }
		 mx+=x;
	 }
	 cout<<mx;
	return 0; 
} 