#include<bits/stdc++.h>
using namespace std;
struct node{
	string x;
	string y;
};
int n,q;
node a[200025],b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
	for(int i=1;i<=q;i++){
		cin>>b.x>>b.y;
		long long ans=0;
		int len=b.x.length();
		for(int j=1;j<=n;j++){
			int lenb=a[j].x.length();
			for(int k=0;k<=len-lenb;k++){
				string s=b.x;
				bool ps=true;
				for(int l=k;l<k+lenb;l++){
					if(a[j].x[l-k]!=b.x[l]){
						ps=false;
						break;
					}s[l]=a[j].y[l-k];
				}if(ps and s==b.y){
					//cout<<j<<endl;
					ans++;
				}
			}
		}cout<<ans<<endl;
	}
	return 0;
}
