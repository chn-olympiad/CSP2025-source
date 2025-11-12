#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int cnt=n*m;
	for(int i=1;i<=cnt;i++) scanf("%d",&a[i]);
	int ans=a[1];
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		if(a[i]==ans){
			int k=i%(2*n),j=i/n;
			if(k<=n && k!=0 && (i%n)!=0){
				printf("%d %d",j+1,k);
			}else if(k==0 || k==n){
				printf("%d %d",j,n);
			}else if(k>n){
				printf("%d %d",j+1,n-(k-n)+1);
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
}
