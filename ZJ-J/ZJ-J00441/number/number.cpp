#include<bits/stdc++.h>
using namespace std;
vector<int>a;
long long tong[20];
bool cmp(int x,int y){
	return x>y;}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char c;int d;
	while(cin>>c){
		d=int(c);
		//cout<<c<<' '<<int(c)<<endl;
		if(48<=d && d<=57){
			a.push_back(d-48);}}
	for(int i=0;i<a.size();i++){
		tong[a[i]]++;}
	for(int i=9;i>=0;i--){
		while(tong[i]--) cout<<i;}
	fclose(stdin);fclose(stdout);
	return 0;}