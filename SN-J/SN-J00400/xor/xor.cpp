//Code Originally Designed by Zhang Aoyi, SN-J00400, Shaanxi NOI CSP-J/S 2025
//Lang: C++, Examination Time: 08:30~12:00
//School: Xi'an Aerospace City No.1 (Junior) High School
//Examination Place: NPU Chang'an Campus
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
using namespace std;
//priority_queue<int>q;
//priority_queue<int,vector<int>,greater<int> >qq;
int n,a[500086],k;
int dp[500086];
bool spA=1,spB=1,spC=1;
//struct xst{
//	int l,r,v;
//};
//xst XST[4*500086];
//int id=0;
//void buildXST(int l,int r){
//	int temp;
//	for(int i=l;i<=r;i++){
//		if(i==l) temp=a[i];
//		else temp=temp^a[i];
//	}
//	XST[id].l=l;
//	XST[id].r=r;
//	XST[id].v=temp;
//	if(l==r) return; 
//	int mid=(l+r)/2;
//	id++; buildXST(l,mid);
//	id++; buildXST(mid+1,r);
//}
//int queryXST(int ql,int qr,int l,int r,int xb){
//	if(XST[xb].l>=ql&&XST[xb].r<=qr) return XST[xb].v; 
//	int mid=(XST[xb].l+XST[xb].r)/2;
//	return queryXST(ql,qr,l,mid,xb+1)^queryXST(ql,qr,mid+1,r,xb+(r-(mid+1)+1)*(int)log2(r-l+1));
//}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) spA=0;
		if(a[i]>1) spB=0;
		if(a[i]>255) spC=0;
	}
//	for(int i=1;i<=n;i++){
//		for(int j=i;j<=n;j++){
//			int ans=a[i];
//			for(int l=i+1;l<=j;l++){
//				ans=ans^a[l];
//			}
//			cout<<"xor["<<i<<","<<j<<"]="<<ans<<"\n";
//		}
//	}
	dp[0]=0;
	//buildXST(1,n);
//	for(int i=1;i<=n*4;i++){
//		cout<<XST[i].l<<" "<<XST[i].r<<" "<<XST[i].v<<"\n";
//	}
	for(int i=1;i<=n;i++){
		int seqXor;
		dp[i]=max(dp[i],dp[i-1]);
		for(int j=i;j>=1;j--){
//			int mid=(i+j)/2;
//			seqXor=queryXST(i,mid,i,mid,1)^queryXST(mid+1,j,mid+1,j,1+(j-(mid+1)+1)*(int)log2(j-i+1));
			if(j==i) seqXor=a[j];
			else seqXor^=a[j];
			if(seqXor==k){
				dp[i]=max(max(dp[i],dp[i-1]),dp[j-1]+1);
				//cout<<i<<" "<<j<<": "<<seqXor<<"\n";
				//cout<<"dp "<<i<<" = "<<dp[i]<<"\n";
			}
			
		}
	}
	cout<<dp[n];
	return 0;
}

