#include<bits/stdc++.h>
using namespace std;
int n,t,a1,a2,a3,a4,sum;
struct node{
	int x,y,z,c,m;
}a[100010];
bool cmp(node e,node f){
	return e.c<f.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		sum=a1=a2=a3=a4=0;
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z; 
			int mx=max(a[i].x,max(a[i].y,a[i].z));
			int mi=min(a[i].x,min(a[i].y,a[i].z));
			a[i].c=2*mx-a[i].x-a[i].y-a[i].z+mi;
			if(mx==a[i].x){
				a[i].m=1;a1++;
			}else if(mx==a[i].y){
				a[i].m=2;a2++;
			}else {
				a[i].m=3;a3++; 
			}       
			sum+=mx;                            
		}
		if(a1<=n/2 && a2<=n/2 && a3<=n/2){
			cout<<sum<<"\n";
			continue;
		}
		sort(a+1,a+n+1,cmp);
		if(a1>n/2){
			for (int i=1;i<=n;i++){
				if(a[i].m==1){
					a1--;
					sum-=a[i].c;
				}
				if(a1<=n/2)break;
			}
		}
		else if(a2>n/2){
			for (int i=1;i<=n;i++){
				if(a[i].m==2){
					a2--;
					sum-=a[i].c;
				}
				if(a2<=n/2)break;
			}
		}	
		else {
			for (int i=1;i<=n;i++){
				if(a[i].m==3){
					a3--;
					sum-=a[i].c;
				}
				if(a3<=n/2)break;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}

 