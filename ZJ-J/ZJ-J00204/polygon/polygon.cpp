#include <bits/stdc++.h>
using namespace std;
#define fr1(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define fr2(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define md %998244353
const int maxn=5e3+10;
long long sum=0;
int n,a[maxn];
struct node {
	int v,c,s;
};
queue<node> q;
inline long long c(int n,int i) {
	long long ans=1;
	fr1(j,i+1,n)ans=(ans*j)md;
	fr1(j,2,n-i)ans/=j;
	return ans;
}
void bfs() {
	while(!q.empty()) {
		node p=q.front();
		q.pop();
		fr1(i,p.c+1,n) {
			node p2=p;
			p2.v+a[i],p2.c=i,p2.s=p2.s*10+i;
			if(p2.v<=a[i]*2){
				sum--;
				if(sum==-1)sum=998244352;
				q.push(p2);
			}
		}
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	fr1(i,1,n)cin>>a[i];
	sort(a+1,a+1+n);
	if(n==3){
		if(a[i]+a[j]+a[k]>max(max(a[i],a[k]),a[j])*2)cout<<1;
		return 0;
	}else{
		long long p=c(n,3);
	fr1(i,3,n) {
		sum=(sum+p)md;
		p=p*(n-i-1)/(i+1);
	}
	node p2;
	fr1(i,1,n-2)fr1(j,i+1,n-1)fr1(r,j+1,n)if(a[i]+a[j]+a[r]<=a[r]*2) {
		sum--;
		if(sum==-1)sum=998244352;
		p2.v=a[i]+a[j]+a[r],p2.c=r,p2.s=i*100+j*10+r;
		q.push(p2);
	}
	bfs();
	cout<<sum;
	return 0;
	}
	
}
