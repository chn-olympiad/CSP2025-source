#include<bits/stdc++.h>
using namespace std;
int t,n;
long ans;
struct st{
	int q,w,e,r;
};
bool cmp(st a,st b){
	if(a.q>b.q) return 1;
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		int a0,a1,a2,a3;
		st a[100020]={};
		for(int i = 0;i<n;i++){
			cin>>a1>>a2>>a3;
			a0=min(max(a1,a2),min(max(a1,a3),max(a2,a3)));
			ans+=a0;
			a1=max(0,a1-a0),a2=max(0,a2-a0),a3=max(0,a3-a0);
			a[i].w=a1,a[i].e=a2,a[i].r=a3,a[i].q=max(a1,max(a2,a3));
		}
		sort(a,a+n+1,cmp);
		a0=0,a1=0,a2=0,a3=0;
		for(int i =0 ;i<n;i++){
			if(a[i].q==0) break;
			if(a[i].q==a[i].w){
				if(a1<n/2){
					a1++;
					ans+=a[i].q;
				}
			}
			else if(a[i].q==a[i].e){
				if(a2<n/2){
					a2++;
					ans+=a[i].q;
				}
			}
			else if(a[i].q==a[i].r){
				if(a3<n/2){
					a3++;
					ans+=a[i].q;
				}
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 