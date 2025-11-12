#include<bits/stdc++.h>
using namespace std;
int a[10009];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int find;
	int n,m,zhz;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		
		cin >> a[i];
		if(i==1) zhz=a[i];
	}
	sort(a,a+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		
		if(a[i]==zhz) find=i+1;
		
	}
	int q=2*n;

	q=find%q;
	if(q==1) cout << find/n+1<< " "<< 1;
	else if(q==n) cout << find/n<< " "<< n;
	else if(q>1 && q<n) cout << find/n<< " "<< n;
	else if(q==0) cout << (find/n)+1<< " "<< 1;
	else cout << (find/n)+1<< " "<< (n-find%n)+1;
	return 0;
} 
