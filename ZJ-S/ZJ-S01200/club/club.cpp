#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

int a[N][5];

struct st{
	int a,b,c,i;
	bool operator<(const st &A) const{
		if(i==1){
			return min(abs(a-b),abs(a-c))<min(abs(A.a-A.c),abs(A.a-A.b));
		}
		else if(i==2){
			return min(abs(c-b),abs(a-b))<min(abs(A.b-A.c),abs(A.b-A.a));
		}
		else if(i==3){
			return min(abs(c-b),abs(a-c))<min(abs(A.a-A.c),abs(A.c-A.b));
		}
	}
};

vector<st>v[5];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int t,n,cnt;
	int s1,s2,s3;
	scanf("%d",&t);
	while(t--){
		int ans=0;
		for(int i=1;i<=3;i++){
			v[i].clear();
		}
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			int ma=max({a[i][1],a[i][2],a[i][3]});
			if(a[i][1]==ma){
				v[1].push_back({a[i][1],a[i][2],a[i][3],1});
			}
			else if(a[i][2]==ma){
				v[2].push_back({a[i][1],a[i][2],a[i][3],2});
			}
			else if(a[i][3]==ma){
				v[3].push_back({a[i][1],a[i][2],a[i][3],3});
			}
			ans+=ma;
		}
		sort(v[1].begin(),v[1].end());
		sort(v[2].begin(),v[2].end());
		sort(v[3].begin(),v[3].end());
		s1=v[1].size(),s2=v[2].size(),s3=v[3].size();
//		cout<<s1<<' '<<s2<<' '<<s3<<' '<<endl;
		int ss1=0,ss2=0,ss3=0;
		if(s1>n/2){
			for(auto x:v[1]){
				if(s1-ss1<=n/2) break;
				if(x.b>x.c&&s2+1<=n/2){
					s2++;
					ss1++;
					ans+=x.b;
					ans-=x.a;
				}
				else{
					s3++;
					ss1++;
					ans+=x.c;
					ans-=x.a;
				}
			}
		}
		else if(s2>n/2){
			for(auto x:v[2]){
				if(s2-ss2<=n/2) break;
				if(x.a>x.c&&s1+1<=n/2){
					ss2++;
					s1++;
					ans+=x.a;
					ans-=x.b;
				}
				else{
					s3++;
					ss2++;
					ans+=x.c;
					ans-=x.b;
				}
			}
		}
		else{
			for(auto x:v[3]){
				if(s3-ss3<=n/2) break;
				if(x.a>x.b&&s1+1<=n/2){
					ss3++;
					s1++;
					ans+=x.a;
					ans-=x.c;
				}
				else{
					ss3++;
					s2++;
					ans-=x.c;
					ans+=x.b;
				}
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//666,zhe ge dian nao mei you zhong wen shu ru fa
