#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Node{
	int a,b,c;
}s[100010];
bool cmp(Node x,Node y){
	return x.a>y.a;
}
bool cmp_(int x,int y){
	return x>y;
}
int d[100010];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,ans=0;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int cnt=0,cnt_=0;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			d[++ans]=s[i].a;
			d[++ans]=s[i].b;
			d[++ans]=s[i].c;
			if(s[i].b==0){
				cnt++;
			}
			if(s[i].c==0){
				cnt_++;
			}
		}
		sort(d+1,d+n+1,cmp_);
		if(cnt==n&&cnt_==n){
			int sum=0;
			sort(s+1,s+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				sum+=s[i].a;
			}
			cout<<sum<<'\n'; 
		} else if(cnt_==n){
			int sum=0;
			for(int i=1;i<=n;i++){
				if(i%2==1){
					sum+=s[i].a;
				}
				if(i%2==0){
					sum+=s[i].b;
				}
			}
			int sum_=0;
			for(int i=1;i<=n;i++){
				if(i%2==0){
					sum_+=s[i].a;
				}
				if(i%2==1){
					sum_+=s[i].b;
				}
			}
			int num=0;
			for(int i=1;i<=n/2;i++){
				num+=s[i].a;
			}
			for(int i=n/2+1;i<=n;i++){
				num+=s[i].b;
			}
			int num_=0;
			for(int i=1;i<=n/2;i++){
				num_+=s[i].a;
			}
			for(int i=n/2+1;i<=n;i++){
				num_+=s[i].b;
			}
			int p=max(sum,sum_),o=max(num,num_);
			int zd=max(p,o);
			cout<<zd<<'\n';
		} else if(n==2){
			int o=s[1].a+s[2].b;
			int o_=s[1].a+s[2].c;
			int p=s[1].b+s[2].a;
			int p_=s[1].b+s[2].c;
			int m=s[1].c+s[2].a;
			int m_=s[1].c+s[2].b;
			int zd=max(o,o_);
			zd=max(zd,max(p,p_));
			zd=max(zd,max(m,m_));
			cout<<zd<<'\n';
		} else{
			int sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=d[i];
			}	
			cout<<sum<<'\n';
		}
	}
	return 0;
}