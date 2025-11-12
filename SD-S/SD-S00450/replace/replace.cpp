#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
#define re register
using namespace std;
const int N=2e5+10;
int n,q;
struct node{
	string a,b;
	int front,back;
}a[N];
string x,y;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(re int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b;
		for(int j=0;i<a[i].a.size();j++){
			if(a[i].a[j]!=a[i].b[j]){
				a[i].front=j;
				break;
			}
		}
		for(re int j=a[i].a.size()-1;j>=0;j--){
			if(a[i].a[j]!=a[i].b[j]){
				a[i].back=j;
				break;
			}
		}
//		cout<<a[i].front<<' '<<a[i].back<<endl;
	}
	while(q--){
		cin>>x>>y;
		int p=0,len=0,ans=0;
		for(re int i=0;i<x.size();i++){
			if(x[i]!=y[i]){
				p=i;
				break;
			}
		}
		for(re int i=x.size()-1;i>=0;i--){
			if(x[i]!=y[i]){
				len=i-p+1;
				break;
			}
		}
//		cout<<p<<' '<<len<<endl;
		for(re int i=1;i<=n;i++){
			bool flag=1;
			if(a[i].back-a[i].front+1!=len) continue;
			if(p-a[i].front<0) continue;
			if(p-a[i].front+len>x.size()) continue;
			for(re int j=p-a[i].front;j<p-a[i].front+len;j++){
				if(a[i].a[j-p+a[i].front]!=x[j]||a[i].b[j-p+a[i].front]!=y[j]){
					flag=0;
					break;
				}
			}
			ans+=flag;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
