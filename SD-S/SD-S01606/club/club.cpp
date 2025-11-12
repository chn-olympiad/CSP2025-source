#include <bits/stdc++.h>
using  namespace std;
const int N=1e6+10;
int n;
int r1,r2,r3;
struct node{
	int a1,a2,a3;
}a[N],b[N],c[N]; 
bool cmp(node x,node y){
	return max(x.a1-x.a2,x.a1-x.a3)>max(x.a2-x.a1,x.a3-x.a1); 
}
bool cmp1(node x,node y){
	return max(x.a2-x.a1,x.a2-x.a3)>max(x.a1-x.a2,x.a3-x.a2);
}
bool cmp2(node x,node y){
	return max(x.a1-x.a3,x.a2-x.a3)<max(x.a3-x.a2,x.a3-x.a1) ;
}
int t;
long long sum;
inline int sl();
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		sl();
	}
	return 0;
} 
sl(){
	long long maxn;
	r1=r2=r3=sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a1>>a[i].a2>>a[i].a3;
		b[i].a1=a[i].a1,b[i].a2=a[i].a2,b[i].a3=a[i].a3;
		c[i].a1=a[i].a1,c[i].a2=a[i].a2,c[i].a3=a[i].a3;
	}
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp1);
	sort(c+1,c+n+1,cmp2);
	sum=a[1].a1+a[2].a1;
	maxn=max(maxn,sum);
	sum=a[1].a2+a[2].a2;
	maxn=max(maxn,sum);
	sum=a[1].a3+a[2].a3;
	maxn=max(maxn,sum);
	sum=a[1].a1+a[2].a2;
	maxn=max(maxn,sum);
	sum=a[1].a1+a[2].a3;
	maxn=max(maxn,sum);
	sum=a[1].a2+a[2].a3;
	maxn=max(maxn,sum);
	sum=a[1].a3+a[2].a2;
	maxn=max(maxn,sum);
	sum=a[2].a3+a[1].a1;
	maxn=max(maxn,sum);
	sum=a[2].a2+a[1].a3;
	maxn=max(maxn,sum);
	sum=a[2].a1+a[1].a1;
	maxn=max(maxn,sum);
	sum=a[2].a2+a[1].a2;
	maxn=max(maxn,sum);
	sum=a[2].a3+a[1].a3;
	maxn=max(maxn,sum);
	sum=a[2].a1+a[1].a2;
	maxn=max(maxn,sum);
	sum=a[2].a1+a[1].a3;
	maxn=max(maxn,sum);
	sum=a[2].a2+a[1].a3;
	maxn=max(maxn,sum);
	sum=a[2].a3+a[1].a2;
	cout<<maxn<<endl;
}
