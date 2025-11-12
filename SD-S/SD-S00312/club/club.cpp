#include<bits/stdc++.h>
using namespace std;
long long sbsb=-1,sb[1010][1010];
const int N=1e5+10000;
int T,n,sum,maxn1=INT_MIN,maxn2=INT_MIN,maxn3=INT_MIN;
struct node{
	int a1;
	int a2;
	int a3;
}a[N];
priority_queue<int,vector<int>,greater<int> >q1;
priority_queue<int,vector<int>,greater<int> >q2;
priority_queue<int,vector<int>,greater<int> >q3;
bool cmp(node q,node p){
	if(q.a1!=p.a1){
		return q.a1<=p.a1;
	}
	else if(q.a2!=p.a2){
			return q.a2<=p.a2;
		}
	else{
		if(q.a3!=p.a3){
			return q.a3<=p.a3;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		sum=0;
		while(!q1.empty()){
			q1.pop();
		}
		while(!q2.empty()){
			q2.pop();
		}
		while(!q3.empty()){
			q3.pop();
		}
		scanf("%d",&n);	
		if(n==2){
			for(int i=1;i<=2;i++){
				for(int j=1;j<=3;j++){
					cin>>sb[i][j];
				}
			}
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i!=j){
						sbsb=max(sbsb,sb[1][i]+sb[2][j]);
					}
				}
			}
			cout<<sbsb<<endl;
			return 0;
		}else if(n==4){
			for(int i=1;i<=4;i++){
				for(int j=1;j<=3;j++){
					cin>>sb[i][j];
				}
			}
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					for(int ii=1;ii<=3;ii++){
						for(int jj=1;jj<=3;jj++){
							if(!((i==j&&j==ii)||(i==j&&j==jj)||(i==ii&&ii==jj)||(j==jj&&jj==ii))){
								sbsb=max(sbsb,sb[1][i]+sb[2][j]+sb[3][ii]+sb[4][jj]);
							}
						}
					}
					
				}
			}
			cout<<sbsb<<endl;
			return 0;
		}
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a1,&a[i].a2,&a[i].a3);
		}
	
		sort(a+1,a+n+1,cmp);
//		q1.push(0);
//		q2.push(0);
//		q3.push(0);
//		for(int i=1;i<=n;i++){
//			printf("%d %d %d \n",a[i].a1,a[i].a2,a[i].a3);
//		}
		for(int i=1;i<=n;i++){
			maxn1=maxn2=maxn3=sum;
			maxn1+=a[i].a1;
			if(q1.size()>=n/2)
			maxn1-=q1.top();
			
			maxn2+=a[i].a2;                                                                                            
			if(q2.size()>=n/2)
			maxn2-=q2.top();
			
			maxn3+=a[i].a3;
			if(q3.size()>=n/2)
			maxn3-=q3.top();
//			cout<<endl<<maxn1<<" "<<maxn2<<" "<<maxn3<<" "<<sum<<endl;
			if(maxn1>sum||maxn2>sum||maxn3>sum){
				if(max(maxn1,max(maxn2,maxn3))==maxn1){
					if(q1.size()>=n/2)
					q1.pop();
					q1.push(a[i].a1);
					sum=maxn1;
				}else if(max(maxn1,max(maxn2,maxn3))==maxn2){
					if(q2.size()>=n/2)
					q2.pop();
					q2.push(a[i].a2);
					sum=maxn2;
				}else if(max(maxn1,max(maxn2,maxn3))==maxn3){
					if(q3.size()>=n/2)
					q3.pop();
					q3.push(a[i].a3);
					sum=maxn3;
				}
			}
			
		}
		cout<<sum<<endl;
	}
	return 0;
} 
