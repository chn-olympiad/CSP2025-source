#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int a[20][20];
int b[1000];
int k;
bool cmp(int x,int y){
	return x>y;
	
}
bool f=1;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	int p=m*n;
	int k=0;
	for(int i=1;i<=p;i++){
		
		cin>>b[i];
		if(f==1){
			k=b[i];
			f=0;
		}
	}
	f=1;
	int cnt=1;
	int e,r;
	sort(b+1,b+p+1,cmp);
	
	
	int o=0;
	for(int i=1;i<=p;i++){
		if(i%n==1){
			o++;
		}
		
		if(b[i]==k){
			if(o%2==0){
				e=n-i%n+1;
				r=o;
				if(e==0){
					e=n;
				}
				cout<<r<<" "<<e;
				break;
			}
			else if(o%2==1){
				e=i%n;
				if(e==0){
					e=n;
				}
				r=o;
				cout<<r<<" "<<e;
				break;
			}
			
		}
	}
	
	return 0;
}
