#include<bits/stdc++.h>
using namespace std;
struct aaa{
	int a,b,c,m;
};
int cmp(aaa x,aaa y){
	return abs(x.m)>abs(y.m);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,oo=0;
		aaa a[100005];
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].m=a[i].a-a[i].b;
		}
		sort(a+1,a+n+1,cmp);
		int l[4]={0,n/2,n/2,n/2};
		if(n<=30){
			int f[35][35][35]={};
			for(int i=1;i<=n;i++){
				a[i].m=max(a[i].a,max(a[i].b,a[i].c))-min(a[i].a,max(a[i].b,a[i].c));
			}
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n;i++){
				if(l[1]==0){
					if(max(a[i].b,a[i].c)==a[i].b){
						oo+=a[i].b;
						l[2]--;
					}else{
						oo+=a[i].c;
						l[3]--;
					}
				}else if(l[2]==0){
					if(max(a[i].a,a[i].c)==a[i].a){
						oo+=a[i].a;
						l[1]--;
					}else{
						oo+=a[i].c;
						l[3]--;
					}
				}else if(l[3]==0){
					if(max(a[i].b,a[i].a)==a[i].b){
						oo+=a[i].b;
						l[2]--;
					}else{
						oo+=a[i].a;
						l[1]--;
					}
				}else{
					if(max(a[i].a,max(a[i].b,a[i].c))==a[i].a){
						oo+=a[i].a;
						l[1]--;
					}else if(max(a[i].a,max(a[i].b,a[i].c))==a[i].b){
						oo+=a[i].b;
						l[2]--;
					}else{
						oo+=a[i].c;
						l[3]--;
					}
				}
			}
		}else{
			for(int i=1;i<=n;i++){
				if(a[i].m<0&&l[2]!=0||l[1]==0){
					oo+=a[i].b;
					l[2]--;
				}else{
					oo+=a[i].a;
					l[1]--;
				}
			}
		}
		cout<<oo<<endl;
	}
	return 0;
} 

