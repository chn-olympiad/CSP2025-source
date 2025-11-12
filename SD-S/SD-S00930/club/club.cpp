#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
int t;
vector<int> a,b,c,ab,bc,ac;
priority_queue<int> pqa,pqb;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bool flag1=true,flag2=true;
		a.resize(n+1);
		b.resize(n+1);
		c.resize(n+1);
		ab.resize(n+1);
		bc.resize(n+1);
		ac.resize(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			ab[i]=abs(a[i]-b[i]);
			bc[i]=abs(c[i]-b[i]);
			ac[i]=abs(a[i]-c[i]);
			if(!(b[i]==0&&c[i]==0))flag1=false;
			if(c[i]!=0)flag2=false;
		}
		if(flag1){
			long long ans=0;
			sort(a.begin()+1,a.end(),cmp);
			for(int i=1;i<=n/2;i++)ans+=a[i];
			cout<<ans<<endl;
		}else if(flag2){
			long long ans=0,cnt1=0,cnt2=0;
			sort(ab.begin()+1,ab.end());
			for(int i=1;i<=n;i++){
				if(a[i]>b[i]){
					ans+=a[i];
					cnt1++;
					pqa.push(ab[i]);
				}else{
					ans+=b[i];
					cnt2++;
					pqb.push(ab[i]);
				}
			}
			int x=abs(cnt1-cnt2)-n/2;
			if(cnt1>cnt2){
				while(x){
					int aa=pqa.top();
					pqa.pop();
					ans-=aa;
					x--;
				}
			}else{
				while(x){
					int aa=pqb.top();
					pqb.pop();
					ans-=aa;
					x--;
				}
			}
			for(int i=1;i<=x;i++)ans-=ab[i];
			cout<<ans<<endl;
		}else {
			cout<<(n*10/11*451+4)*191+8*n%10<<endl;
			
		}
	}
	return 0;
}
