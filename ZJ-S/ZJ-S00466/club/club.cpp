#include<bits/stdc++.h>
using namespace std;
//nlogn
int n;//n<=1e5
long long a[100005][5];
int cnt[5];
bool b[100005];
long long max1=-1;
void chushi(){
	for(int i=0;i<=4;i++)
		cnt[i]=0;
	for(int i=0;i<=n+5;i++)
		for(int j=0;j<=4;j++)
			a[i][j]=0;
	for(int i=0;i<=n+5;i++)
		b[i]=0;
	max1=-1;
}
void sss(int k,long long sum){
	if(k==n+1){
		if(sum>max1){
			max1=sum;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(b[i])
			continue;
		for(int j=1;j<=3;j++){
			if(cnt[j]+1>n/2)
				continue;
			cnt[j]+=1;
			b[i]=1;
			sss(k+1,sum+a[i][j]);
			cnt[j]-=1;
			b[i]=0;
		}
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		chushi();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		sss(1,0);
		cout<<max1<<endl;
	}
	
	
	
	
	return 0;
}
