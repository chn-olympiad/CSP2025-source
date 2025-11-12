#include <bits/stdc++.h>
using namespace std;

int n,t;
int a[100006][5];
int b[100006][5];
int l[100006][5];
int cnts[4];
int id[4];
priority_queue<int> que;

void aas(void){
	memset(cnts,0,sizeof(cnts));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(l,0,sizeof(l));
	memset(id,1,sizeof(id));
	while(!que.empty()) que.pop();
}


int main(){
//	freopen("club.in","r",stdin);	
//	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		aas();
		long long ans=0;
		cin>>n;
		for(int i =1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int ma=max(a[i][1],max(a[i][2],a[i][3]));
			b[i][1]=ma;
			bool bl=0;
			for(int j=1;j<=3;j++){
				if(a[i][j]==ma&&bl==0) {
					bl=1;continue;
				}
				if(a[i][j]>b[i][2]) b[i][2]=a[i][j];
			}
			if(b[i][1]>b[i][2]){
				for(int j=1;j<=3;j++){
					if(a[i][j]==ma) {
						l[j][id[j]]=i;
						id[j]++;
						cnts[j]++;
						break;
					}
				}
			}
			else{ans+=b[i][1];}
		}
		for(int i=1;i<=3;i++){
			if(cnts[i]<n/2) {
				for(int j=1;j<=cnts[i];j++){
					ans+=b[l[i][j]][1];
				}
			}
			else{
				for(int j=1;j<=cnts[i];j++){
					b[l[i][j]][3]=b[l[i][j]][1]-b[l[i][j]][2];
					que.push(b[l[i][j]][3]);
				}
				for(int j=1;j<=n/2;j++){
					for(int ij=1;true;ij++){
						if(b[l[i][j]][3]==que.top()){
							ans+=b[l[i][j]][1];
							que.pop();
							b[l[i][j]][3]=-1;
						}
					}
				}
				for(int j=1;j<=cnts[i];j++){
					if(b[l[i][j]][3]!=-1) ans+=b[l[i][j]][1];
				}
			}
		}
		cout<<ans;
		
		
	}
	return 0;
}

