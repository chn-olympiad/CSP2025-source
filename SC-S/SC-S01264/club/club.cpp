#include<bits/stdc++.h>
using namespace std;
int T;
int n;
struct st{
	int a,b,c;
}s[200010]; 
struct st2{
	int v,id;
}cnt[200010];
st2 cntt[200010],cnttt[200010];
bool cmp(st2 a,st2 b){
	if(a.v<b.v){
		return 1;
	}
	return 0;
}
int vis[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<=100003;i++){
			vis[i]=cnt[i].v=cntt[i].v=cnttt[i].v=cnt[i].id=cntt[i].id=cnttt[i].id=0;
		}
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			int ma=max(max(s[i].a,s[i].b),s[i].c);
			if(ma==s[i].a){
				vis[i]=1;
			}
			if(ma==s[i].b){
				vis[i]=2;
			}
			if(ma==s[i].c){
				vis[i]=3;
			}
		}
		int sx=n/2;
		int cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==1){
				cnt1++;
			}
			if(vis[i]==2){
				cnt2++;
			}
			if(vis[i]==3){
				cnt3++;
			}
		}
		if(cnt1>sx){
			int idx=0;
			for(int i=1;i<=n;i++){
				if(vis[i]==1){
					cnt[++idx]={abs(s[i].a-max(s[i].b,s[i].c)),i};
				}
			}
			int ky1=sx-cnt2;
			sort(cnt+1,cnt+idx+1,cmp);
			int tmp=cnt1;
			for(int i=1;i<=tmp-sx;i++){
				cnt1--;
				if(s[cnt[i].id].b>s[cnt[i].id].c&&ky1){
					vis[cnt[i].id]=2;
					cnt2++;
					ky1--;
				}else{
					vis[cnt[i].id]=3;
					cnt3++;
				}
			}
		}
		if(cnt2>sx){
			int idx=0;
			for(int i=1;i<=n;i++){
				if(vis[i]==2){
					cntt[++idx]={abs(s[i].b-max(s[i].a,s[i].c)),i};
				}
			}
			sort(cntt+1,cntt+idx+1,cmp);
			int tmp=cnt2;
			int ky1=sx-cnt1;
			for(int i=1;i<=tmp-sx;i++){
				cnt2--;
				if(s[cntt[i].id].a>s[cntt[i].id].c&&ky1){
					vis[cntt[i].id]=1;
					cnt1++;
					ky1--;
				}else{
					vis[cntt[i].id]=3;
					cnt3++;
				}
			}
		}
		if(cnt3>sx){
			int idx=0;
			for(int i=1;i<=n;i++){
				if(vis[i]==3){
					cnttt[++idx]={abs(s[i].c-max(s[i].b,s[i].a)),i};
				}
			}
			int ky1=sx-cnt1;
			sort(cnttt+1,cnttt+idx+1,cmp);
			int tmp=cnt3;
			for(int i=1;i<=tmp-sx;i++){
				cnt3--;
				if(s[cnttt[i].id].a>s[cnttt[i].id].b&&ky1){
					vis[cnttt[i].id]=1;
					cnt1++;
					ky1--;
				}else{
					vis[cnttt[i].id]=2;
					cnt2++;
				}
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==1){
				ans+=s[i].a;
			}
			if(vis[i]==2){
				ans+=s[i].b;
			}
			if(vis[i]==3){
				ans+=s[i].c;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}