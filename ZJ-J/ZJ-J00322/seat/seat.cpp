#include<bits/stdc++.h>
using namespace std;
const int N=15;
int a[N*N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
    	scanf("%d",&a[i]);
	}
	int r=a[1];
	sort(a+1,a+n*m+1);
	int cnt=0;
	for(int i=n*m;i>=1;i--){
		cnt++;
		if(a[i]==r){
			break;
		}
	}
//	cout<<"cnt="<<cnt<<endl;
	if(cnt%n==0){
		int l=cnt/n;
		if(l%2==0){
			printf("%d 1",l);
		}
		else{
			printf("%d %d",l,n);
		}
	}
	else{
		int k=cnt/n;
		int l=k+1;
		if(l%2==0){
			printf("%d %d",l,n-(cnt-k*n)+1);
		}
		else{
			printf("%d %d",l,cnt-k*n);
		}
	}
	return 0;
}
