#include<bits/stdc++.h>
using namespace std;
long long a[1000005][100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,m,g;
	cin>>t;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];}}
	for(int i=1;i<=n;i++){
		if(a[i][1]>a[i][2]&&a[i][2]>a[i][3]){
			if (n<t/2){
				n++;}
			else{
				if(a[i][2]>a[i][3]){
					if(n<t/2) m++;
					else g++;}
				else{
					if(n<t/2) g++;
					else m++;}}}
		else if(a[i][2]>a[i][3]){
			if (n<t/2) m++;
			else{
				if(a[i][1]>a[i][3]){
					if(m<t/2) n++;
					else g++;}}}
		else{
			if (n<t/2) g++;
			else{
				if(a[i][1]>a[i][2]){
					if(m<t/2) n++;
					else m++;}}
		cout<<n<<endl<<m<<endl<<g;}return 0;}}
