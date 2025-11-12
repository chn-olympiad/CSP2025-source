#include<bits/stdc++.h>
using namespace std;
const int NMAX=1e5+50;
struct members{
	int first;
	int second;
	int third;
	int used;
	int want[4]{0,0,0,0};
}m[NMAX];
bool cmp1(members x,members y){
	if(x.used!=y.used){
		return x.used<y.used;
	}
	else if(x.first!=y.first){
		return x.first>y.first;
	}
	else return false;
}
bool cmp2(members x,members y){
	if(x.used!=y.used){
		return x.used<y.used;
	}
	else if(x.second!=y.second){
		return x.second>y.second;
	}
	else return false;
}
bool cmp3(members x,members y){
	 if(x.used!=y.used){
		return x.used<y.used;
	}
	else if(x.third!=y.third){
		return x.third>y.third;
	}
	else return false;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int cnt[4]{0,0,0,0};
		int n;	
		cin>>n;	 
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&m[i].first,&m[i].second,&m[i].third);
			m[i].used=0;
		}
		int sum=0;
		if(n==2){
			sum+=max(m[1].first,max(m[1].second,m[1].third));
			sum+=max(m[2].first,max(m[2].second,m[2].third));
			printf("%d\n",sum);
			continue;
		}
		else if(m[1].second==0&&m[1].third==0){
			for(int i=1;i<=n/2;i++){
				sum+=m[1].first;
			}
			printf("%d\n",sum);
			continue;
		}
		else if(m[1].third==0){
			for(int i=1;i<=n;i++){
				if(m[i].first>m[i].second&&cnt[1]<=n/2){
					sum+=m[i].first; 
					cnt[1]++;
				}
				else if(m[i].first>m[i].second&&cnt[1]>n/2){
					sum+=m[i].second;
					cnt[2]++;
				}
				else if(m[i].second>m[i].first&&cnt[2]<=n/2){
					sum+=m[i].second;
					cnt[2]++;
				}
				else if(m[i].second>m[i].first&&cnt[2]>n/2){
					sum+=m[i].first; 
					cnt[1]++;
				}
			}
			printf("%d\n",sum);
			continue;
			}
		for(int i=1;i<=n;i++){
			int maxx=-1,maxxx,midd,minn=2147483647,minnn;
				if(m[i].first>maxx){
					maxx=m[i].first;
					maxxx=1;
				}
				if(m[i].first<minn){
					minn=m[i].first;
					minnn=1;
				}
				if(m[i].second>maxx){
					maxx=m[i].second;
					maxxx=2;
				}
				if(m[i].second<minn){
					minn=m[i].second;
					minnn=2;
				}
				if(m[i].third>maxx){
					maxx=m[i].third;
					maxxx=3;
				}
				if(m[i].third<minn){
					minn=m[i].third;
					minnn=3;
			}
			midd=6-maxxx-minnn;
			m[i].want[1]=maxxx;
			m[i].want[2]=midd;
			m[i].want[3]=minnn;
		}
		for(int i=1;i<=n;i++){
			if(cnt[m[i].want[1]]<=n/2){
				sum+=m[i].first;
			}
			else{
				if(cnt[m[i].want[2]]<=n/2){
					sum+=m[i].second;
				}
				else{
					sum+=m[i].third;
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
