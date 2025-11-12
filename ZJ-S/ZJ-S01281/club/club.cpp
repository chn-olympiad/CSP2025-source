#include<bits/stdc++.h>
//#define int long long
using namespace std;
struct students{
	int a1;
	int a2;
	int a3;
}s[100005];
int n;
int m1[100005],m2[100005];
int ans,cnt1,cnt2,cnt3,sum;
void dfs(int x){
	if(x==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(cnt1*2<n){
		sum+=s[x].a1;
		cnt1++;
		dfs(x+1);
		cnt1--;
		sum-=s[x].a1;
	}
	if(cnt2*2<n){
		sum+=s[x].a2;
		cnt2++;
		dfs(x+1);
		cnt2--;
		sum-=s[x].a2;
	}
	if(cnt3*2<n){
		sum+=s[x].a3;
		cnt3++;
		dfs(x+1);
		cnt3--;
		sum-=s[x].a3;
	}
	
}
bool cmp(students x,students y){
	return x.a1>y.a1;
}
bool cmp1(int x,int y){
	if(s[x].a1==s[y].a1) return s[x].a2<s[y].a2;
	return s[x].a1>s[y].a1;
}
bool cmp2(int x,int y){
	if(s[x].a2==s[y].a2) return s[x].a1<s[y].a1;
	return s[x].a2>s[y].a2;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		cnt1=0;
		cnt2=0;
		cnt3=0;
		ans=0;
		sum=0;
		int u=0,v=0;
		for(int i=1;i<=n;i++){
			cin>>s[i].a1>>s[i].a2>>s[i].a3;
			if(s[i].a2!=0) u=1;
			if(s[i].a3!=0) v=1;
		}
		if(u==0&&v==0){
			sort(s+1,s+1+n,cmp);
			for(int i=1;i*2<=n;i++){
				ans+=s[i].a1;
			}
			cout<<ans<<endl;
			continue;
		}
		else if(v==0){
			for(int i=1;i<=n;i++){
				if(s[i].a1>=s[i].a2){
					ans+=s[i].a1;
					cnt1+=1;
					m1[cnt1]=i;
				}else{
					ans+=s[i].a2;
					cnt2+=1;
					m2[cnt2]=i;
				}
			}
			if(cnt1==cnt2){
				cout<<ans<<endl;
				continue;
			}
			else if(cnt1>cnt2){
				sort(m1+1,m1+1+cnt1,cmp1);
				while(cnt1>cnt2){
					ans-=s[m1[cnt1]].a1;
					ans+=s[m1[cnt1]].a2;
					cnt1--;
					cnt2++;
				}
				cout<<ans<<endl;
				continue;
			}
			else if(cnt1<cnt2){
				sort(m2+1,m2+1+cnt2,cmp2);
				while(cnt1<cnt2){
					ans-=s[m2[cnt2]].a2;
					ans+=s[m2[cnt2]].a1;
					cnt2--;
					cnt1++;
				}
				cout<<ans<<endl;
				continue;
			}
		}
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
