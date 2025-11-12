#include<iostream>
#include<cstdio> 
#include<queue>
#include<cstring>
#define PII pair <int,int>
#define fi first
#define se second
using namespace std;
int now[100010],a[100010][4],n,t,cnt[4],ans,maxn;
bool book[100010];
priority_queue<PII> slove;
PII P(long long a,long long b){
	PII temp;
	temp.fi=a;
	temp.se=b;
	return temp;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(book,0,sizeof(book));
		cnt[1]=cnt[2]=cnt[3]=0;
		ans=0;
		while(!slove.empty()){
			slove.pop();
		}
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=n;i++){
			long long maxn=max(a[i][1],max(a[i][2],a[i][3]));
			if(maxn==a[i][1])
				cnt[1]++,now[i]=1;
			else if(maxn==a[i][2])
				cnt[2]++,now[i]=2;
			else{
				cnt[3]++,now[i]=3;
			}
			ans+=maxn;
		}
		
		int temp=0;
		if(cnt[1]>n/2){
			temp=cnt[1]-n/2;
			for(int i=1;i<=n;i++){
				if(now[i]==1){
					int temp=-a[i][1]+a[i][2];
					slove.push(P(temp,i));
					temp=-a[i][1]+a[i][3];
					slove.push(P(temp,i));  
				}
			}
		}
		if(cnt[2]>n/2){
			temp=cnt[2]-n/2;
			for(int i=1;i<=n;i++){
				if(now[i]==2){
					int temp=-a[i][2]+a[i][3];
					slove.push(P(temp,i));
					temp=-a[i][2]+a[i][1];
					slove.push(P(temp,i));  
				}
			}
		}
		if(cnt[3]>n/2){
				temp=cnt[3]-n/2;
				for(int i=1;i<=n;i++){
				if(now[i]==3){
					int temp=-a[i][3]+a[i][1];
					slove.push(P(temp,i));
					temp=-a[i][3]+a[i][2];
					slove.push(P(temp,i));  
				}
			}
		}
		while(1){
			if(temp==0) break;
			PII tp=slove.top();
			if(slove.empty()) break;
			slove.pop();
			if(book[tp.se]) continue;
			ans+=tp.fi;
			book[tp.se]=1;
			temp--;
		}
		cout<<ans<<"\n";
	}
	return 0; 
}
