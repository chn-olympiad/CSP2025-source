#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,b[N],siz[5];
struct node{
	int a,b,c;
}a[N];
int middle(int x,int y,int z){
	if(x>=y&&x>=z){
		if(y>z) return x-y;
		else return x-z;
	}else if(y>=x&&y>=z){
		if(x>z) return y-x;
		else return y-z;
	}else{
		if(x>y) return z-x;
		else return z-y;
	}
}
priority_queue<int,vector<int>,greater<int> >Q1,Q2,Q3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int m=n/2,ans=0;
		while(!Q1.empty()) Q1.pop();
		while(!Q2.empty()) Q2.pop();
		while(!Q3.empty()) Q3.pop();
		siz[1]=siz[2]=siz[3]=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			b[i]=middle(a[i].a,a[i].b,a[i].c);
		}
		for(int i=1;i<=n;i++){
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
				if(siz[1]<m){
					ans+=a[i].a;
					Q1.push(b[i]);
					siz[1]++;
				}else{
					if(b[i]>Q1.top()){
						ans+=a[i].a-Q1.top();
						Q1.pop();
						Q1.push(b[i]);
					}else{
						if(a[i].b>a[i].c){
							ans+=a[i].b;
						}else{
							ans+=a[i].c;
						}
					}
				}
			}else if(a[i].b>=a[i].a&&a[i].b>=a[i].c){
				if(siz[2]<m){
					ans+=a[i].b;
					Q2.push(b[i]);
					siz[2]++;
				}else{
					if(b[i]>Q2.top()){
						ans+=a[i].b-Q2.top();
						Q2.pop();
						Q2.push(b[i]);
					}else{
						if(a[i].a>a[i].c){
							ans+=a[i].a;
						}else{
							ans+=a[i].c;
						}
					}
				}
			}else{
				if(siz[3]<m){
					ans+=a[i].c;
					Q3.push(b[i]);
					siz[3]++;
				}else{
					if(b[i]>Q3.top()){
						ans+=a[i].c-Q3.top();
						Q3.pop();
						Q3.push(b[i]);
					}else{
						if(a[i].a>a[i].b){
							ans+=a[i].a;
						}else{
							ans+=a[i].b;
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

