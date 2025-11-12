#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int q,r[5],n,a[5],ans=0,s[N],m[N],mi[N],bs=1,c[N],d[N]; 
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[1]>>a[2]>>a[3];
			m[i]=max(a[1],max(a[2],a[3]));
			if(a[1]==m[i]) d[i]=1;
			else if(a[2]==m[i]) d[i]=2;
			else d[i]=3;
			r[d[i]]++;
			mi[i]=min(a[1],min(a[2],a[3]));
			c[i]=a[1]+a[2]+a[3]-m[i]-mi[i];
			ans+=c[i];
			s[i]=m[i]-c[i];
			if(a[3]) bs=0;
		}
		if(n==2){
			if(d[1]==d[2]){
				ans=max(m[1]+c[2],m[2]+c[1]);
			}
			else ans=m[1]+m[2];
		}
		else if(bs){
			sort(s+1,s+n+1,cmp);
			if(r[2]>n/2) q=2;
			if(r[1]>n/2) q=1;
			for(int i=1,j=0;i<=n;i++){
				if(d[i]==q){
					j++;
					ans+=s[i];
				} 
				if(j==n/2) break;
			}
		}
		else if(n==4){
			for(int i=1;i<=4;i++){
				for(int j=1;j<=4;j++){
					if(i!=j) ans=max(ans,m[i]+c[j]);
				}
			}
		}
		cout<<ans<<endl;
		bs=1; ans=0; memset(r,0,sizeof(r));
	}
	return 0;
}