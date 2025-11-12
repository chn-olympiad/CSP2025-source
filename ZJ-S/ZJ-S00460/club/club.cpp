#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
int t,n,cnt[5];
struct node{
	int a,b,c,ch;
}s[N];
int mx(int x){
	if(s[x].a>s[x].b){
		if(s[x].a>s[x].c) return 1;
		else return 3;
	}
	else{
		if(s[x].b>s[x].c) return 2;
		else return 3;
	}
}
int me(int x){
	return s[x].a+s[x].b+s[x].c-max(s[x].a,max(s[x].b,s[x].c))-min(s[x].a,min(s[x].b,s[x].c));
}
bool cmp(node x,node y){
	return x.ch>y.ch;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			s[i].ch=max(s[i].a,max(s[i].b,s[i].c))-me(i);
		}
		sort(s+1,s+1+n,cmp);
		ll ans=0;
		for(int i=1;i<=n;i++){
			if(cnt[mx(i)]==n/2) ans+=me(i);
			else{
				ans+=max(s[i].a,max(s[i].b,s[i].c));
				cnt[mx(i)]++;
			} 
		}
		cout<<ans<<endl;
	}

	return 0;
}
