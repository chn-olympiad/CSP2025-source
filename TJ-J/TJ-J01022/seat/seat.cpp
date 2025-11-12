#include<bits/stdc++.h>
using namespace std;
int n,m;
int q,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	q=n*m;
	int a[q];
	for(int i=1;i<=q;i++){
		cin>>a[i];
	}
	int r=a[1];
	for(int i=1;i<=q;i++){
		if(a[i]>=a[i+1]){
			continue;
		}else if(a[i]<a[i+1]){
			l=a[i];
			a[i]=a[i+1];
			a[i+1]=l;
			l=0;
		}
	}
	for(int i=1;i<=q;i++){
		if(a[i]>=a[i+1]){
			continue;
		}else if(a[i]<a[i+1]){
			l=a[i];
			a[i]=a[i+1];
			a[i+1]=l;
			l=0;
		}
	}
	for(int i=1;i<=q;i++){
		if(a[i]>=a[i+1]){
			continue;
		}else if(a[i]<a[i+1]){
			l=a[i];
			a[i]=a[i+1];
			a[i+1]=l;
			l=0;
		}
	}
	for(int i=1;i<=q;i++){
		if(a[i]>=a[i+1]){
			continue;
		}else if(a[i]<a[i+1]){
			l=a[i];
			a[i]=a[i+1];
			a[i+1]=l;
			l=0;
		}
	}
	for(int i=1;i<=q;i++){
		if(a[i]>=a[i+1]){
			continue;
		}else if(a[i]<a[i+1]){
			l=a[i];
			a[i]=a[i+1];
			a[i+1]=l;
			l=0;
		}
	}
	for(int i=1;i<=q;i++){
		if(a[i]>=a[i+1]){
			continue;
		}else if(a[i]<a[i+1]){
			l=a[i];
			a[i]=a[i+1];
			a[i+1]=l;
			l=0;
		}
	}
	for(int i=1;i<=q;i++){
		if(a[i]>=a[i+1]){
			continue;
		}else if(a[i]<a[i+1]){
			l=a[i];
			a[i]=a[i+1];
			a[i+1]=l;
			l=0;
		}
	}
	for(int i=1;i<=q;i++){
		if(a[i]>=a[i+1]){
			continue;
		}else if(a[i]<a[i+1]){
			l=a[i];
			a[i]=a[i+1];
			a[i+1]=l;
			l=0;
		}
	}
	for(int i=1;i<=q;i++){
		if(a[i]>=a[i+1]){
			continue;
		}else if(a[i]<a[i+1]){
			l=a[i];
			a[i]=a[i+1];
			a[i+1]=l;
			l=0;
		}
	}
	int lie;
	int hang;
	for(int i=1;i<=q;i++){
		if(a[i]==r){
			lie=i/n;
			if(i%n!=0){
				lie+=i/n;
			}
			if(i<=m){
		
			hang=i;	
			}
			else{
				hang=i%m;
			}
			
			cout<<lie<<' '<<hang;
			return 0;
		}
	}
	return 0;
} 
