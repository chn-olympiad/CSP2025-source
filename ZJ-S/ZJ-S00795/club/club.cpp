#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 200005
int n,maxn[N],id[N],mi[N],to[N],b[N],c[N],d[N][5],t[N];
struct node{
	int x,id;
}a[N];
bool cmp2(node a,node b){
	return a.x<b.x;
}
bool check(){
	for(int i=1;i<=n;i++){
		for(int j=2;j<=3;j++){
			if(d[i][j]!=0)return false;
		}
	}
	return true;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>d[i][j];
		}
	}
	if(check()){
		int ty=0,ans=0;
		for(int i=1;i<=n;i++)t[++ty]=d[i][1];
		sort(t+1,t+ty+1);
		for(int i=n;i>=n-n/2+1;i--){
			ans+=t[i];
		}
		cout<<ans<<"\n";
		return ;
	}
	for(int i=1;i<=n;i++){
		maxn[i]=d[i][1],id[i]=1;
		for(int j=2;j<=3;j++){
			if(d[i][j]>maxn[i])maxn[i]=d[i][j],id[i]=j;
		}
	}
	int cnt1=0,cnt2=0,cnt3=0;
	for(int i=1;i<=n;i++){
		if(id[i]==1)cnt1++;
		else if(id[i]==2)cnt2++;
		else if(id[i]==3)cnt3++;
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans+=maxn[i];
	if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
		cout<<ans<<"\n";
		return ;
	}
	for(int i=1;i<=n;i++){
		if(id[i]==1){
			if(d[i][2]>d[i][3])mi[i]=d[i][2],to[i]=2;
			else mi[i]=d[i][3],to[i]=3;
		}
		else if(id[i]==2){
			if(d[i][1]>d[i][3])mi[i]=d[i][1],to[i]=1;
			else mi[i]=d[i][3],to[i]=3;
		}
		else if(id[i]==3){
			if(d[i][1]>d[i][2])mi[i]=d[i][1],to[i]=1;
			else mi[i]=d[i][2],to[i]=2;
		}
	}

	if(cnt1>n/2){
		int num2=0,num3=0;
		for(int i=1;i<=n;i++){
			if(id[i]==1&&to[i]==2){
				b[++num2]=maxn[i]-mi[i];
			}
			else if(id[i]==1&&to[i]==3){
				c[++num3]=maxn[i]-mi[i];
			}
		}
		int yu2=n/2-cnt2,yu3=n/2-cnt3,ned=cnt1-n/2,tot=0;
		for(int i=1;i<=num2;i++)a[++tot].x=b[i],a[tot].id=2;
		for(int i=1;i<=num3;i++)a[++tot].x=c[i],a[tot].id=3;
		sort(a+1,a+tot+1,cmp2);
		int use=0;
		for(int i=1;i<=tot;i++){
			if(use==ned)break;
			if(a[i].id==2){
				if(cnt2<n/2)cnt2++,use++,ans-=a[i].x;
			}
			else if(a[i].id==3){
				if(cnt3<n/2)cnt3++,use++,ans-=a[i].x;
			}
		}
		cout<<ans<<"\n";
		return ;
	}
	else if(cnt2>n/2){
		int num2=0,num3=0;
		for(int i=1;i<=n;i++){
			if(id[i]==2&&to[i]==1){
				b[++num2]=maxn[i]-mi[i];
			}
			else if(id[i]==2&&to[i]==3){
				c[++num3]=maxn[i]-mi[i];
			}
		}
		int yu2=n/2-cnt1,yu3=n/2-cnt3,ned=cnt2-n/2,tot=0;
		for(int i=1;i<=num2;i++)a[++tot].x=b[i],a[tot].id=1;
		for(int i=1;i<=num3;i++)a[++tot].x=c[i],a[tot].id=3;
		sort(a+1,a+tot+1,cmp2);
		int use=0;
		for(int i=1;i<=tot;i++){
			if(use==ned)break;
			if(a[i].id==1){
				if(cnt1<n/2)cnt1++,use++,ans-=a[i].x;
			}
			else if(a[i].id==3){
				if(cnt3<n/2)cnt3++,use++,ans-=a[i].x;
			}
		}
		cout<<ans<<"\n";
		return ;
	}
	else if(cnt3>n/2){
		int num2=0,num3=0;
		for(int i=1;i<=n;i++){
			if(id[i]==3&&to[i]==1){
				b[++num2]=maxn[i]-mi[i];
			}
			else if(id[i]==3&&to[i]==2){
				c[++num3]=maxn[i]-mi[i];
			}
		}
		int yu2=n/2-cnt1,yu3=n/2-cnt2,ned=cnt3-n/2,tot=0;
		for(int i=1;i<=num2;i++)a[++tot].x=b[i],a[tot].id=1;
		for(int i=1;i<=num3;i++)a[++tot].x=c[i],a[tot].id=2;
		sort(a+1,a+tot+1,cmp2);
		int use=0;
		for(int i=1;i<=tot;i++){
			if(use==ned)break;
			if(a[i].id==2){
				if(cnt1<n/2)cnt1++,use++,ans-=a[i].x;
			}
			else if(a[i].id==3){
				if(cnt2<n/2)cnt2++,use++,ans-=a[i].x;
			}
		}
		cout<<ans<<"\n";
		return ;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--)solve();
	return 0;
}
/*
Ren5Jie4Di4Ling5%
*/
