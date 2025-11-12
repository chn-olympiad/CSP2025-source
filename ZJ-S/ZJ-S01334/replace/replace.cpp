#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n,m;
string a,b,c[N];
map<string,string>ma;
bool check(int x,string y){
	string k=a;
	k.erase(x,y.length());
	k.insert(x,ma[y]);
	return k==b;
}
void solve(){
	cin>>a>>b;
	int an=0,ans=0;
	if(a.length()>50){
		int an1=0,an2=0;
		for(int i=0;i<24;i++){
			if(a[i]!=b[i])an++;
		}
		for(int i=a.length()-1;i>=a.length()-24;i--){
			if(a[i]!=b[i])an++;
		}
	}
	for(int i=1;i<=n;i++){
		if(c[i].length()<an)continue;
		int l=0;
		while(l<a.length()){
//			printf("(%d)\n",l);
			l=a.find(c[i],l);
			if(l==-1)break;
			if(check(l,c[i]))ans++;
			l++;
		}
	}
	cout<<ans<<"\n";
}
int main(){
 	freopen("replace.in","r",stdin);
 	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		string x;
		cin>>c[i]>>x;
		ma[c[i]]=x;
	}
	while(m--){
		solve();
	}
}
