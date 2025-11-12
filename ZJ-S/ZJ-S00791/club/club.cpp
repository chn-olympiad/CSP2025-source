#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005],b[100005],c[100005],ca,cb,cc,ans;
struct node{
	int id,num;
	friend bool operator<(node x,node y){
		return x.num>y.num;
	}
};
priority_queue<node>qa;
priority_queue<node>qb;
priority_queue<node>qc;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ca=cb=cc=ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i],&b[i],&c[i]);
			
			if(c[i]>a[i]&&c[i]>b[i]){
				if(cc==n/2){
					node awa=qc.top();
					int tt;
					if(a[i]>b[i]) tt=a[i];
					else tt=b[i];
					if(c[i]-tt<awa.num){
						if(b[i]>a[i]) qb.push({i,b[i]-a[i]});
						else qa.push({i,a[i]-b[i]});
					}
					else{
						qc.pop();
						qc.push({i,c[i]-tt});
						if(a[awa.id]>b[awa.id]) qa.push({awa.id,a[awa.id]-b[awa.id]});
						else qb.push({awa.id,b[awa.id]-a[awa.id]});
					}
				}
				else{
					cc++;
					if(b[i]>a[i]) qc.push({i,c[i]-b[i]});
					else qc.push({i,c[i]-a[i]});
				}
			}
			
			else if(b[i]>a[i]&&b[i]>c[i]){
				if(cb==n/2){
					node awa=qb.top();
					int tt;
					if(c[i]>a[i]) tt=c[i];
					else tt=a[i];
					if(b[i]-tt<awa.num){
						if(c[i]>a[i]) qc.push({i,c[i]-a[i]});
						else qa.push({i,a[i]-c[i]});
					}
					else{
						qb.pop();
						qb.push({i,b[i]-tt});
						if(c[awa.id]>a[awa.id]) qc.push({awa.id,c[awa.id]-a[awa.id]});
						else qa.push({awa.id,a[awa.id]-c[awa.id]});
					}
				}
				else{
					cb++;
					if(a[i]>c[i]) qb.push({i,b[i]-a[i]});
					else qb.push({i,b[i]-c[i]});
				}
			}
			
			else{
				if(ca==n/2){
					node awa=qa.top();
					int tt;
					if(c[i]>b[i]) tt=c[i];
					else tt=b[i];
					if(a[i]-tt<awa.num){
						if(c[i]>b[i]) qc.push({i,c[i]-b[i]});
						else qb.push({i,b[i]-c[i]});
					}
					else{
						qa.pop();
						qa.push({i,a[i]-tt});
						if(c[awa.id]>b[awa.id]) qc.push({awa.id,c[awa.id]-b[awa.id]});
						else qb.push({awa.id,b[awa.id]-c[awa.id]});
					}
				}
				else{
					ca++;
					if(b[i]>c[i]) qa.push({i,a[i]-b[i]});
					else qa.push({i,a[i]-c[i]});
				}
			}
		}
		while(!qa.empty()){
			node awa=qa.top();
			//cout<<"A"<<awa.id<<endl;
			qa.pop();
			ans+=a[awa.id];
		}
		while(!qb.empty()){
			node awa=qb.top();
			//cout<<"B"<<awa.id<<endl;
			qb.pop();
			ans+=b[awa.id];
		}
		while(!qc.empty()){
			node awa=qc.top();
			//cout<<"C"<<awa.id<<endl;
			qc.pop();
			ans+=c[awa.id];
		}
		printf("%d\n",ans);
	}
	return 0;
}
