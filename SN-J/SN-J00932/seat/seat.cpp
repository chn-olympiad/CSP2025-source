#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,sum,f;
struct node{
	int cj;
	int pm;
}a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)	cin>>a[i].cj;
	f=a[1].cj;
	for(int j=1;j<=1000;j++){
		for(int i=2;i<=n*m;i++){
			if(a[i].cj>a[i-1].cj){
				int l=a[i].cj,k=a[i-1].cj;
				a[i].cj=k;
				a[i-1].cj=l;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		a[i].pm=i;
		if(f==a[i].cj)	sum=a[i].pm;
	}
	cout<<(sum+n-1)/n<<" ";
	if(((sum+n-1)/n)%2==0) cout<<n-(sum/n)+1;
	if(((sum+n-1)/n)%2==1) cout<<(sum+n-1)%n+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
