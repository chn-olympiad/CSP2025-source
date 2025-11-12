#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,m,ml;
int a[N];
bool zc(int x){
	if(x=1)
	return true;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	 string a;
	 cin>>n>>m;
	  cin>>a;
	 for(int i=0;i<=n;i++){
	 	cin>>a[i];
	 }
	 for(int i=0;i<=n;i++){
	 	if(zc(1)){
	 		ml<a[i];
	 		ml=i;
		 }
		 i++;
	 }
	 cout<<ml;
	return 0; 
} 