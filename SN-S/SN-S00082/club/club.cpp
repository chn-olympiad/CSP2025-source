#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
int t;
struct kx{
	int id;
	int st,nd,rd;
}a[100010];
struct kx1{
	int id;
	int type;
	int s;
}lar[300030];
int cmp(kx1 x,kx1 y){
	return x.s>y.s;
}
int fid[100010];
int main(){
	freopen("clud.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0;
		int n;
		cin>>n;
		int det=0;
		for(int i=1;i<=n;i++){
			a[i].id=i;
			cin>>a[i].st>>a[i].nd>>a[i].rd;
			det++;
			lar[det].id=a[i].id;
			lar[det].type=1;
			lar[det].s=a[i].st;
			det++;
			lar[det].id=a[i].id;
			lar[det].type=2;
			lar[det].s=a[i].nd;
			det++;
			lar[det].id=a[i].id;
			lar[det].type=3;
			lar[det].s=a[i].rd;
		}
		sort(lar+1,lar+1+det,cmp);
		int ccst=0,ccnd=0,ccrd=0;
		for(int i=1;i<=det;i++){
			if(fid[lar[i].id]==0){
				fid[lar[i].id]=1;
				if(lar[i].type==1&&ccst<n/2){
					ans+=lar[i].s;
					ccst++;
				}
				if(lar[i].type==2&&ccnd<n/2){
					ans+=lar[i].s;
					ccnd++;
				}
				if(lar[i].type==3&&ccrd<n/2){
					ans+=lar[i].s;
					ccrd++;
				}
			}
			else continue;
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++)a[i].st=0,a[i].nd=0,a[i].rd=0,a[i].id=0;
		for(int i=1;i<=det;i++)lar[det].id=0,lar[det].type=0,lar[det].s=0;
		for(int i=1;i<=n;i++)fid[i]=0;
	}
	return 0;
}

