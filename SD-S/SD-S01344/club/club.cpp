#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N=1e5+50;

int T;
int n;
int a[N][5];
long long ans,sum;
int maxx;

struct men{
	int id,k;
}mi[N],mj[N],mk[N],ci[N],cj[N],ck[N];

bool cmp(men a,men b){
	return a.k>b.k;
}

int it,jt,kt;

void dfs(int x){
	if(x==n+1){
		sum=max(ans,sum);
		return ;
	}
	if(it<maxx){
		ans+=a[x][1];
		it++;
		dfs(x+1);
		it--;
		ans-=a[x][1];
	}
	if(jt<maxx){
		ans+=a[x][2];
		jt++;
		dfs(x+1);
		jt--;
		ans-=a[x][2];
	}
	if(kt<maxx){
		ans+=a[x][3];
		kt++;
		dfs(x+1);
		kt--;
		ans-=a[x][3];
	}
	return ;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		maxx=n/2;
		//cout<<"maxx="<<maxx<<endl;
		ans=it=jt=kt=sum=0;
		int flag1=1,flag2=1;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2]!=0||a[i][3]!=0) flag1=0;
			if(a[i][3]!=0) flag2=0;
			mi[i]={i,a[i][1]},mj[i]={i,a[i][2]},mk[i]={i,a[i][3]};
			a[i][0]=0;
		}
		if(n<30){
			dfs(1);
			cout<<sum<<endl;
			continue;
		}
		sort(mi+1,mi+1+n,cmp);
		sort(mj+1,mj+1+n,cmp);
		sort(mk+1,mk+1+n,cmp);
		for(int i=1;i<=n;i++){
			int id=mi[i].id;
			if(it==maxx) break;
			if(a[id][1]>a[id][2]&&a[id][1]>a[id][3]){
				a[id][0]=1;
				ans+=a[id][1];
				it++;
				int mid=max(a[id][2],a[id][3]);
				ci[it]={id,a[id][1]-mid};
			}
		}
		for(int i=1;i<=n;i++){
			int id=mj[i].id;
			if(jt==maxx) break;
			if(a[id][0]!=0) continue;
			if(a[id][2]>a[id][1]&&a[id][2]>a[id][3]){
				a[id][0]=2;
				ans+=a[id][2];
				jt++;
				int mid=max(a[id][1],a[id][3]);
				cj[jt]={id,a[id][2]-mid};
			}
		}
		for(int i=1;i<=n;i++){
			int id=mk[i].id;
			if(kt==maxx) break;
			if(a[id][0]!=0) continue;
			if(a[id][3]>a[id][1]&&a[id][3]>a[id][2]){
				a[id][0]=3;
				ans+=a[id][3];
				kt++;
				int mid=max(a[id][2],a[id][1]);
				ck[kt]={id,a[id][3]-mid};
			}
		}
		sort(ci+1,ci+1+it,cmp);
		sort(cj+1,cj+1+jt,cmp);
		sort(ck+1,ck+1+kt,cmp);
		/*if(flag2==1){
			for(int i=1;i<=n;i++){
				if(a[i][0]!=0) continue;
				if(a[i][1]>=a[i][2]){
					if((a[i][1]-a[i][2])>=ci[1].k){
					int b=0;
					for(int j=1;j<=it;j++){
						if(ci[j].k<=(a[i][1]-mid)&&ci[j+1].k>=(a[i][1]-mid)){
							b=j;
							break;
						}
					}
					int id=ci[b].id;
					a[id][0]=0;
					a[i][0]=1;
					ans-=a[id][1];
					ans+=a[i][1];
					continue;
					}
				}
			}
		}*/
		for(int i=1;i<=n;i++){
			if(a[i][0]!=0) continue;
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]&&it==maxx){
				int mid=max(a[i][2],a[i][3]);
				if((a[i][1]-mid)>=ci[1].k){
					int b=0;
					for(int j=1;j<=it;j++){
						if(ci[j].k<=(a[i][1]-mid)&&ci[j+1].k>=(a[i][1]-mid)){
							b=j;
							break;
						}
					}
					int id=ci[b].id;
					a[id][0]=0;
					a[i][0]=1;
					ans-=a[id][1];
					ans+=a[i][1];
					continue;
				}
			}
			if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]&&jt==maxx){
				int mid=max(a[i][1],a[i][3]);
				if((a[i][2]-mid)>=cj[1].k){
					int b=0;
					for(int j=1;j<=jt;j++){
						if(cj[j].k<=(a[i][2]-mid)&&cj[j+1].k>=(a[i][2]-mid)){
							b=j;
							break;
						}
					}
					int id=cj[b].id;
					a[id][0]=0;
					a[i][0]=2;
					ans-=a[id][2];
					ans+=a[i][2];
					continue;
				}
			}
			if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]&&kt==maxx){
				int mid=max(a[i][2],a[i][1]);
				if((a[i][3]-mid)>=ck[1].k){
					int b=0;
					for(int j=1;j<=kt;j++){
						if(ck[j].k<=(a[i][3]-mid)&&ck[j+1].k>=(a[i][3]-mid)){
							b=j;
							break;
						}
					}
					int id=ck[b].id;
					a[id][0]=0;
					a[i][0]=3;
					ans-=a[id][3];
					ans+=a[i][3];
					continue;
				}
			}
			if(a[i][1]<=a[i][2]&&a[i][1]>=a[i][3]&&it!=maxx){
				a[i][0]=1;
				it++;
				ans+=a[i][1];
				continue;
			}
			if(a[i][2]<=a[i][1]&&a[i][2]>=a[i][3]&&jt!=maxx){
				a[i][0]=2;
				ans+=a[i][2];
				jt++;
				continue;
			}
			if(a[i][3]<=a[i][1]&&a[i][3]>=a[i][2]&&kt!=maxx){
				a[i][0]=3;
				ans+=a[i][3];
				kt++;
				continue;
			}
			if(a[i][1]>=a[i][2]&&a[i][1]<=a[i][3]&&it!=maxx){
				a[i][0]=1;
				it++;
				ans+=a[i][1];
				continue;
			}
			if(a[i][2]>=a[i][1]&&a[i][2]<=a[i][3]&&jt!=maxx){
				a[i][0]=2;
				ans+=a[i][2];
				jt++;
				continue;
			}
			if(a[i][3]>=a[i][1]&&a[i][3]<=a[i][2]&&kt!=maxx){
				a[i][0]=3;
				ans+=a[i][3];
				kt++;
				continue;
			}
			if(it!=maxx){
				a[i][0]=1;
				it++;
				ans+=a[i][1];
				continue;
			}
			if(jt!=maxx){
				a[i][0]=2;
				ans+=a[i][2];
				jt++;
				continue;
			}
			a[i][0]=3;
			ans+=a[i][3];
			kt++;
			continue;
		} 
		cout<<ans<<endl;
	}
	return 0;
}
