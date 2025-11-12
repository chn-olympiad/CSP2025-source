#include<bits/stdc++.h>

using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	cin>>n>>m>>r;
	a[1]=r;
	for(int i=2;i<=n*m-1;i++){
		cin>>a[i];
		
	}
	for(int i=1;i<n*m-1;i++){
		for(int j=i;j<=n*m-1;j++){
			if(a[j]<a[j+1]){
				int e=a[j];
				a[j]=a[j+1];
				a[j+1]=e;
			}
		}
	}
	int e=1;
	for(int i=1;r!=a[i];i++){
		e++;
	}
	int s=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s==e){
				cout<<j<<" "<<i<<endl;
				
			}
			s++;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
