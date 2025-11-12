#include<bits/stdc++.h>
using namespace std;
int t,n,ans,ans1,ans2,ans3,cnt1,cnt2,cnt3,cmx;
struct node{
	int a,id;
};
struct noode{
	node b[4];
}a[100005];
bool cmp(node a,node b){
	return a.a>b.a; 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0,cnt1=0,cnt2=0,cnt3=0;
		cin>>n;
		cmx=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].b[1].a>>a[i].b[2].a>>a[i].b[3].a;
			a[i].b[1].id=1,a[i].b[2].id=2,a[i].b[3].id=3;
			sort(a[i].b+1,a[i].b+n+1,cmp);
		}
		for(int i=1;i<=n;i++){
			if(a[i].b[1].id==1){
				if(cnt1>=cmx){
					if(a[i].b[2].id==2){
						if(cnt2>=cmx){
							cnt3++;
							ans+=a[i].b[3].a;
						}else{
							cnt2++;
							ans+=a[i].b[2].a;
						}
					}if(a[i].b[2].id==3){
						if(cnt3>=cmx){
							cnt2++;
							ans+=a[i].b[3].a;
						}else{
							cnt3++;
							ans+=a[i].b[2].a;
						}
					}
				}else{
					cnt1++;
					ans+=a[i].b[1].a;
				}
			}else if(a[i].b[1].id==2){
				if(cnt2>=cmx){
					if(a[i].b[2].id==1){
						if(cnt1>=cmx){
							cnt3++;
							ans+=a[i].b[3].a;
						}else{
							cnt1++;
							ans+=a[i].b[2].a;
						}
					}if(a[i].b[2].id==3){
						if(cnt3>=cmx){
							cnt1++;
							ans+=a[i].b[3].a;
						}else{
							cnt3++;
							ans+=a[i].b[2].a;
						}
					}
				}else{
					cnt2++;
					ans+=a[i].b[1].a;
				}
			}else if(a[i].b[1].id==3){
				if(cnt3>=cmx){
					if(a[i].b[2].id==1){
						if(cnt1>=cmx){
							cnt2++;
							ans+=a[i].b[3].a;
						}else{
							cnt1++;
							ans+=a[i].b[2].a;
						}
					}if(a[i].b[2].id==2){
						if(cnt2>=cmx){
							cnt1++;
							ans+=a[i].b[3].a;
						}else{
							cnt2++;
							ans+=a[i].b[2].a;
						}
					}
				}else{
					cnt3++;
					ans+=a[i].b[1].a;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

