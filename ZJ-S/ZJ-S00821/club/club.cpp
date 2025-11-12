#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
struct T{
	int i;
	int j;
	int k;
	int s;
}num[N];
int nu1[N];
int nm1=0;
int nu2[N];
int nm2=0;
int nu3[N];
int nm3=0;
int ans;
bool cmp(int a,int b){
	return num[a].s>num[b].s;
}
void f1(int a1,int n){
	sort(nu1+1,nu1+a1+1,cmp);
	for(;a1>n/2;a1--){
		ans-=num[nu1[a1]].s;
	}
}
void f2(int a2,int n){
	sort(nu2+1,nu2+a2+1,cmp);
	for(;a2>n/2;a2--){
		ans-=num[nu2[a2]].s;
	}
}void f3(int a3,int n){
	sort(nu3+1,nu3+a3+1,cmp);
	for(;a3>n/2;a3--){
		ans-=num[nu3[a3]].s;
	}
}
int main(){
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		ans=0;
		nm1=0;
		nm2=0;
		nm3=0;
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&num[i].i,&num[i].j,&num[i].k);
			if(max(max(num[i].i,num[i].j),num[i].k)==num[i].i){
				nu1[++nm1]=i;
				num[i].s=num[i].i-max(num[i].j,num[i].k);
				ans+=num[i].i;
			}else if(max(num[i].j,num[i].k)==num[i].j){
				nu2[++nm2]=i;
				ans+=num[i].j;
				num[i].s=num[i].j-max(num[i].i,num[i].k);
			}else{
				nu3[++nm3]=i;
				ans+=num[i].k;
				num[i].s=num[i].k-max(num[i].i,num[i].j);
			}
		}if(nm1>n/2){
			f1(nm1,n);
		}else if(nm2>n/2){
			f2(nm2,n);
		}else if(nm3>n/2){
			f3(nm3,n);
		}printf("%d\n",ans);
	}
	return 0;
}

