#include <bits/stdc++.h>
using namespace std;

struct Member{
	int F,S,T;
	int Max,Min,Mid;
};

Member a[100005];
int t,n,Ans,F,T,S;

bool cmp(Member x, Member y){
	return (x.Max-x.Mid)>(y.Max-y.Mid);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		Ans=0;S=0,F=0,T=0;
		
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].F,&a[i].S,&a[i].T);
			a[i].Max=max(a[i].F,max(a[i].S,a[i].T));
			a[i].Min=min(a[i].F,min(a[i].S,a[i].T));
			a[i].Mid=a[i].F+a[i].S+a[i].T-a[i].Max-a[i].Min;
		}
		
		sort(a+1,a+n+1,cmp);
		
		for(int i=1;i<=n;i++){
			if(a[i].Max==a[i].F){
				if(F<n/2)F++,Ans+=a[i].Max;
				else Ans+=a[i].Mid;
			}
			else if(a[i].Max==a[i].S){
				if(S<n/2)S++,Ans+=a[i].Max;
				else Ans+=a[i].Mid;
			}
			else if(a[i].Max==a[i].T){
				if(T<n/2)T++,Ans+=a[i].Max;
				else Ans+=a[i].Mid;
			}
		}
		
		printf("%d\n",Ans);
	}
}
