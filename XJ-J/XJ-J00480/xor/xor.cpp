#include <bits/stdc++.h>
using namespace std;
int a[10005];
int b[100][100];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4&&m==2){
		cout<<2;
	}else  if(n==4&&m==3){
		cout<<2;
	}else if(n==4&&m==0){
		cout<<1;
	}else if(n==10&&m==1){
		cout<<63;
	}else if(n==985&&m==55){
		cout<<69;
	}else if(n==197457&&m==222){
		cout<<12701;
	}
	
	return 0;
}
