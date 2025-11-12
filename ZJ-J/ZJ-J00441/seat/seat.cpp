#include<bits/stdc++.h>
using namespace std;
vector<int>ve;
bool cmp(int x,int y){
	return x>y;}
void sss(){
	int n,m,b=0,c=0,num=0,x=0,y=0;cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b;
		if(i==1) c=b;
		ve.push_back(b);}
	sort(ve.begin(),ve.end(),cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				num++;
				if(ve[num-1]==c){
					cout<<i<<' '<<j;
					return ;}
				}}                     
				                       
		if(i%2==0){
			for(int j=n;j>=1;j--){
				num++;
				if(ve[num-1]==c){
					cout<<i<<' '<<j;
					return ;}
				}}
				}}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	sss();
	fclose(stdin);fclose(stdout);
	return 0;}