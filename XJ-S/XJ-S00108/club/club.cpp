#include<bits/stdc++.h>
using namespace std; 
int t;
int n,ca=0,cb=0,cc=0,cnt=0,qq[100005][3],x[100005];
int solve(){
	int ans=0;
	sort(x+1,x+n+1);
	for(int i=1;i<=n/2;i++){
		cnt-=x[i];
	}
	return cnt;
}
void init(){
	ca=0;cb=0;cc=0;cnt=0;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		init();
		cin>>n;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			int ppp[3];
			ppp[1]=a;
			ppp[2]=b;
			ppp[3]=c;
			sort(ppp+1,ppp+4);
			qq[i][1]=ppp[1];
			qq[i][2]=ppp[2];
			qq[i][3]=ppp[3];
			x[i]=ppp[2]-ppp[1];
			if(a>=b&&a>=c){
				ca++;
				cnt+=a;
				//cout<<"a";
				continue;
			}
			if(b>=a&&b>=c){
				cb++;
				cnt+=b;
				//cout<<"b";
				continue;
			}
			if(c>=a&&c>=b){
				cc++;
				cnt+=c;
				//cout<<"c";
				continue;
			}
		}
		if(ca<=n/2&&cb<=n/2&&cc<=n/2){
			cout<<cnt<<endl;
		}
		else{
			cout<<solve()<<endl;
		}
	}
	return 0;
}
