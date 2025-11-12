#include<bits/stdc++.h>
using namespace std;
int a[100005][4],n,t[4],b[100005];
long long cnt;
void bc(int x){
	vector<int>c;
	for(int i=1;i<=n;++i){
		if(b[i]==x){
			if(x==1){
				c.push_back(a[i][1]-max(a[i][2],a[i][3]));
			}else if(x==2){
				c.push_back(a[i][2]-max(a[i][1],a[i][3]));
			}else if(x==3){
				c.push_back(a[i][3]-max(a[i][2],a[i][1]));
			}
		}
	}
	sort(c.begin(),c.end());
	for(int i=0;i<(t[x]-n/2);++i){
		cnt=cnt-1ll*c[i];
	}
}
void slove(){
	cnt=0;
	cin>>n;
	t[1]=t[2]=t[3]=0;
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		if(a[i][1]>=max(a[i][2],a[i][3])){
			cnt=cnt+1ll*a[i][1];
			++t[1];
			b[i]=1;
		}else if(a[i][2]>=max(a[i][1],a[i][3])){
			cnt=cnt+1ll*a[i][2];
			++t[2];
			b[i]=2;
		}else{
			cnt=cnt+1ll*a[i][3];
			++t[3];
			b[i]=3;
		}
	}
	if(t[1]>n/2){
		bc(1);
	}else if(t[2]>n/2){
		bc(2);
	}else if(t[3]>n/2){
		bc(3);
	}
	cout<<cnt<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _;
	cin>>_;
	while(_--){
		slove();
	}
	return 0;
}

