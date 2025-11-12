#include<bits/stdc++.h>
using namespace std;
int t,n;
int cnt,maxx;
int ca,cb,cc;
int a[100005],b[100005],c[100005];
void dg(int step){
	if(step==n+1){
		maxx=max(maxx,cnt);
		return ;
	}
	if(ca<n/2){
		ca++;
		cnt+=a[step];
		dg(step+1);
		ca--;
		cnt-=a[step];
	}
	if(cb<n/2){
		cb++;
		cnt+=b[step];
		dg(step+1);
		cb--;
		cnt-=b[step];
	}
	if(cc<n/2){
		cc++;
		cnt+=c[step];
		dg(step+1);
		cc--;
		cnt-=c[step];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		maxx=0;
		ca=cb=cc=0;
		bool f=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0||c[i]!=0){
				f=1;
			}
		}
		if(!f){
			sort(a+1,a+n+1);
			int cnt=0;
			for(int i=n;i>=n/2+1;i--){
				cnt+=a[i];
			}
			cout<<cnt<<endl;
		}else{
			dg(1);
			cout<<maxx<<endl;
		}
	}
}
