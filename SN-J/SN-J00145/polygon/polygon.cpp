#include<bits/stdc++.h>
using namespace std;
int m,n;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	std::ifstream cin("polygon.in");
	std::ofstream cout("polygon.out");
	cin>>m>>n;
	int b[m*n+1],sum=0;
	for(int i=0;i<m*m;i++){
		cin>>b[i];
	}
	sum=b[0];
	sort(b+0,b+m*n,cmp);
	for(int i=0;i<n*m;i++){
		if(b[i]==sum) sum=i;
	}
	if()
	return 0;
}
