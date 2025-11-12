#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int n,m,a[105],xx,x1,yu;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	x1=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x1){
			xx=i;
			break;
		}
	}
	cout<<(xx+n-1)/n<<' ';
	yu=xx%n;
	if(((xx+n-1)/n)%2==1){
		if(yu==0){
			cout<<n;
		}else{
			cout<<yu;
		}
	}else{
		if(yu==0){
			cout<<1;
		}else{
			cout<<n-yu+1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
