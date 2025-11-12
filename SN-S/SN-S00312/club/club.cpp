#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100005][4];
int aa1[100005],aa2[100005],aa3[100005];
int cmp(int x,int y){
	return x>y;
}
struct node{
	int z;//值 
	int p;//position
};
int cmpp(node x,node y){
	return x.z>y.z;
}
bool pd(int aa[]){
	for(int i=1;i<=n;i++){
		if(aa[i]!=0) return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		for(int i=1;i<=100001;i++){
			for(int j=1;j<=4;j++) a[i][j]=0;
		}
		for(int i=1;i<=100001;i++){
			aa1[i]=0;aa2[i]=0;aa3[i]=0;
		}
		cin>>n;
		int n1=n/2;
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			aa1[i]=a[i][1];aa2[i]=a[i][2];aa3[i]=a[i][3];
		}
		if(n==2){
			int ans1=max(a[1][1]+a[2][2],a[1][1]+a[2][3]);
			int ans2=max(a[1][2]+a[2][1],a[1][2]+a[2][3]);
			int ans3=max(a[1][3]+a[2][1],a[1][3]+a[2][2]);
			ans=max(ans1,max(ans2,ans3));
		}else if(pd(aa2)&&pd(aa3)){
			sort(aa1+1,aa1+1+n,cmp);
			for(int i=1;i<=n1;i++) ans+=aa1[i];
		}else if(pd(aa1)&&pd(aa2)){
			sort(aa3+1,aa3+1+n,cmp);
			for(int i=1;i<=n1;i++){
				ans+=aa3[i];
			}
		}else if(pd(aa1)&&pd(aa3)){
			sort(aa2+1,aa2+1+n,cmp);
			for(int i=1;i<=n1;i++) ans+=aa2[i];
		}else if(pd(aa3)){
			node lr[100005];
			for(int i=1;i<=n;i++){
				lr[i].z=aa1[i]-aa2[i];
				lr[i].p=i;
			}
			sort(lr+1,lr+1+n,cmpp);
			for(int i=1;i<=n1;i++){
				ans+=a[lr[i].p][1];
			}
			for(int i=n1+1;i<=n;i++){
				ans+=a[lr[i].p][2];
			}
		}else{
			for(int i=1;i<=n;i++){
				ans+=max(a[i][1],max(a[i][2],a[i][3]));
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
