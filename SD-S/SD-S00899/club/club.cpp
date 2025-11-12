#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+10;

int T,a[MAXN][4],c[MAXN];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		int n,sum1=0,sum2=0,sum3=0,ans=0;cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int M=max(a[i][1],max(a[i][2],a[i][3]));
			if(M==a[i][1])c[i]=1,sum1++;
			else if(M==a[i][2])c[i]=2,sum2++;
			else if(M==a[i][3])c[i]=3,sum3++;
			ans+=M;
		}
		int t1=0,cc=0;
		if(sum1>n/2)t1=1,cc=sum1-n/2;
		else if(sum2>n/2)t1=2,cc=sum2-n/2;
		else if(sum3>n/2)t1=3,cc=sum3-n/2;
		if(t1==0){
			printf("%d\n",ans);
			continue;
		}
		vector<pair<int,int> > b;
		for(int i=1;i<=n;i++){
			if(c[i]==t1){
				if(t1==1){
					if(a[i][2]>a[i][3])b.push_back(make_pair(a[i][1]-a[i][2],i));
					else b.push_back(make_pair(a[i][1]-a[i][3],i));
				}else if(t1==2){
					if(a[i][1]>a[i][3])b.push_back(make_pair(a[i][2]-a[i][1],i));
					else b.push_back(make_pair(a[i][2]-a[i][3],i));
				}else if(t1==3){
					if(a[i][1]>a[i][2])b.push_back(make_pair(a[i][3]-a[i][1],i));
					else b.push_back(make_pair(a[i][3]-a[i][2],i));
				} 
			}
		}
		sort(b.begin(),b.end());
		for(int i=0;i<cc;i++){
			ans-=b[i].first;
		}
		printf("%d\n",ans);
	}
	return 0;
}

/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
