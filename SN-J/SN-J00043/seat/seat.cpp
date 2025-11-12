#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,a[101],p;
	cin>>m>>n;
	scanf("%d",&m,&n);
	for(int i=1;i<=n;i++){
		cin>>a[101];
		fclose(stdin);
		fclose(stdout);
	}
	for(int i=1;i<=1;i++){
		for(int j=1;j<=n;j++){
			for(int s=1;s<=n;s++){
				if(a[s]>a[j]){
					swap(a[s],a[j]);
				}
			}
		}
	}for(int i=1;i<=m*n;i++){
		if(a[i]==p){
			cout<<a[p];
		}
	}
	for(int x=1;x<=n;x++){
		if(x==m*n){
		a[x]=a[p]*x;
		cout<<a[x];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
