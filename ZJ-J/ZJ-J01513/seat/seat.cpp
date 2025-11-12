#include<bits/stdc++.h>
using namespace std;

int n,m,d;
int a[110];

bool cmp(int a,int b){return a>b;}

int h(){
	int l=1,r=n*m;
	while(l<r){
		int mid=(l+r)/2;
		if(a[mid]<d) r=mid-1;
		else if(a[mid]>d) l=mid+1;
		else return mid;
	}
	return l;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&a[1]);
	d=a[1];
	for(int i=2;i<=n*m;i++) scanf("%d",&a[i]);
	sort(a+1,a+(n*m)+1,cmp);
	int f=h();
	if(f%(2*n)<=n){
		cout<<(f+m-1)/m<<" ";
		if(f%m==0) cout<<m;
		else cout<<f%m;
	}
	else cout<<(f+m-1)/m<<" "<<m-(f%m)+1;
	return 0;
}