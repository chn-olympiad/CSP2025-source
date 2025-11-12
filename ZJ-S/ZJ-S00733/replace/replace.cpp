#include<bits/stdc++.h>
using namespace std;
const int N=2e5+17;
int n,q;
string s1[N],s2[N],t1,t2;
int S1[N],S2[N],cnt,sz1[N],sz2[N];
struct node{
	int dig,num;
}a[N];
int f(int x){
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid].dig<=x)l=mid+1;
		else r=mid-1;
	}
	return r;
}
bool cmp(node u,node v){
	return u.dig<v.dig;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		int x,y;
		for(int j=0;j<s1[i].size();j++){
			if(s1[i][j]=='b'){
				x=j;
				S1[i]=j;
				break;
			}
		}
		sz1[i]=s1[i].size();
		for(int j=0;j<s2[i].size();j++){
			if(s2[i][j]=='b'){
				y=j;
				S2[i]=j;
				break;
			}
		}
		sz2[i]=s2[i].size();
		a[++cnt].dig=y-x;
		a[cnt].num=i;
	}
	sort(a+1,a+cnt+1,cmp);
	while(q--){
		cin>>t1>>t2;
		int x,y;
		for(int j=0;j<t1.size();j++){
			if(t1[j]=='b'){
				x=j;
				break;
			}
		}
		for(int j=0;j<t2.size();j++){
			if(t2[j]=='b'){
				y=j;
				break;
			}
		}
		if(t1.size()!=t2.size()){
			cout<<0<<"\n";
			continue;
		}
		int pos=f(y-x);
		int ans=0;
		while(pos>0&&a[pos].dig==y-x){
			if(S1[a[pos].num]<=x&&sz1[a[pos].num]-S1[a[pos].num]<=t1.size()-x){
				ans++;
			}
			pos--;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
7 2
b b
ba ba
aab baa
abaa aaab
baaaa aaaba
aaaaab aaaaab
aaaaaba baaaaaa
abaa aaab
aaaaaaabaaaaaaa aaaaaaaaabaaaaa

*/