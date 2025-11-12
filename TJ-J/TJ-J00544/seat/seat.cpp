#include<bits/stdc++.h>
using namespace std;
int a[10000];
bool px1(int f1,int f2){
	return f1>f2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int q;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	q=a[1];
	sort(a+1,a+n*m+1,px1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==q){
			q=i;
			break;
		}
	}
	int m1=q/n,n1;
	if(q%n!=0){
		int o=q%n;
		m1++;
		if(m1%2==0){
			n1=n-o+1;	
		}else{
			n1=o;
		}
	}else{
		if(m1%2==0){
			n1=1;
		}else{
			n1=n;
		}
	}
	cout<<m1<<" "<<n1;	
} 
