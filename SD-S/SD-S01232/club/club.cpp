#include<bits/stdc++.h>
using namespace std;
int bn(int a,int b){
	if(a>b) return a-b;
	return b-a;
}
int maxp(int a,int b,int c){
	if(a>b&&a>c) return 1;
	if(a>b) return 3;
	if(b>c) return 2;
	return 3;
}
int minp(int a,int b,int c){
	if(a<b&&a<c) return 1;
	if(a<b) return 3;
	if(b<c) return 2;
	return 3;
}
void an(){
	int n;
	int a[5][100005];
	int m1=0,m2=0,m3=0;
	m1=m2=m3=1000000009;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[1][i]>>a[2][i]>>a[3][i];
	int ans=0;
	int k[5][100005];
	int s[5]={0,0,0,0,0};
	for(int i=1;i<=n;i++){
		int p=maxp(a[1][i],a[2][i],a[3][i]);
		int ma;
		if(p==1){ma=min(a[1][i]-a[2][i],a[1][i]-a[3][i]);m2=min(m2,ma);m3=min(m3,ma);}
		else if(p==2){ma=min(a[2][i]-a[1][i],a[2][i]-a[3][i]);m1=min(m1,ma);m3=min(m3,ma);}
		else{ma=min(a[3][i]-a[1][i],a[3][i]-a[2][i]);m2=min(m2,ma);m1=min(m1,ma);}
		ans+=a[p][i];
		if(s[p]<n/2) s[p]++;
		else if(p==1){
			ans-=min(min(ma,m2),m3);
			if(minp(ma,m2,m3)==2){m2=ma;s[3]++;}
			else if(minp(ma,m2,m3)==3){m3=ma;s[2]++;}
		}
		else if(p==2){
			ans-=min(min(ma,m1),m3);
			if(minp(ma,m1,m3)==2){m1=ma;s[3]++;}
			else if(minp(ma,m1,m3)==3){m3=ma;s[1]++;}
		}
		else{
			ans-=min(min(ma,m2),m1);
			if(minp(ma,m2,m1)==2){m2=ma;s[1]++;}
			else if(minp(ma,m2,m1)==3){m1=ma;s[2]++;}
		}
	}
	cout<<ans<<endl;
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)an();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
