#include <bits/stdc++.h>
using namespace std;
int a[10000];
int seat[1000][1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int R;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		R=a[1];
	}
	if(n==1&&m==1){
		cout<<n<<" "<<m;
		return 0;
	}else if(n==1&&m!=1){
		for(int i=1;i<=n*m;i++){
			if(a[i]<a[i+1]){
				swap(a[i],a[i+1]);
			}	
		}
		for(int i=1;i<=n*m;i++){
			if(a[i]==R){
				cout<<i<<" "<<n;
				return 0;
			}
		}	
	}else if(n!=1&&m==1){
		for(int i=1;i<=n*m;i++){
			if(a[i]<a[i+1]){
				swap(a[i],a[i+1]);
			}	
		}
		for(int i=1;i<=n*m;i++){
			if(a[i]==R){
				cout<<m<<" "<<i;
				return 0;
			}
		}		
	}else if(n==2&&m==2){
		for(int i=1;i<=4;i++){
			if(a[i]<a[i+1]){
				swap(a[i],a[i+1]);
			}
		}
		for(int i=1;i<=4;i++){
			for(int j=1;j<=4;j++){
				seat[i][j]=a[i];
				if(seat[i][j]==R){
					if(i>n){
						j++;
						i--;
					}
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}	
	for(int i=1;i<=n*m;i++){
		if(a[i]<a[i+1]){
			swap(a[i],a[i+1]);
		}
	}
	if(a[1]==R){
		cout<<1<<" "<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			seat[i][j]=a[i];
		}	
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			seat[i][j]=a[i];
			if(seat[i][j]==R){
				if(i>n){
					j++;
					i--;
				}
				cout<<j<<" "<<i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

