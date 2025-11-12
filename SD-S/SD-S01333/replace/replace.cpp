#include<bits/stdc++.h>
#define ll int
const ll N=2e6+100;
using namespace std;
ll n,Q;
char s1[N],s2[N];
ll pos[N][27],en[N],ID;
unordered_map<string,ll>mp[N];
void add(){
	ll t=0,l1=strlen(s1+1);
	string s;
	for(ll i=1;i<=l1;i++){
		if(!pos[t][s1[i]-'a'])pos[t][s1[i]-'a']=++ID;
		t=pos[t][s1[i]-'a'];
		s+=s2[i];
	}
	en[t]++;
	mp[t][s]++;
}
void Calc(){
	ll l1=strlen(s1+1),l2=strlen(s2+1);
	if(l1!=l2){
		printf("0\n");
		return;
	}
	ll hou=l1+1;
	for(ll i=l1;i>=1;i--){
		if(s1[i]==s2[i])hou=i;
		else break;
	}
	ll ans=0;
	for(ll top=1;top<=l1;top++){
		if(top>=1&&s1[top-1]!=s2[top-1])break;
		ll t=0;
		string s;
		for(ll i=top;i<=l1;i++){
			if(!pos[t][s1[i]-'a'])break;
			t=pos[t][s1[i]-'a'];
			s+=s2[i];
			if(en[t]&&i+1>=hou)ans+=mp[t][s]; 
		} 
	}
	printf("%d\n",ans);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&Q);
	for(ll i=1;i<=n;i++){
		scanf("%s%s",s1+1,s2+1);
		add();
	}
	while(Q--){
		scanf("%s%s",s1+1,s2+1);
		Calc(); 
	}
	return 0;
} 
