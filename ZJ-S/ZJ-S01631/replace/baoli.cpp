#include<bits/stdc++.h>
using namespace std;
int n,q;
const int nn=2e5+5;
struct node{
	string a,b,c,d;
};
int cnt;
node upd[nn];
inline node get(string a,string b){
	int wz1;
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]){
			wz1=i;
			break;
		}
	}
	int wz2;
	for(int i=a.size()-1;i>=0;i--){
		if(a[i]!=b[i]) {
		wz2=i;break;}
	}
	node res;
	for(int i=wz1;i<=wz2;i++) res.a+=a[i],res.b+=b[i];
	for(int i=0;i<wz1;i++) res.c+=a[i];
	for(int i=wz2+1;i<a.size();i++) res.d+=a[i];
	reverse(res.c.begin(),res.c.end());
	return res;
}
inline bool prv(string a,string b){
	if(a.size()>b.size()) return 0;
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]) return 0;
	}
	return 1;
}
int main(){
	freopen("replace3.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
//		upd[i]=get(a,b);
		if(a==b) continue;
		upd[++cnt]=get(a,b);
	}
	for(int i=1;i<=1000;i++){
		string a,b;
		cin>>a>>b;
		node nw=get(a,b);
		int ans=0;
		for(int j=1;j<=cnt;j++){
			if(upd[j].a==nw.a&&upd[j].b==nw.b&&prv(upd[j].c,nw.c)&&prv(upd[j].d,nw.d)) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

