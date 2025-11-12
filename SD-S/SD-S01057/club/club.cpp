#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5; 
int T,n,j,suma,sumb,sumc;
struct node{
	int a,b,c;
}x[N]; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int maxn=-1,f2=0,f3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			f2=max(f2,x[i].b),f3=max(f3,x[i].c);
		}
		if(f2||f3){
			for(int i=1;i<=pow(3,n)-1;i++){
				int t=i,sum=0,cnt=0,a=0,b=0,c=0;
				while(cnt<n){
					cnt++;
					if(t%3==0)	sum+=x[cnt].a,a++;
					if(t%3==1)	sum+=x[cnt].b,b++;
					if(t%3==2)	sum+=x[cnt].c,c++;
					t/=3;
				}
				if(sum>maxn&&a<=n/2&&b<=n/2&&c<=n/2)	maxn=sum;
			} 
			cout<<maxn<<'\n';
		}
		else{
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=x[i].a;
			} 
			cout<<ans<<'\n';
		}
	}
	return 0;
}

