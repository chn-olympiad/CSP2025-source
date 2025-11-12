#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n;
struct node{
	int num[5];
	int sr[5];
}a[100005];
int cha[100005];
struct cntnode{
	int n,num;
};
bool cmpcnt(cntnode a,cntnode b){
	return a.num>b.num;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		cntnode cnt[5]={0,0,0,0,0};
		memset(a,0,sizeof a);
		cnt[1].n=1,cnt[2].n=2,cnt[3].n=3;
		for(int i=1;i<=n;i++){
			int a1,a2,a3;
			cin>>a1>>a2>>a3;
			if(a1>a2&&a1>a3){
				cnt[1].num++;
				a[i].sr[1]=1;
				if(a2>a3){
					a[i].sr[2]=2;
					a[i].sr[3]=3;
				}else{
					a[i].sr[2]=3;
					a[i].sr[3]=2;
				}
			}else if(a2>a1&&a2>a3){
				cnt[2].num++;
				a[i].sr[1]=2;
				if(a1>a3){
					a[i].sr[2]=1;
					a[i].sr[3]=3;
				}else{
					a[i].sr[2]=3;
					a[i].sr[3]=1;
				}
			}else if(a3>a1&&a3>a2){
				cnt[3].num++;
				a[i].sr[1]=3;
				if(a1>a2){
					a[i].sr[2]=1;
					a[i].sr[3]=2;
				}else{
					a[i].sr[2]=2;
					a[i].sr[3]=1;
				}
			}
			a[i].num[1]=a1,a[i].num[2]=a2,a[i].num[3]=a3;
		}
		sort(cnt+1,cnt+3+1,cmpcnt);
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i].num[a[i].sr[1]];
		}
		if(cnt[1].num<=n/2){
			cout<<sum;
		}else{
			memset(cha,0,sizeof cha);
			int more=cnt[1].num-n/2;
			int id=0;
			for(int i=1;i<=n;i++){
				if(a[i].sr[1]!=cnt[1].n) continue;
				id++;
				cha[id]=a[id].num[a[id].sr[1]]-a[id].num[a[id].sr[2]];
			}
			sort(cha+1,cha+id+1);
			int chasum=0;
			for(int i=1;i<=more;i++){
				chasum+=cha[i];
			}
			cout<<sum-chasum;
		}
		cout<<'\n';
	}
	return 0;
}
