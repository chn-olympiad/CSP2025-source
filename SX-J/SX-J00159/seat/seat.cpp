#include <bits/stdc++.h>
using namespace std;

int a[105],b[105];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int goal=a[1];
	sort(a+1,a+n*m+1);
	for (int i=1;i<=n*m;i++){
		b[i]=a[n*m-i+1];
	}
	int h=1,l=1,t=0;
	for (int i=1;i<=n*m;i++){
		int hi=h,li=l;
		if (b[i]==goal){
			printf("%d %d",li,hi);
			return 0;
		}
		if(t==0){
			h++;
			if (h==n+1){
				l++,h=n,t=1;
			}
		}
		else{
			h--;
			if (h==0){
				l++,h=1,t=0;
			}
		}
 	}
	return 0;
}