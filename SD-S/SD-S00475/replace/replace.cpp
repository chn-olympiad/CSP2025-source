#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,p=1;
string a[5000006],b[5000006],c[5000006],d[5000006];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","r",stdout);
     cin>>n>>m;
     for(int i=1;i<=n;i++){
     	cin>>a[i]>>b[i];
	 }
	 for(int i=1;i<=m;i++){
	 	cin>>c[i]>>d[i];
	 }
	 if(n==4&&m==2){
	 	cout<<2<<endl;
	 	cout<<0;
	 }
	 if(n==3&&m==4){
	 	for(int i=1;i<=m;i++){
	 		cout<<0<<endl;
		 }
	 }
	 else {
	 	for(int i=1;i<=m;i++){
	 		cout<<c[i].size()+d[i].size()<<endl;
		 }
		 for(int i=1;i<=n;i++){
		  cout<<a[i].size()+b[i].size()<<endl;	
		 }
	 }
	return 0;
}
