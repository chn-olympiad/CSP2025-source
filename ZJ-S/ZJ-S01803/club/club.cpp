#include<bits/stdc++.h>
using namespace std;
int t,n,ans,x[4],s[114514][4];
struct st{
	int k,l;
}a[100007];
bool cmp(st a,st b){
	return a.l<b.l;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(x,0,sizeof(x));
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)scanf("%d",&s[i][j]);
			if(s[i][1]>=s[i][2] && s[i][1]>=s[i][3]){
				a[i].k=1;
				ans+=s[i][1];
				a[i].l=s[i][1]-max(s[i][2],s[i][3]);
				x[1]++;
			}
			if(s[i][2]>s[i][1] && s[i][2]>=s[i][3]){
				a[i].k=2;
				ans+=s[i][2];
				a[i].l=s[i][2]-max(s[i][1],s[i][3]);
				x[2]++;
			}
			if(s[i][3]>s[i][1] && s[i][3]>s[i][2]){
				a[i].k=3;
				ans+=s[i][3];
				a[i].l=s[i][3]-max(s[i][1],s[i][2]);
				x[3]++;
			}
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=3;i++){
			for(int j=1;x[i]>n/2;j++){
				if(a[j].k==i){
					ans-=a[j].l;
					x[i]--;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
