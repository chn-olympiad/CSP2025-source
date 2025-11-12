#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	//SN-J00334,张屹然，铁一中
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+n*m+1,cmp);
	int w;
	for(int i=1;i<=n*m;i++){
		if(k==a[i]){
			w=i;
			break;
		}
	}
	if(w%n==0){
		if(w/n%2==1){
			cout<<w/n<<' '<<n;
		}
		else cout<<w/n<<' '<<1;
	}
	else{
		if(w/n%2==1){
			cout<<w/n+1<<' '<<n-(w-w/n*n)+1;
		}
		else cout<<w/n+1<<' '<<w-w/n*n;
	}
	return 0;
}
