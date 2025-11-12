#include<bits\stdc++.h>
using namespace std;
int n,m,c[100000];
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>c[i];
	}
	int x=c[1];
	for(int i=0;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(c[j]<c[j+1]){
				int q=c[j];
				c[j]=c[j+1];
				c[j+1]=q;
			}		
		}
	}
	int p;
	for(int i=0;i<=n*m;i++){
		if(c[i]==x) p=i;
	}
	int l; 
	if(p%n!=0) l=(p/n)+1;
	else l=p/n;
	int h;
	if(l%2==0) h=m-(p%n);
	else if(p%n!=0) h=p%n;
	else h=p;
	cout<<l<<" "<<h;
	return 0;
}
