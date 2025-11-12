#include<bits/stdc++.h>
using namespace std;
#define int long long
struct stu{int a,b,c,bm;};
stu s[100001];
vector<int> ans;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		int sum=0,sum1=0,sum2=0,sum3=0;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(max(s[i].a,max(s[i].b,s[i].c))==s[i].a){
				sum1++;s[i].bm=1;
			}
			else if(max(s[i].a,max(s[i].b,s[i].c))==s[i].b){
				sum2++;s[i].bm=2;
			}
			else if(max(s[i].a,max(s[i].b,s[i].c))==s[i].c){
				sum3++;s[i].bm=3;
			}
			sum+=max(s[i].a,max(s[i].b,s[i].c));
		}
		if(sum1>n/2){
			for(int i=1;i<=n;i++){
				if(s[i].bm!=1)continue;
				ans.push_back(max(s[i].b,s[i].c)-s[i].a);
			}
		}
		else if(sum2>n/2){
			for(int i=1;i<=n;i++){
				if(s[i].bm!=2)continue;
				ans.push_back(max(s[i].c,s[i].a)-s[i].b);
			}
		}
		else if(sum3>n/2){
			for(int i=1;i<=n;i++){
				if(s[i].bm!=3)continue;
				ans.push_back(max(s[i].a,s[i].b)-s[i].c);
			}
		}
		sort(ans.begin(),ans.end());
		reverse(ans.begin(),ans.end());
		for(int i=0;i<max(sum1,max(sum2,sum3))-n/2;i++)sum+=ans[i];
		for(int i=0;i<ans.size();i++)ans[i]=-1e18;
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}