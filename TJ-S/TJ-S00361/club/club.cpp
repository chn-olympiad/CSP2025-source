#include<bits/stdc++.h>
using namespace std;
struct node{
	int a, b, c;
	int x, y, z;
	int maxn1=0, maxn2=0, maxn3=0;;
}a[100005];

int main(){
//	freopen("club.in", "r", stdin);
//	freopen("club.out", "w", stdout);
	int t;
	cin>>t;
	int c1=0, c2=0, c3=0;
	while (t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a>a[i].b&&a[i].a>a[i].c){
				a[i].maxn1=a[i].a;
				c1++;
			}
			else if(a[i].b>a[i].a&&a[i].b>a[i].c){
				a[i].maxn2=a[i].b;
				c2++;
			}
			else{
				a[i].maxn3=a[i].c;
				c3++;
			}
		}
		
		int v1=0, v2=0, v3=0;
		for(int i=1;i<=n;i++){
			if(c1<=n/2&&c2<=n/2&&c3<=n/3){
				cout<<a[i].maxn1+a[i].maxn2+a[i].maxn3<<endl;
				break;
			}
			for(int j=1;j<=n;j++){
				if(c1>n/2){
					if(a[i].maxn1<=a[i+1].maxn1){
						v1=i;
					}
				}
				if(c2>n/2){
					if(a[i].maxn2<=a[i+1].maxn2){
						v2=i;
					}
				}
				if(c3>n/2){
					if(a[i].maxn3<=a[i+1].maxn3){
						v3=i;
					}
				}
			}
			a[v1].maxn1=0;a[v2].maxn2=0, a[v3].maxn3=0;
			if(a[v1].b>a[v1].c){
				a[v1].maxn2=a[v1].b;
			}
			if(a[v1].b<a[v1].c){
				a[v1].maxn3=a[v1].c;
			}
			if(a[v2].a>a[v2].c){
				a[v2].maxn1=a[v2].a;
			}
			if(a[v2].a<a[v2].c){
				a[v2].maxn3=a[v2].c;
			}
			if(a[v3].a>a[v3].b){
				a[v3].maxn1=a[v3].a;
			}
			if(a[v3].a<a[v3].b){
				a[v3].maxn2=a[v3].b;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=a[i].maxn1;
			cnt+=a[i].maxn2;
			cnt+=a[i].maxn3;
		}
		cout<<cnt;
	}
	return 0;
}
