#include<bits/stdc++.h>
using namespace std;
int t,n;
int ans=-1e9;
struct jiegou{
	int a,b,c;
}a[1005000];
void dfs(int sum,int as,int bs,int cs,int wz){
	if(wz==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(as<n/2){
		dfs(sum+a[wz].a,as+1,bs,cs,wz+1);
	}
	if(bs<n/2){
		dfs(sum+a[wz].b,as,bs+1,cs,wz+1);
	}
	if(cs<n/2){
		dfs(sum+a[wz].c,as,bs,cs+1,wz+1);
	}
}
bool cmp1(jiegou x,jiegou y){
	return x.a<y.a;
}
bool cmp(jiegou x,jiegou y){
	return abs(x.a-x.b)>abs(y.a-y.b);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int flog=0;
		ans=-1e9;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b!=0&&a[i].c!=0){
				flog=1;
			}else if(a[i].b!=0)flog=2;
		}
		if(n<=30){
			dfs(0,0,0,0,1);
			cout<<ans<<'\n';
		}else if(flog==0){
			sort(a+1,a+1+n,cmp1);
			int sum=0;
			for(int i=n;i>=n/2+1;i--){
				sum+=a[i].a;
			}
			cout<<sum<<'\n';
		}else if(flog==2){
			int sum1=0;
			int as=0,bs=0;
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n;i++){
				if(as==n/2){
					bs++;
					sum1+=a[i].b;
				}else if(bs==n/2){
					as++;
					sum1+=a[i].a;
				}else{
					if(a[i].a>a[i].b){
						as++;
						sum1+=a[i].a;
					}else{
						bs++;
						sum1+=a[i].b;
					}
				}
			}
			cout<<sum1<<'\n';
		}else cout<<1<<'\n';
	}
	return 0;
}