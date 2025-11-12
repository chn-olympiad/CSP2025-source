#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int maxn,l,l2,maxm;
}a[100001];
bool cmp(node a,node b){
	return a.maxn>b.maxn;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	while(n--){
		int t;
		cin>>t;
		for(int i=1;i<=t;i++){
			int x,y,z;
			cin>>x>>y>>z;
			if(x>y&&x>z){
				a[i].maxn=x;
				a[i].l=1;
				a[i].maxm=max(y,z);
				if(a[i].maxm==y){
					a[i].l2=2;
				}
				else{
					a[i].l2=3;
				}
			}
			else if(y>x&&y>z){
				a[i].maxn=y;
				a[i].l=2;
				a[i].maxm=max(x,z);
				if(a[i].maxm==x){
					a[i].l2=1;
				}
				else{
					a[i].l2=3;
				}
			}
			else{
				a[i].maxn=z;
				a[i].l=3;
				a[i].maxm=max(x,y);
				if(a[i].maxm==x){
					a[i].l2=1;
				}
				else{
					a[i].l2=2;
				}
			}
		}
		sort(a+1,a+t+1,cmp);
		int b[3]={0,0,0};
		int cnt=0;
		for(int i=1;i<=t;i++){
			if(b[a[i].l]<=t/2){
				b[a[i].l]++;
				cnt+=a[i].maxn;
			}
			else{
				b[a[i].l2]++;
				cnt+=a[i].maxm;
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
