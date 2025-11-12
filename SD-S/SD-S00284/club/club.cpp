#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<utility>
#include<vector>
using namespace std;
struct bumen{
	int s[3];
}bm[114514];
struct D{
	int id;
	int v;
	int bmid;
}diff[114514*2];

pair<int,int> max_[114514];
//pair<int,pair<pair<int,int>,pair<int,int> > > diff[114514];
int crt[3];

int maxn;
int n;

bool cmp(D a,D b){
	return a.v<b.v;
}

bool vis[114514*2];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		int ans=0;
		cin>>n;
		memset(max_,-1,sizeof(max_));
		maxn=n/2;
		crt[0]=0;crt[1]=0;crt[2]=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>bm[i].s[j];
				if(max_[i].first<bm[i].s[j]){
					max_[i].first=bm[i].s[j];
					max_[i].second=j;
				}				
			}
			crt[max_[i].second]++;
			ans+=max_[i].first;
			diff[i].id=i;
			for(int j=0;j<=1;j++){
				int temp=j+1;
				if(max_[i].second==1 && temp==2) diff[i*2+j].bmid=2;
				else diff[i*2+j].bmid=abs(max_[i].second-temp);
				diff[i*2+j].v=abs(max_[i].first-bm[i].s[diff[i*2+j].bmid]);
			}
		}
		stable_sort(diff,diff+n*2,cmp);
		while(crt[0]>maxn || crt[1]>maxn || crt[2]>maxn){
			for(int i=0;i<3;i++){
				if(crt[i]>maxn){
					for(int j=0;j<crt[i]-maxn;j++){
						for(int x=0;1;x++){
							if(diff[x].bmid!=i){
								ans-=diff[x].v;
								crt[diff[x].bmid]++;
								diff[x].v=abs(bm[diff[x].id].s[i]-bm[diff[x].id].s[diff[x].bmid]);
								diff[x].bmid=i;
								break;
							}
						}
						stable_sort(diff,diff+n*2,cmp);	
					}
					crt[i]=maxn;
				}
			}
		}

		cout<<ans<<endl;
	}
	return 0;
}
/*#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
//fuck your poopoo, i like dicks
//ccf dont ban me pls i sorry
//play with my balls
using namespace std;
const int maxx=114514;
struct bumen{
	int gg[3];
};

int max_=-1;
int n;
int maxn;
int maxed[3];
int temp=0;

/*bool cmp(bumen a,bumen b){
	//return max(a.fst,max(a.scd,a.thd))>max(b.fst,max(b.scd,b.thd));
}*/
/*
bumen bm[maxx];

void srch(int b){
	if(b==n){
		max_=max(temp,max_);
		return;
	}
	for(int i=0;i<3;i++){
		if(maxed[i]==maxn) continue;
		temp+=bm[b].gg[i];
		maxed[i]++;
		srch(b+1);
		maxed[i]--;
		temp-=bm[b].gg[i];
	}
	return;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		max_=-1;
		
		maxed[0]=0;maxed[1]=0;maxed[2]=0;
		cin>>n;
		maxn=n/2;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++) cin>>bm[i].gg[j];
		}
		//stable_sort(bm,bm+n,cmp);
		srch(0);
		cout<<"ans:"<<max_<<endl;
	}	
	return 0;
}*/

/*
3 
4
4 2 1
3 2 4 
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2 
10 9 8
4 0 0
*/
/*
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<utility>
#include<vector>
using namespace std;
struct bumen{
	int s[3];
}bm[114514];
struct D{
	int id;
	int v;
	int bmid;
}diff[114514*2];

pair<int,int> max_[114514];
//pair<int,pair<pair<int,int>,pair<int,int> > > diff[114514];
int crt[3];

int maxn;
int n;

bool cmp(D a,D b){
	return a.v<b.v;
}

bool vis[114514*2];

int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		int ans=0;
		cin>>n;
		memset(max_,-1,sizeof(max_));
		maxn=n/2;
		crt[0]=0;crt[1]=0;crt[2]=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>bm[i].s[j];
				if(max_[i].first<bm[i].s[j]){
					max_[i].first=bm[i].s[j];
					max_[i].second=j;
				}				
			}
			crt[max_[i].second]++;
			ans+=max_[i].first;
			diff[i].id=i;
			for(int j=0;j<=1;j++){
				int temp=j+1;
				if(max_[i].second==1 && temp==2) diff[i*2+j].bmid=2;
				else diff[i*2+j].bmid=abs(max_[i].second-temp);
				diff[i*2+j].v=abs(max_[i].first-bm[i].s[diff[i*2+j].bmid]);
			}
		}
		cout<<ans<<endl;
		stable_sort(diff,diff+n*2,cmp);
		while(crt[0]>maxn || crt[1]>maxn || crt[2]>maxn){
			for(int i=0;i<3;i++){
				if(crt[i]>maxn){
					for(int j=0;j<crt[i]-maxn;j++){
						for(int x=0;1;x++){
							if(diff[x].bmid!=i && vis[diff[x].id]==0){
								cout<<diff[x].v<<endl;
								ans-=diff[x].v;
								crt[diff[x].bmid]++;
								diff[x].v=abs(bm[diff[x].id].s[i]-bm[diff[x].id].s[diff[x].bmid]);
								diff[x].bmid=i;
								vis[diff[x].id]=1;
								break;
							}
						}
						stable_sort(diff,diff+n*2,cmp);	
					}
					crt[i]=maxn;
				}
			}
		}

		cout<<ans<<endl;
	}
	return 0;
}
*/
