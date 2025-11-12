#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX=1e5+10;
ll in[MAX][3];
ll re;

ll d[MAX];

int n,choose[MAX],cnt[3];

void print(int num){
	for(int i=0;i<num;i++){
		printf("%d %3lld\n",i,d[i]);
	}
}

void init(){
	memset(cnt,0,sizeof(cnt));re=0;
	memset(d,0,sizeof(d));
	scanf("%d",&n);//cout<<"g"<<endl;
	for(int i=0;i<n;i++){
		scanf("%lld%lld%lld",&in[i][0],&in[i][1],&in[i][2]);
	}
	//print(n);
}

void solve(){
	for(int i=0;i<n;i++){
		if(in[i][0]>=in[i][1] && in[i][0]>=in[i][2]) choose[i]=0;
		else if(in[i][1]>=in[i][0] && in[i][1]>=in[i][2]) choose[i]=1;
		else choose[i]=2;
		cnt[choose[i]]++;
		re+=in[i][choose[i]];
	}
	if(cnt[0]>(n/2)){
		int k=0;
		//cout<<endl<<endl<<"0"<<endl<<endl;
		for(int i=0;i<n;i++){
			if(choose[i]==0){
				d[k++]=min(in[i][0]-in[i][1],in[i][0]-in[i][2]);
			}
		}
		sort(d,d+k);
		//print(k);
		for(int i=0;i<cnt[0]-n/2;i++){
			re-=d[i];
		}
		printf("%lld\n",re);
	}else if(cnt[1]>(n/2)){
		//cout<<endl<<endl<<"1"<<endl<<endl;
		int k=0;
		for(int i=0;i<n;i++){
			if(choose[i]==1){
				d[k++]=min(in[i][1]-in[i][0],in[i][1]-in[i][2]);
			}
		}
		sort(d,d+k);
		//print(k);
		for(int i=0;i<cnt[1]-n/2;i++){
			re-=d[i];
		}
		printf("%lld\n",re);
	}else if(cnt[2]>(n/2)){//not change
		//cout<<endl<<endl<<"2"<<endl<<endl;
		int k=0;
		for(int i=0;i<n;i++){
			if(choose[i]==2){
				d[k++]=min(in[i][2]-in[i][0],in[i][2]-in[i][1]);
			}
		}
		sort(d,d+k);
		//print(k);
		for(int i=0;i<cnt[2]-n/2;i++){
			re-=d[i];
		}
		printf("%lld\n",re);
	}else{
		printf("%lld\n",re);
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		init();
		solve();
	}
}