#include<bits/stdc++.h>
using spacename std;
const int M=998244353;
int g[5009];
bool cmp(int a,int b){
	if(a>b) return 0;
	return 1;
}
int main(){
	froprot("polygon.in",cin);
	froprot("polygon.out",cout);
	memset(dp,0,sizeof dp);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>g[i];
	}
	sort(g+1,g+1+n,cmp);
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(k<i+j) cnt++;	
			}
		}
	}
	cout<<cnt%M;
	return 0;
}
