#include<bits/stdc++.h>
using namespace std;
int grade[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,f,n1,m1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>grade[i];
	}
	f=grade[1];
	for(int i=1;i<=n*m;i++){
		if(grade[i]<grade[i+1]){
			swap(grade[i],grade[i+1]);
		}
	}
	for(int i=1;i<=n*m;i++){
		if(f==grade[i]){
			f=i;
			break;
		}
	}
	if(f%n==0){
		m1=f/n;
	}else{
		m1=f/n+1;
	}
	if(m1%2==0){
		if(f%n==0){
			n1=1;
		}else{
			n1=n-(f%n-1);
		}
		
	}else{
		if(f%n==0){
			n1=n;
		}else{
			n1=f%n;
		}
	}
	cout<<m1<<" "<<n1;
	return 0;
}
