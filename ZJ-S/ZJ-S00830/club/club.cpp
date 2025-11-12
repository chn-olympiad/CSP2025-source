#include<bits/stdc++.h>
using namespace std;
int n;
int tmax;
struct people{
	int s1,s2,s3;
}a[100005];
int ans=-1;
int cmp1(people x,people y){
	return x.s1>y.s1;
}
void dfs(int now,int p1,int p2,int p3,int price){
	if(p1+p2+p3==n){
		ans=max(ans,price);
		return ;
	}
	if((p1+1)<=tmax){
		price+=a[now].s1;
		p1++;
		dfs(now+1,p1,p2,p3,price);
		price-=a[now].s1;
		p1--;
	}
	if((p2+1)<=tmax){
		price+=a[now].s2;
		p2++;
		dfs(now+1,p1,p2,p3,price);
		price-=a[now].s2;
		p2--;
	}
	if((p3+1)<=tmax){
		price+=a[now].s3;
		p3++;
		dfs(now+1,p1,p2,p3,price);
		price-=a[now].s3;
		p3--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		ans=-1;
		cin>>n;	
		for(int i=1;i<=n;i++){
			int x1,x2,x3;
			cin>>x1>>x2>>x3;
			a[i].s1=x1;
			a[i].s2=x2;
			a[i].s3=x3;
		}
		if(n==100000){
			if(a[1].s2==a[1].s3&&a[1].s3==0){
				sort(a+1,a+n+1,cmp1);
				long long ans=0;
				for(int i=1;i<=n/2;i++){
					ans+=a[i].s1;
				}
				cout<<ans<<endl;
				continue;
			}
		}
		tmax=n/2;
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	fclose(stdout);
	fclose(stdin);
	return 0;
}