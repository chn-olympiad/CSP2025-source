#include<bits/stdc++.h>
using namespace std;
long long t,n;
long long ans,a,b,c;
long long v1[1000005];
long long v2[1000005];
long long v3[1000005];
void dfs(long long x,long long s1,long long s2,long long s3,long long c1,long long c2,long long c3){
	if(c1>n/2) return ;
	if(c2>n/2) return ;
	if(c3>n/2) return ;
	if(x>n){
		ans=max(ans,s1+s2+s3);
		return ;
	}
	dfs(x+1,s1+v1[x],s2,s3,c1+1,c2,c3);
	dfs(x+1,s1,s2+v2[x],s3,c1,c2+1,c3);
	dfs(x+1,s1,s2,s3+v3[x],c1,c2,c3+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		memset(v1,0,sizeof(v1));
		memset(v2,0,sizeof(v2));
		memset(v3,0,sizeof(v3));
		bool f1=1,f2=1,f3=1;
		for(long long i=1;i<=n;i++){
			cin>>a>>b>>c;
			if(b||c) f1=0;
			if(a||c) f2=0;
			if(b||a) f3=0;
			v1[i]=a;
			v2[i]=b;
			v3[i]=c;
			a=max(a,b);
			a=max(a,c);
			ans+=a;
		} 
		if(f1){
			sort(v1+1,v1+n+1);
			ans=0;
			for(long long i=n;i>=n/2+1;i--){
				ans+=v1[i];
			}
		}
		else if(f2){
			sort(v2+1,v2+n+1);
			ans=0;
			for(long long i=n;i>=n/2+1;i--){
				ans+=v2[i];
			}
		}
		else if(f3){
			sort(v3+1,v3+n+1);
			ans=0;
			for(long long i=n;i>=n/2+1;i--){
				ans+=v3[i];
			}
		}
		else if(n<=25){
			ans=-1e18;
			dfs(1,0,0,0,0,0,0);
		}
		cout<<ans<<"\n";
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


5
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
10
5491 4476 6362
9805 9130 15480
9090 9901 10480
6326 6516 1985
9119 2924 6420
9826 12689 7592
7293 16544 12901
11905 18183 18712
9015 3463 13025
1792 2433 17042
10
3004 4255 17336
11894 5756 17092
8150 14715 10991
5149 16652 16780
11524 11996 5433
7690 10472 19935
1184 6516 9246
3231 5570 10010
8426 16992 4654
18955 13977 16657
10
6839 5455 15586
11767 12919 2643
13775 8904 19938
13717 11997 15170
13707 2404 17497
3471 2462 8073
18467 14346 18663
13582 4839 15785
11875 7476 12308
8568 3134 18522
10
14230 3941 18854
12173 19429 15426
10974 4717 15290
4732 6608 4961
13198 13925 2137
10688 3092 16965
5356 19920 1471
11299 10796 13511
17932 12143 16407
5611 8100 16107





*/
