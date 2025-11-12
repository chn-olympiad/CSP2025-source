#include<bits/stdc++.h>
using namespace std;
int a[500000];
void w(int a,int n,int e[]){
	int c;
	int z=0;
	int d=a%2;
	if(d!=0){
		c=a/2;
		e[n]=d;
		n--;
		z++;
		w(c,n,e[]);
	}
	
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,k,s=0,l,r,h=0,t=n;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]=k){
			s++;
			h++;
		}
		else {
			l=i;
			break;
		}
	}
	for(int i=n;i>=1;i--){
		if(h==t) break;
		if(a[i]=k){
			s++;
			t--;
		}
		
		else {
			r=i;
			break;
		}
	}
	for(int i=l+1;i<=r;i++){
		int b[9];
		w(i-1,9,b[]);
		int c[9];
		w(i,9,c[]);
		int d[9];
		for(int i)
	}
	cout<<s;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
