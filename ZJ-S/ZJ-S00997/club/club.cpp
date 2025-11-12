#include<bits/stdc++.h>
using namespace std;
int a[100005][4];
int choose[100005];
priority_queue<int,vector<int>,greater<int> >que;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		while(!que.empty())que.pop();
		int n;
		scanf("%d",&n);
		int num1=0,num2=0,num3=0,ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",a[i]+1,a[i]+2,a[i]+3);
			if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3])
				ans+=a[i][1],num1++,choose[i]=1;
			else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3])
				ans+=a[i][2],num2++,choose[i]=2;
			else if(a[i][3]>=a[i][2] && a[i][3]>=a[i][1])
				ans+=a[i][3],num3++,choose[i]=3;
		}
		if(num1>n/2){
			for(int i=1;i<=n;i++)
				if(choose[i]==1)
					que.push(min(a[i][1]-a[i][2],a[i][1]-a[i][3]));
			while(num1>n/2){
				ans-=que.top();que.pop();
				num1--;
			}
		}
		else if(num2>n/2){
			for(int i=1;i<=n;i++)
				if(choose[i]==2)
					que.push(min(a[i][2]-a[i][1],a[i][2]-a[i][3]));
			while(num2>n/2){
				ans-=que.top();que.pop();
				num2--;
			}
		}
		else if(num3>n/2){
			for(int i=1;i<=n;i++)
				if(choose[i]==3)
					que.push(min(a[i][3]-a[i][2],a[i][3]-a[i][1]));
			while(num3>n/2){
				ans-=que.top();que.pop();
				num3--;
			}
		}
		printf("%d\n",ans);
	}
}
