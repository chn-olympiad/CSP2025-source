#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1010],b[1010],c[1010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int f=a[1];
	int k=0;
		
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==f){
			k=i;
			break;
		}
	}
	//ÌØÊâÊý¾Ý 
	if(n==1){
		cout<<1<<" "<<k;
		return 0; 
	}
	if(m==1){
		cout<<k<<" "<<1;
		return 0;
	}
	
	
	
	int e=1;
	for(int i=1;i<=n*m;i++){
		c[i]=e;
		if(i%n==0){
			e++;
		}
	} 
	
	
	
	int q=1;
	for(int i=1;i<=n*m;i++){		 
		b[i]=q;
		if(q>=n){
			q=1;
		} else {
			q++;
		}
		//cout<<b[i]<<" ";
	}
	
	int o=n;
	if(n+1>=n*m-n){
		for(int i=n+1;i<=n*m;i++){		
			b[i]=o;
			if(o>1){
				o--;
			} else {
				o=n;
			}
		}
	} else {
		for(int i=n+1;i<=n*m-n;i++){		
			b[i]=o;
			if(o>1){
				o--;
			} else {
				o=n;
			}
		}
	}
	/*
	for(int i=1;i<=n*m;i++){
		cout<<b[i]<<" ";
	}
	*/
	int h,l;	
	h=c[k];
	l=b[k];
	cout<<h<<" "<<l;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
//2 2 
//99 100 97 98
//1 2

//2 2
//98 99 100 97
//2 2

//3 3
//94 95 96 97 98 99 100 93 92
//3 1
