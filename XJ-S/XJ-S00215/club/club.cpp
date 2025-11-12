#include<bits/stdc++.h>
using namespace std;
struct bm{
	int a1,a2,a3;
};
bool cmp(bm x,bm y){
	if(x.a1!=y.a1) return x.a1>y.a1;
	else if(x.a2!=y.a2) return x.a2>y.a2;
	else return x.a3>y.a3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int n2=n/2;
		bm a[n+10];
		for(int i=1;i<=n;i++) cin>>a[i].a1>>a[i].a2>>a[i].a3;
		sort(a+1,a+1+n,cmp);
		int b1=0,b2=0,b3=0,s=0;
		for(int i=1;i<=n;i++)
			if(max(a[i].a1,max(a[i].a2,a[i].a3))==a[i].a1){
				if(b1<=n2){
					b1++;
					s+=a[i].a1;
					continue;
				}
			}
			else if(max(a[i].a1,max(a[i].a2,a[i].a3))==a[i].a2){
				if(b2<=n2){
					b2++;
					s+=a[i].a2;
					continue;
				}
			}
			else{
				if(b3<=n2){
					b3++;
					s+=a[i].a3;
					continue;
				}
			}
		cout<<s<<"\n";
	}
	return 0;
}
