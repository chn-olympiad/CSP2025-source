#include<bits/stdc++.h>
using namespace std;//贪心有没有分 
const int N=1e5+5;
struct club{
	int num;
	int m;
	int r;
}cl[4*N];
bool cmp(club a,club b){
	return a.m>b.m;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(cl,0,sizeof(cl));
		int cnt[4]={};
		int n,ans=0;
		cin>>n;
		int tot=1,x=1;
		for(int i=1;i<=3*n;i++){
			cin>>cl[i].m;
			cl[i].r=tot;
			if(x%4==0) x=1;
			cl[i].num=x++;
			if(i%3==0) tot++;
		}
		sort(cl+1,cl+3*n+1,cmp);
		bool v[N]={};
		for(int i=1;i<=3*n;i++){
			if(cnt[cl[i].num]<(n/2)&&v[cl[i].r]==0){
				ans+=cl[i].m;
//				cout<<cl[i].num<<" "<<cl[i].m<<" "<<cl[i].r<<"\n";
				cnt[cl[i].num]++;
				v[cl[i].r]=1;
			}
		}
		cout<<ans<<"\n";
//		for(int i=1;i<=3;i++)
//			cout<<cnt[i]<<" ";
	}
	return 0;
}