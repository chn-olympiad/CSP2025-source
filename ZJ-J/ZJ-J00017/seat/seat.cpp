#include<bits/stdc++.h>
using namespace std;
int n,m,a[105]={};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int num=a[1],p=0;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==num){
			p=n*m-i+1;
		}
	}
	if(((p-1)/n)%2==0){
		cout<<(p-1)/n+1<<' '<<(p-1)%n+1;
	}
	else{
		cout<<(p-1)/n+1<<' '<<n-(p-1)%n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

