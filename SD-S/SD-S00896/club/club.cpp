#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int _,n,m,a[maxn][4],v[maxn],sum,cnt[4],now[maxn],ans;
struct no{
	int a,b,c;
}e[maxn];
int cm(no a,no b){
	return a.a>b.a;
}
int noww[maxn];
int df(int s){
	if(s>n){
		int sum=0;
		for(int i = 1;i<=n;i++){
			sum+=a[i][v[i]];
		}
		ans=max(ans,sum);
		return 0;
	}
	for(int i = 1;i<=3;i++){
		if(cnt[i]>=n/2)continue;
		cnt[i]++;
		v[s]=i;
		df(s+1);
		cnt[i]--;
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cin>>_;
	while(_--){
	ans=0;
	memset(v,0,sizeof v);
	memset(now,0,sizeof now);
	sum=0;
	cnt[3]=cnt[1]=cnt[2]=0;
	cin>>n;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=3;j++){
			cin>>a[i][j];
			e[i*3+j-3].a=a[i][j];
			e[i*3+j-3].b=j;
			e[i*3+j-3].c=i;
		}
	}
	if(n<=10){
		df(1);
		cout<<ans;
		continue;
	}
	sort(e+1,e+1+n*3,cm);
//	for(int i = 1;i<=n*3;i++){
//		cout<<e[i].a<<" ";
//	}
	for(int i = 1;i<=3*n;i++){
		if(!v[e[i].c]&&cnt[e[i].b]<n/2){
			sum+=e[i].a;
			v[e[i].c]=1;
			cnt[e[i].b]++;
			now[e[i].c]=e[i].b;
		}
	}
	if(n<=200){
		for(int k = 1;k<=n;k++){
			for(int i = 1;i<=n;i++){
				for(int j = 1;j<=n;j++){
					if(i==j)continue;
					if(a[i][now[j]]+a[j][now[i]]>a[i][now[i]]+a[j][now[j]]){
						sum+=a[i][now[j]]+a[j][now[i]]-a[i][now[i]]-a[j][now[j]];
						now[i]^=now[j];
						now[j]^=now[i];
						now[i]^=now[j];
					}
				}
			}
		}
		cout<<sum<<"\n";
	}
	}
	return 0;
}
//4 1
//4 1
//3 3
//2 1
//2 1
//2 1
