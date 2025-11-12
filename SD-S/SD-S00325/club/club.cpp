#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t[5];

struct Note{
	int a1,a2,a3,max1,maxi;
}a[N];

bool cmp(Note a1,Note b1){
	return a1.max1>=b1.max1;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	while(T--){
		long long sum=0;
		t[1]=0;
		t[2]=0;
		t[3]=0;
		int n;
		scanf("%d",&n);
		int m=n/2;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i].a1);
			int maxxx=a[i].a1;
			scanf("%d",&a[i].a2);
			maxxx=max(maxxx,a[i].a2);		
			scanf("%d",&a[i].a3);
			a[i].max1=max(maxxx,a[i].a3);
		}
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++){
			if(a[i].a1==a[i].max1){
				a[i].maxi=1;
				if(t[1]<m){
					sum=sum+a[i].a1;
					t[1]++;
				}else{
					bool chazhao=0;
					int mmmin=1e7,mj,cha,mmaxi,mmj;
					for(int j=i-1;j>=0;j--){
						if(a[j].maxi==1){
							int mmaxx;
							if(a[j].a2>=a[j].a3){
								mmaxx=a[j].a2;
								mmaxi=2;
								cha=a[j].a1-a[j].a2;
							}else{
								mmaxx=a[j].a3;
								mmaxi=3;
								cha=a[j].a1-a[j].a3;
							}
							if(cha<a[i].a1&&cha<mmmin){
								chazhao=1;
								mmmin=cha;
								mj=j;
								mmj=mmaxi;
							}
						}
					}
					if(chazhao==0){
						if(a[i].a2>=a[i].a3){
							sum=sum+a[i].a2;
							a[i].maxi=2;
						}else{
							sum=sum+a[i].a3;
							a[i].maxi=3;
						}
					}else{
						sum=sum+a[i].a1-mmmin;
						a[i].maxi=1;
						a[mj].maxi=mmj;
					}
				}
			}else if(a[i].a2==a[i].max1){
				a[i].maxi=2;
				if(t[2]<m){
					sum=sum+a[i].a2;
					t[2]++;
				}else{
					bool chazhao=0;
					int mmmin=1e6,mj,cha,mmaxi,mmj;
					for(int j=i-1;j>=0;j--){
						if(a[j].maxi==2){
							int mmaxx;
							if(a[j].a1>=a[j].a3){
								mmaxx=a[j].a1;
								mmaxi=1;
								cha=a[j].a2-a[j].a1;
							}else{
								mmaxx=a[j].a3;
								mmaxi=3;
								cha=a[j].a2-a[j].a3;
							}
							if(cha<a[i].a2&&cha<mmmin){
								chazhao=1;
								mmmin=cha;
								mj=j;
								mmj=mmaxi;
							}
						}
					}
					if(chazhao==0){
						if(a[i].a1>=a[i].a3){
							sum=sum+a[i].a1;
							a[i].maxi=1;
						}else{
							sum=sum+a[i].a3;
							a[i].maxi=3;
						}
					}else{
						sum=sum+a[i].a2-mmmin;
						a[i].maxi=2;
						a[mj].maxi=mmj;
					}
				}
			}else{
				a[i].maxi=3;
				if(t[3]<m){
					sum=sum+a[i].a3;
					t[3]++;
				}else{
					bool chazhao=0;
					int mmmin=1e6,mj,cha,mmaxi,mmj;
					for(int j=i-1;j>=0;j--){
						if(a[j].maxi==3){
							int mmaxx;
							if(a[j].a2>=a[j].a1){
								mmaxx=a[j].a2;
								mmaxi=2;
								cha=a[j].a3-a[j].a2;
							}else{
								mmaxx=a[j].a1;
								mmaxi=1;
								cha=a[j].a3-a[j].a1;
							}
							if(cha<a[i].a3&&cha<mmmin){
								chazhao=1;
								mmmin=cha;
								mj=j;
								mmj=mmaxi;
							}
						}
					}
					if(chazhao==0){
						if(a[i].a2>=a[i].a1){
							sum=sum+a[i].a2;
							a[i].maxi=2;
						}else{
							sum=sum+a[i].a1;
							a[i].maxi=1;
						}
					}else{
						sum=sum+a[i].a3-mmmin;
						a[i].maxi=3;
						a[mj].maxi=mmj;
					}
				}
			}
		}
		printf("%lld\n",sum);
	}
	
	return 0;
}
