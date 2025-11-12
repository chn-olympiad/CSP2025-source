#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[10000];
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int v=a[0];
	for(int i=0;i<n*m;i++){
		for(int j=0;j<n*m;j++){
			if(a[j+1]>a[j]){
				swap(a[j+1],a[j]);
			}
		}
	}
	int w,h,l,c=0;
	for(int i=0;i<n*m;i++){
		if(a[i]==v){
			w=i+1;
			break;
		}
	}
	if(w%n==0){
		l=w/n;	
	}else{
		l=w/n+1;
	}
	if(l%2==0){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				c+=1;
				if(w==c){
					h=n+1-j;
				}
			}
		}
	}else{
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				c+=1;
				if(w==c){
					h=j;
				}
			}
		}
	}
	cout<<l<<" "<<h<<endl;
	return 0;
} 
