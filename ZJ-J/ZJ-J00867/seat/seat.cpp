#include<bits/stdc++.h>
using namespace std;
short n,m,a[105],s,c=1,r=1;
bool cmp(short x,short y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%hd %hd",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%hd",&a[i]);
	s=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			printf("%hd %hd",c,r);
			break;
		}
		if(c%2){
			r++;
			if(r>n)
				r--,c++;
		}else{
			r--;
			if(r<1)
				r++,c++;
		}
	}
	return 0;
}