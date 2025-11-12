#include <bits/stdc++.h>
using namespace std;
int main(){
	int a[10005],b[10005],c[10005],n=2;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	n=a[2]*a[1];
	for(int i=1;i<=n;i++){
		cin >> b[i];
		
	}
	int pointxr=b[1];
	for(int i=1;i<=n;i++){
		int maxx=0,maxn=0;
		for(int j=1;j<=n;j++){
			if(b[j]>=maxx){
				maxx=b[j];
				maxn=j;
			}
		}
		b[maxn]=0;
		c[i]=maxx;
	}
	int xiaor=0;
	for(int i=1;i<=n;i++){
		if(c[i]==pointxr){
			xiaor=i;
		}
	}
	int zhengchuxr=xiaor/a[1];
	if(zhengchuxr*a[1]==xiaor){
		if(zhengchuxr%2==1){
			cout << zhengchuxr << " " << a[1]; 
		}
		else{
			cout << zhengchuxr << " " << 1;
		}

	}
	else{
		int yushuxr=xiaor-zhengchuxr*a[1];
		if(zhengchuxr%2==1){
			cout << zhengchuxr+1 << " " << a[1]-yushuxr+1; 
		}
		else{
			cout << zhengchuxr+1 << " " << yushuxr;
		}
	}
}
