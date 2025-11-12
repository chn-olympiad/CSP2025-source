#include <bits/stdc++.h>
using namespace std;
int t,n,sum,ans;
struct Node{
	int a,b,c,to;
}a[100005];
bool cmp(Node x,Node y){
	if(x.a!=y.a)return x.a>y.a;
	else return x.b<y.b;
}
bool cmp2(Node x,Node y){
	if(x.b!=y.b)return x.b>y.b;
	else return x.a<y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			a[i].to=1,sum+=a[i].a;
		}
		ans=sum;
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;i++){
			if(a[i].to==0){
				a[i].to=2;
				ans+=a[i].b;
			}
		}
	}
	cout<<ans;
	return 0;
}
