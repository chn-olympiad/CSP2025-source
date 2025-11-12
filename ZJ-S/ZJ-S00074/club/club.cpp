#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
priority_queue<PII,vector<PII>,greater<PII> > q1;
int d[5];
struct f{
	int ma,mid,x1,x2;
}q[100010];
bool cmp(f x,f y){
	if(x.ma==y.ma){
		return x.mid>y.mid;
	}
	return x.ma>y.ma;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			q[i].ma=max(max(a,b),c);
			if(q[i].ma==a){
				q[i].x1=1;
				if(b>c){
					q[i].mid=b;
					q[i].x2=2;
				}else{
					q[i].mid=c;
					q[i].x2=3;
				}
			}else if(q[i].ma==b){
				q[i].x1=2;
				if(a>c){
					q[i].mid=a;
					q[i].x2=1;
				}else{
					q[i].mid=c;
					q[i].x2=3;
				}
			}else if(q[i].ma==c){
				q[i].x1=3;
				if(b>a){
					q[i].mid=b;
					q[i].x2=2;
				}else{
					q[i].mid=a;
					q[i].x2=1;
				}
			}
		}
		sort(q+1,q+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(d[q[i].x1]+1<=n/2){
				sum+=q[i].ma;
				d[q[i].x1]++;
				q1.push({q[i].ma-q[i].mid,i});
			}else{
				int u=q1.top().second;
				q1.pop();
				if(q[u].mid+q[i].ma>q[u].ma+q[i].mid){
					sum=sum-q[u].ma+q[u].mid+q[i].ma;
					d[q[u].x1]--;
					d[q[u].x2]++;
					d[q[i].x1]++;
					q1.push({q[i].ma-q[i].mid,i});
				}else{
					sum+=q[i].mid;
					d[q[i].x2]++;
					q1.push({q[u].ma-q[u].mid,u});
				}
			}
		}
		cout<<sum<<"\n";
		d[1]=d[2]=d[3]=0;
		while(!q1.empty()){
			q1.pop();
		}
	}
}

