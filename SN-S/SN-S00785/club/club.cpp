#include<bits/stdc++.h>
using namespace std;
int cl[100004];
int sum;
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		 cin>>n;//你皂中回入鸟？A.皂 B.木星 C.木识首 
		 for(int i=0;i<n;i++){
		 	cin>>cl[i];
			 int aaa,bbb;
			 cin>>aaa>>bbb; 
		 }
		 sort(cl,cl+n);
		 for(int i=0;i<n/2;i++){
		 	sum+=cl[i];
		 }
		 cout<<sum;
		 sum=0;
		 for(int i=0;i<n;i++){
		 	cl[i]=0;
		 }
	}
}//memset咋用 
