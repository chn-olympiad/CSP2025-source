#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int T,n,a[100010][5],cnt[5],c[100010];
struct node{
	int v,pos;
}b[5];
struct jjjj{
	int p,v;
	operator <(const jjjj &x)
	const{
		return v<x.v;
	}
};
bool cmp(node x,node y){
	return x.v<y.v;
}
int e(int x){
	for(int i=1;i<=3;i++){
		b[i].pos=b[i].v=0;
	}
	for(int i=1;i<=3;i++){
		b[i].v=a[x][i];
		b[i].pos=i;
	}
	sort(b+1,b+4,cmp);
	return b[2].pos;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		priority_queue<jjjj> q;
		bool flag=0;
		int sum=0;
		for(int i=1;i<=3;i++){
			cnt[i]=0;
		}
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
		}
		for(int i=1;i<=n;i++){
			int mx=max(a[i][1],max(a[i][2],a[i][3]));
			for(int j=1;j<=3;j++){
				if(a[i][j]==mx){
					if(cnt[j]<n/2){
						cnt[j]++;
						c[i]=j;
						sum+=a[i][j];
					}
					else{
						if(!flag){
							for(int k=1;k<i;k++){
								if(c[k]==j){
									q.push({k,a[k][e(k)]-max(a[k][1],max(a[k][2],a[k][3]))});
								}
							}
							flag=1;
						}
						if(q.empty()){
							cnt[e(i)]++;
							c[i]=e(i);
							sum+=a[i][e(i)];
						}
						else if(q.top().v+a[i][j]<=0){
							cnt[e(i)]++;
							c[i]=e(i);
							sum+=a[i][e(i)];
						}
						else{
							int kk=q.top().p,kv=q.top().v;
							q.pop();
							cnt[e(kk)]++;
							c[kk]=e(kk);
							c[i]=j;
							sum+=kv+a[i][j];
							q.push({i,a[i][e(i)]-mx});
						}
					}
					break;
				}
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}
