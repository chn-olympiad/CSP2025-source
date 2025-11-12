#include<bits/stdc++.h>
using namespace std;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	int a[105];
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	
	int r=a[1];
	int paiming=0;
	
	sort(a+1,a+n*m+1,cmp);
	
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
	
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			paiming=i;
		}
	}
	
//	cout<<r<<" "<<paiming<<endl;
	
	int lie=paiming/n+1;
	if(paiming%n==0){
		lie--;
	}
	
//	cout<<lie<<endl;
	
	int hang;
	if(lie%2==0){
		hang=lie*n-paiming+1;
	}
	else{
		if(paiming%n==0){
			hang=n;
//			cout<<1<<endl;
		}else{
			hang=paiming-n*(lie-1);
//			cout<<2<<endl;
		}
	}
	
	
	cout<<lie<<" "<<hang;
	
	
	return 0;
}




