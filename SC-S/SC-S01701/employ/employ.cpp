#include<bits/stdc++.h>
using namespace std;
int n,m,c[510],num;
char a[510];
int cmp(int x,int y){
	return x>y;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]='0'){
			num++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+1+n,cmp);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	if(n-num<m){
		cout<<0;
	}
	if(n-num==m){
		for(int i=1;i<=n;i++){
			if(c[i]<n-i+1){
				cout<<0;
			}
		}
	}
//	if(n-num>m){
//		for(int i=1;i<=n;i++){
//			if()
//		} 
//	}

	
	return 0;	
}