#include<bits/stdc++.h>
using namespace std;
int main{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s;
	cin>>s;
	int a[10000];
	a[1]=s;
	for(int i=2;i<=n*m-1;i++){
		int q;
		cin>>a[i];
		for(int j=i;j<=1;j--){
			if(a[j]>a[j-1]){
			q=a[j-1];
			a[j-1]=a[j];
			a[j]=q;
		}
		}
		
	}
	int p;
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			p=i;
		}
	}
	if(p/n%2==0){
		cout<<p/n+1<<p%n;
	}eles if(p/n%2==1){
		cout<<p/n+1<<n-p%n;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
