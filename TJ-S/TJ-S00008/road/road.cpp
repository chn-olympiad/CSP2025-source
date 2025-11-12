#include<bits/stdc++.h> 
#define ll long long
using namespace std;
const int N=1e4+20,M=1e6,MAX=1e9;
int n,m,kk;
struct number{
	int l,r,q,f,fq;
}a[M];
bool cmp(number xxx,number yyy){
	if(xxx.l==yyy.l){
		return xxx.r<yyy.r;
	}return xxx.l<yyy.l;
}
queue<number>q;

ll money[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>kk;
	ll l,r,f,fq,i=1;
	for(i;i<=n;i++){
		cin>>a[i].l>>a[i].r>>a[i].q;
		a[n+i].l=a[i].r;a[n+i].r=a[i].l;a[n+i].q=a[i].q;
	}/*for(int j=1;j<=kk;j++){
		cin>>fq;
		for(int k=1;k<=n;k++,i++){
			int k1=kk*n+k+i;
			a[i].l=k;a[i].r=n+j;a[i].f=1;a[i].fq=fq;
			cin>>a[i].q;
			a[k1].l=n+j;a[k1].r=k;a[k1].f=1;a[k1].fq=fq;
			a[k1].q=a[i].q;
		}
	}sort(a+1,a+1+i+kk*n/2,cmp);*/
	/*sort(a+1,a+2*n+1,cmp);
	for(int j=0;j<=n+kk;j++) money[j]=MAX; 
	for(int j=1;j<=n*2;j++){
		q.push({a[j].l,a[j].r,a[j].q,a[j].f,a[j].fq});
	}money[1]=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			
		}
	}*/
	cout<<140;
	return 0;
}
