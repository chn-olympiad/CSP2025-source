#include<bits/stdc++.h>
using namespace std;
int n,q;
long long ans=0;
string x,y;
struct nod{
	string x,y;
}a[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		int lle=x.size();
		ans=0;
		for(int j=1;j<=n;j++){
			int len=a[j].x.size();
			for(int k=0;k+len-1<lle;k++){
				int fl=1;
				for(int l=0;l<k;l++){
					if(x[l]!=y[l]){
						fl=0;
						break;
					}
				}
				for(int l=0;l<len;l++){
					if(x[k+l]!=a[j].x[l]||a[j].y[l]!=y[k+l]){
						fl=0;
						break;
					}
				}
				for(int l=k+len;l<lle;l++){
					if(x[l]!=y[l]){
						fl=0;
						break;
					}
				}
				if(fl){
//					cout<<a[j].x<<" "<<a[j].y<<" "<<k<<endl;
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
