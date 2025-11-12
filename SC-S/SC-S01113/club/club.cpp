#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int T;
struct node{
	int x[4];
	int ind;
}a[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		int n;
		long long cnt=0;
		cin>>n;
		int l1=0,l2=0,l3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x[1]>>a[i].x[2]>>a[i].x[3];
			int maxn=0;
			for(int j=1;j<=3;j++){
				if(maxn<a[i].x[j]){
					maxn=a[i].x[j];
					a[i].ind=j;
				}	
			}
			if(a[i].ind==1)l1++;
			else if(a[i].ind==2)l2++;
			else l3++;
			cnt+=a[i].x[a[i].ind];
		}
//		cout<<cnt<<endl;
//		cout<<l1<<" "<<l2<<" "<<l3<<endl;
		int k=n/2;
		if(l1>k){
			for(int l=1;l<=l1-k;l++){
				long long maxnnn=0,index=0;
				for(int i=1;i<=n;i++){
					long long cntm=cnt;
					if(a[i].ind==1){
						cntm=cntm-a[i].x[1]+max(a[i].x[2],a[i].x[3]);
						if(maxnnn<cntm){
							maxnnn=cntm;
							index=i;
						}	
					}	
				}
				cnt=cnt-a[index].x[1]+max(a[index].x[2],a[index].x[3]);
				if(a[index].x[2]>=a[index].x[3])a[index].ind=2;
				if(a[index].x[2]<a[index].x[3])a[index].ind=3;
			}
		}else if(l2>k){
			for(int l=1;l<=l2-k;l++){
				long long maxnnn=0,index=0;
				for(int i=1;i<=n;i++){
					long long cntm=cnt;
					if(a[i].ind==2){
						cntm=cntm-a[i].x[2]+max(a[i].x[1],a[i].x[3]);
						if(maxnnn<cntm){
							maxnnn=cntm;
							index=i;
						}	
					}
					
				}			
				cnt=cnt-a[index].x[2]+max(a[index].x[1],a[index].x[3]);
				if(a[index].x[1]>=a[index].x[3])a[index].ind=1;
				if(a[index].x[1]<a[index].x[3])a[index].ind=3;	
			}
		}else if(l3>k){
			for(int l=1;l<=l3-k;l++){
				long long maxnnn=0,index=0;
				for(int i=1;i<=n;i++){
					long long cntm=cnt;
					if(a[i].ind==3){
						cntm=cntm-a[i].x[3]+max(a[i].x[1],a[i].x[2]);
						if(maxnnn<cntm){
							maxnnn=cntm;
							index=i;
						}
					}
				}
				cnt=cnt-a[index].x[3]+max(a[index].x[1],a[index].x[2]);
				if(a[index].x[1]>=a[index].x[2])a[index].ind=1;
				if(a[index].x[1]<a[index].x[2])a[index].ind=2;
			//	cout<<index<<" "<<cnt<<" ";
			}
		}
		cout<<cnt<<endl;
	}	
	return 0;
}