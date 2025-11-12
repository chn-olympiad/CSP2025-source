#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int a,b,c;
};
int T,n,q[3][N],sip[3],ans;
node s[N];
/*void push(int o,int num){
	int l=1,r=sipr[o];
	if(sipl[o]=0){
		sipl[o]=1;
		sipr[o]=1;
		q[o][]
	}
}*/
bool mpa(int l,int r){
	return s[l].a-max(s[l].b,s[l].c)>s[r].a-max(s[r].b,s[r].c);
}bool mpb(int l,int r){
	return s[l].b-max(s[l].a,s[l].c)>s[r].b-max(s[r].a,s[r].c);
}bool mpc(int l,int r){
	return s[l].c-max(s[l].b,s[l].a)>s[r].c-max(s[r].a,s[r].b);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		for(int i=0;i<3;i++){
			for(int j=1;j<=n;j++){
				q[i][j]=0;
			}
			sip[i]=0;
		}
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].a>=s[i].b&&s[i].a>=s[i].c){
				sip[0]++;
				q[0][sip[0]]=i;
				ans=ans+s[i].a;
			}else if(s[i].b>=s[i].a&&s[i].b>=s[i].c){
				sip[1]++;
				q[1][sip[1]]=i;
				ans=ans+s[i].b;
			}else{
				sip[2]++;
				q[2][sip[2]]=i;
				ans=ans+s[i].c;
			}
			
		}
		sort(q[0]+1,q[0]+1+sip[0],mpa);
		sort(q[1]+1,q[1]+1+sip[1],mpb);
		sort(q[2]+1,q[2]+1+sip[2],mpc);
		for(int j=n/2+1;j<=sip[0];j++){
			ans=ans-s[q[0][j]].a+max(s[q[0][j]].b,s[q[0][j]].c);
		}
		for(int j=n/2+1;j<=sip[1];j++){
			ans=ans-s[q[1][j]].b+max(s[q[1][j]].a,s[q[1][j]].c);
		}
		for(int j=n/2+1;j<=sip[2];j++){
			ans=ans-s[q[2][j]].c+max(s[q[2][j]].a,s[q[2][j]].b);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
