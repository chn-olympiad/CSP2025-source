#include<bits/stdc++.h>
using namespace std;
int const N=1e5+10;
//struct node{
//	int x,y,z;
//	int maxx;	 
//}s1[N],s2[N],s3[N];
//bool cmp1(node a,node b){
//	return a.x>b.x;
//}//按第一组排序 
//bool cmp2(node a,node b){
//	return a.y>b.y;
//}//按第二组排序 
//bool cmp3(node a,node b){
//	return a.z>b.z;
//}//按第三组排序 
//void makebig(node &a){
//	a.maxx=max(a.x,a.y);
//	a.maxx=max(a.z,a.maxx);
//return;
//}
//void solveit(){
//	for(int i=0;i<N;i++) s1[i]=s2[i]=s3[i]={0,0,0};
//	int n; cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>s1[i].x>>s1[i].y>>s1[i].z;
//		s2[i]=s1[i];
//		s3[i]=s1[i];
//	} 
//	for(int i=1;i<=n;i++){
//		makebig(s1[i]);
//		makebig(s2[i]);
//		makebig(s3[i]);
//	}
//	sort(s1+1,s1+1+n,cmp1);
//	sort(s2+1,s2+1+n,cmp2);
//	sort(s3+1,s3+1+n,cmp3);
//	int sum1=0,sum2=0,sum3=0,num1=0,num2=0,num3=0;
//	//sumi表示第i个社团收获的喜悦值 
//	for(int i=1;i<=n;i++){
//		if(s1[i].x==s1[i].maxx) num1++,sum1+=s1[i].x;
//	}
//	return;
//}
//int doit(int x,int wh){
//	if(num[wh]>=n/2) return 0;
//	return s[x][wh];
//}//x给第wh个组 
//void dfs(int x,int ans){
//	if(x==n) {
//		int u=max(doit(x,1),doit(x,2));
//		sum=max(sum,ans+max(u,doit(x,3)));
//		return;
//	}
//	for(int i=1;i<=3;i++){
//		if(num[i]<n/2){
//			num[i]++;
//			dfs(x+1,ans+s[x][i]);
//			num[i]--;
//		} 
//	}
//	return;
//}
int s[N][4];
int dp[510][260][260];
int num[4];
int sum=0,n;
int cnm[N];
bool cmpxx(int a,int b){
	return a>b;
}
void doa(){
	memset(cnm,0,sizeof(cnm));
	for(int i=1;i<=n;i++){
		cnm[i]=s[i][1];
	}
	sort(cnm+1,cnm+1+n,cmpxx);
	int aaa=0;
	for(int i=1;i<=n>>1;i++) aaa+=cnm[i];
	cout<<aaa<<endl;
return;
}
void solveit(){
	memset(s,0,sizeof(s));
	memset(num,0,sizeof(num));
	memset(dp,0,sizeof(dp));
	n=sum=0;
	cin>>n;
	bool flaga=true;
	bool flagb=true;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2]>>s[i][3];
		if((s[i][2]!=0)||(s[i][3]!=0)) flaga=false;
		if(s[i][3]!=0) flagb=false;
	}
	if(flaga) { doa(); return;} 
	//else if(flagb){ dob(); return; }
	for(int i=1;i<=n;i++){
		dp[i][i][0]=dp[i-1][i-1][0]+s[i][1];
		dp[i][0][i]=dp[i-1][0][i-1]+s[i][2];
		dp[i][0][0]=dp[i-1][0][0]+s[i][3];
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=min(n>>1,i);j++){
			for(int k=1;k<=min(n>>1,i-j);k++){
				int x=max(dp[i-1][j-1][k]+s[i][1],dp[i-1][j][k-1]+s[i][2]);
				dp[i][j][k]=max(x,dp[i-1][j][k]+s[i][3]);
			}
		}
	}
	cout<<dp[n][n>>1][n>>1]<<endl;
return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T; cin>>T;
	while(T--){ solveit(); }
	fclose(stdin);
	fclose(stdout);
	return 0;
}

