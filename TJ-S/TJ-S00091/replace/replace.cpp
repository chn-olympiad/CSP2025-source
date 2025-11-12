#include<bits/stdc++.h>
using namespace std;
int n,p,m,b1,b2,q,c;
string a[3][100001],b[3][100001];
void in(int d){
	while(true){
		q++;
		if(b[1][d][q]==0){
			b1=q;
		}
	}
	while(true){
		q++;
		if(b[2][d][q]==0){
			b2=q;
		}
	}
	c=b1-b2;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[1][i]>>a[2][i];
	}
	for(int i=1;i<=m;i++){
		cin>>b[1][i]>>b[2][i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			in(j);
			
		}
	}
	for(int i=1;i<=m;i++){
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
