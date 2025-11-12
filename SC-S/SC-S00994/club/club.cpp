#include<bits/stdc++.h>
using namespace std;
int t,n,a,b,c,x,q,qq,aa,bb,cc;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a>>b>>c;
			if(a>b&&b>=c&&aa<=n/2||a>c&&c>=b&&aa+1<=n/2){
				x+=a;
				aa++;
			}else if(b>a&&a>=c&&bb<=n/2||b>c&&c>=a&&bb+1<=n/2){
				x+=b;
				bb++;
			}else if(c>a&&a>=b&&cc<=n/2||c>b&&b>=a&&cc+1<=n/2){
				x+=c;
				cc++;
			}
		}
		cout<<x<<endl;
		x=0;
		aa=0;
		bb=0;
		cc=0;	
	}
	return 0;
}