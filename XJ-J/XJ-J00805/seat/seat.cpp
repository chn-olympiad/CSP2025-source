#include <bits/stdc++.h>
using namespace std;
int a[200]={};
int b[200][200]={};
bool cmp(int x ,int y){
	return x>=y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a[1];
	int num=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int p=0;
	while(a[p]!=num){
		p++;
	}
	int x=(p-1)/n;
	int y=p-x*n;
	if(x%2==1){
	 	cout<<x+1<<" "<<m+1-y;
	}
	else{
		cout<<x+1<<" "<<y;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
