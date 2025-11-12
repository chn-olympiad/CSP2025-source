#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,n,m,maxn=INT_MIN;
int aa[100005][5];
void dfs(int aaa,int x,int y,int z,int xx,int yy,int zz){
	if(max(xx,max(yy,zz))>b/2)return;
	if(aaa==b){
		if(max(aa[aaa][1],max(aa[aaa][2],aa[aaa][3]))+x+y+z<maxn){
			return;
		}
	}
	if(aaa==b-1){
		if(max(aa[aaa][1],max(aa[aaa][2],aa[aaa][3]))+max(aa[aaa+1][1],max(aa[aaa+1][2],aa[aaa+1][3]))+x+y+z<maxn){
			return;
		}
	}
	if(aaa==b-2){
		if(max(aa[aaa][1],max(aa[aaa][2],aa[aaa][3]))+max(aa[aaa+1][1],max(aa[aaa+1][2],aa[aaa+1][3]))+max(aa[aaa+2][1],max(aa[aaa+2][2],aa[aaa+2][3]))+x+y+z<maxn){
			return;
		}
	}
	if(aaa==b-3){
		if(max(aa[aaa][1],max(aa[aaa][2],aa[aaa][3]))+max(aa[aaa+1][1],max(aa[aaa+1][2],aa[aaa+1][3]))+max(aa[aaa+2][1],max(aa[aaa+2][2],aa[aaa+2][3]))+max(aa[aaa+3][1],max(aa[aaa+3][2],aa[aaa+3][3]))+x+y+z<maxn){
			return;
		}
	}
	if(aaa==b-4){
		if(max(aa[aaa][1],max(aa[aaa][2],aa[aaa][3]))+max(aa[aaa+1][1],max(aa[aaa+1][2],aa[aaa+1][3]))+max(aa[aaa+2][1],max(aa[aaa+2][2],aa[aaa+2][3]))+max(aa[aaa+3][1],max(aa[aaa+3][2],aa[aaa+3][3]))+max(aa[aaa+4][1],max(aa[aaa+4][2],aa[aaa+4][3]))+x+y+z<maxn){
			return;
		}
	}
	if(aaa==b-5){
		if(max(aa[aaa][1],max(aa[aaa][2],aa[aaa][3]))+max(aa[aaa+1][1],max(aa[aaa+1][2],aa[aaa+1][3]))+max(aa[aaa+2][1],max(aa[aaa+2][2],aa[aaa+2][3]))+max(aa[aaa+3][1],max(aa[aaa+3][2],aa[aaa+3][3]))+max(aa[aaa+4][1],max(aa[aaa+4][2],aa[aaa+4][3]))+max(aa[aaa+5][1],max(aa[aaa+5][2],aa[aaa+5][3]))+x+y+z<maxn){
			return;
		}
	}
	
	//int maxxyz=max(xx,max(yy,zz));
	if(aaa>b){
		//cout<<x<<" "<<y<<" "<<z<<" "<<x+y+z<<" "<<maxn<<" "<<xx<<" "<<yy<<" "<<zz<<" "<<max(xx,max(yy,zz))<<" "<<b/2<<" "<<(max(xx,max(yy,zz))<=b/2)<<endl;
		if(aaa>b&&max(xx,max(yy,zz))<=b/2){
			maxn=max(maxn,x+y+z);
			//	cout<<x<<" "<<y<<" "<<z<<" "<<x+y+z<<" "<<maxn<<" "<<xx<<" "<<yy<<" "<<zz<<" "<<max(xx,max(yy,zz))<<" "<<b/2<<" "<<(max(xx,max(yy,zz))<=b/2)<<endl;
			
		}
		return;
	}
	dfs(aaa+1,x+aa[aaa][1],y,z,xx+1,yy,zz);
	dfs(aaa+1,x,y+aa[aaa][2],z,xx,yy+1,zz);
	dfs(aaa+1,x,y,z+aa[aaa][3],xx,yy,zz+1);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>a;
	for(int ii=1;ii<=a;ii++){
		maxn=INT_MIN;
		cin>>b;
		for(int i=1;i<=b;i++){
			for(int j=1;j<=3;j++){
				cin>>aa[i][j];
			}
			
		}
		dfs(1,0,0,0,0,0,0);
		cout<<maxn<<endl;
	}
	
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
//5
//10
//2020 14533 18961
//2423 15344 16322
//1910 6224 16178
//2038 9963 19722
//8375 10557 5444
//3518 14615 17976
//6188 13424 16615
//8769 509 4394
//958 3195 9953
//16441 5313 10926
//10
//5491 4476 6362
//9805 9130 15480
//9090 9901 10480
//6326 6516 1985
//9119 2924 6420
//9826 12689 7592
//7293 16544 12901
//11905 18183 18712
//9015 3463 13025
//1792 2433 17042
//10
//3004 4255 17336
//11894 5756 17092
//8150 14715 10991
//5149 16652 16780
//11524 11996 5433
//7690 10472 19935
//1184 6516 9246
//3231 5570 10010
//8426 16992 4654
//18955 13977 16657
//10
//6839 5455 15586
//11767 12919 2643
//13775 8904 19938
//13717 11997 15170
//13707 2404 17497
//3471 2462 8073
//18467 14346 18663
//13582 4839 15785
//11875 7476 12308
//8568 3134 18522
//10
//14230 3941 18854
//12173 19429 15426
//10974 4717 15290
//4732 6608 4961
//13198 13925 2137
//10688 3092 16965
//5356 19920 1471
//11299 10796 13511
//17932 12143 16407
//5611 8100 16107

