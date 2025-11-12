#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105],rg,id;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	rg=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==rg){
			id=i;
			break;
		}	
	}
	
	int x,y;
	x=(id-1)/n+1;
	if(x%2==1){
		y=id-(x-1)*n;
	}else{
		y=m+1-(id-(x-1)*n);
	}
	cout<<x<<' '<<y;
	fclose(stdin);
	fclose(stdout);
	
	
	return 0;
}
