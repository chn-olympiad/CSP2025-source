#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int T, n, ans, c[4], sum, f;
bool zero1, zero2, zero3;
struct Node{
	int a, b, c;
}a[N];
bool cmp(Node x, Node y){
	return (x.a==y.a? (x.b==y.b? x.c>y.c: x.b>y.b): x.a>y.a);
}
void dfs(int i){
//	cout<<c[1]<<" "<<c[2]<<" : "<<sum<<"\n";
	if(i>n or c[1]+c[2]+c[3]>=n){
		ans=max(ans, sum);
		return;
	}
	if(c[1]+1<=n/2){
		c[1]++, sum+=a[i].a;
		dfs(i+1);
		c[1]--, sum-=a[i].a;
	}
	if(c[2]+1<=n/2){
		c[2]++, sum+=a[i].b;
		dfs(i+1);
		c[2]--, sum-=a[i].b;
	}
	if(!f and c[3]+1<=n/2){
		c[3]++, sum+=a[i].c;
		dfs(i+1);
		c[3]--, sum-=a[i].c;
	}
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>T;
	while(T--){
		zero1=zero2=zero3=1, f=c[1]=c[2]=c[3]=sum=ans=0;
		cin>>n;
		for(int i=1; i<=n; i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a!=0) zero1=0;
			if(a[i].b!=0) zero2=0;
			if(a[i].c!=0) zero3=0;
		}
		if(zero1){
			if(!zero3){
				swap(zero3, zero1);
				for(int i=1; i<=n; i++){
					swap(a[i].a, a[i].c);
				}
			}
			else if(!zero2){
				swap(zero2, zero1);
				for(int i=1; i<=n; i++){
					swap(a[i].a, a[i].b);
				}
			}
		}
		if(zero2 and zero3){//A
			sort(a+1, a+1+n, cmp);
			for(int i=1; i<=n/2; i++){
				ans+=a[i].a;
			}
			cout<<ans<<"\n";
			continue;
		}
		if(zero3){//B
			f=1;
			dfs(1);
			cout<<ans<<"\n";
			continue;
		}
//		for(int i=1; i<=n; i++){
//			cout<<a[i].a<<" "<<a[i].b<<" "<<a[i].c<<",\n";
//		}
		dfs(1);
		cout<<ans<<"\n";
	}
	
	return 0;
}
