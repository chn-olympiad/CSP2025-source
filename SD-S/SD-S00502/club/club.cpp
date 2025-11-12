#include<bits/stdc++.h>
using namespace std;
int T;
long long n;
struct node{
	long long a,b,c;
}x[100005];
struct node2{
	long long ch;
	int fr;
}p[100005];
bool cmp(node2 x,node2 y){
	return x.ch<y.ch;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		memset(x,0,sizeof(x));
		int cnt1=0,cnt2=0,cnt3=0;
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			long long tmp1=max(max(x[i].a,x[i].b),x[i].c);
			ans+=tmp1;
			long long tmp2;
			if(tmp1==x[i].a){
				cnt1++;
				tmp2=min(tmp1-x[i].b,tmp1-x[i].c);
				p[i].fr=1;
			}
			else if(tmp1==x[i].b){
				cnt2++;
				tmp2=min(tmp1-x[i].a,tmp1-x[i].c);
				p[i].fr=2;
			}
			else{
				cnt3++;
				tmp2=min(tmp1-x[i].b,tmp1-x[i].a);
				p[i].fr=3;
			}
			p[i].ch=tmp2;
		}
		long long mo;
		sort(p+1,p+n+1,cmp);
		if(cnt1>n/2){
			mo=cnt1-n/2;
			long long tmp=0;
			long long pos=1;
			while(tmp<mo){
				if(p[pos].fr==1){
					tmp++;
					ans-=p[pos].ch;
				}
				pos++;
			}
		}
		else if(cnt2>n/2){
			mo=cnt2-n/2;
			long long tmp=0;
			long long pos=1;
			while(tmp<mo){
				if(p[pos].fr==2){
					tmp++;
					ans-=p[pos].ch;
				}
				pos++;
			}
		}
		else if(cnt3>n/2){
			mo=cnt3-n/2;
			long long tmp=0;
			long long pos=1;
			while(tmp<mo){
				if(p[pos].fr==3){
					tmp++;
					ans-=p[pos].ch;
				}
				pos++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
