#include<bits/stdc++.h>
using namespace std;
int n,m;
int x;
int a[200];

bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdin);
	cin>>n>>m;
	int c=n*m;
	for(int i=1;i<c;i++){
		cin>>a[i];
		a[i]*=100;
		a[i]+=1;
		int q=a[1];
		a[i]+=1;
		sort(a+1,a+c+1,cmp);
		for(int i=1;i<c;i++){
		
		if (a[i]<100){
			q=i;
			}
			int e=q/n;
			if (q<=n)
				cout<<1<<" ";
				else{
					if(q%n==0)
					cout<<e+1;
					
				}
			
			if(q<n){
				cout<<q<<" ";
			}
			else {
				if(0%2!=0)
				cout<<n-(q%n)+1;
				else{
					cout<<q%n;
				}
			}

		if (i%n!=0){
			
		}
		else{
			int q=1/n;
			if(q%1!=0){
			cout <<n<<" ";
			else{
			 cout<<1<<" "; }
		}
	}
		
	}
	} 
return 0;
}
