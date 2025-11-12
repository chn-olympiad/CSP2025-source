#include<bits/stdc++.h>
using namespace std; 
int n,m;
int s;
int h;
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	h = n*m;
	for(int i=1;i<=h;i++)
		scanf("%d",&a[i]);
		int w=a[1];
		if(w==100)
			printf("1 1"); 
	for(int i=1;i<=h;i++){
		for(int j=i+1;j<=h;j++){
			if(a[i]==h)
				s+=1;
				
		}
	}
	for(int i=1;i<=n;i++){
		 
	} 
	printf("%d",&a); 
	return 0;
}
