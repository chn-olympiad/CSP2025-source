#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5,K=2e6+5;
int n,k,a,s[N];
map<int,int> mp;//Ð¡ÓÅ»¯¡« 
map<int,bool> tmp;
struct node{int l,r;};
bool cmp(node x,node y){return x.r<y.r;}
vector<node> v;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	mp[0]=0;tmp[0]=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		s[i]=s[i-1]^a;
		int nd=s[i]^k;
		if(tmp[nd])v.push_back({mp[nd]+1,i});
		mp[s[i]]=i;tmp[s[i]]=1;
	}
	sort(v.begin(),v.end(),cmp);
	int last=0,ans=0;
	for(node t:v)
	if(t.l>last){
		last=t.r;ans++;
	}
	printf("%d\n",ans);
	return 0;
}
