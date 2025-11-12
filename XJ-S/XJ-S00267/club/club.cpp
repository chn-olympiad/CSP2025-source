#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct no{
	int num,st,bm,vis;
}s[N*3];
int t,n,a,b,c;
int ans=0;
int nm[5];
bool cmp(no x,no y){
	if(x.st>y.st) return true;
	return false;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int f=0;
	while(t--){
		f=0;
		cin>>n;
		for(int i=0;i<n*3;i+=3){
			cin>>a>>b>>c;
			if(b!=0||c!=0)
			f=1;
			s[i].num=i+1;
			s[i].vis=0;
			s[i].st=a;
			s[i].bm=1;
			s[i+1].num=i+1;
			s[i+1].vis=0;
			s[i+1].st=b;
			s[i+1].bm=2;
			s[i+2].num=i+1;
			s[i+2].vis=0;
			s[i+2].st=c;
			s[i+2].bm=3;
		}
		
		sort(s+0,s+n+n+n,cmp);
		if(f==0){
			for(int i=0;i<n/2;i++){
				ans+=s[i].st;
			}
			cout<<ans<<endl;
			ans=0;
			continue;
		}
		memset(nm,0,sizeof(nm));
		for(int i=0;i<n;i++){
			if(nm[s[i].bm]<n/2&&s[i].vis==0){
				ans+=s[i].st;
				nm[s[i].bm]++;
				for(int j=i;j<n;j++){
					if(s[j].num==s[i].num){
						s[j].vis=1;
					}
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}

