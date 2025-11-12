#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int t,n,dp[100005],x=0;
bool cmp(int a,int b){
	return a>b;
}
void ans(){
	int l=0;
	cin>>n;
	int j1[n]={0},j2[n]={0},j3[n]={0},j4[n]={0};
	for(int i=0;i<n;i++){
		cin>>j1[i]>>j2[i]>>j3[i];
		j4[i]=j1[i]-j2[i];
	}
	sort(j1,j1+n,cmp);
	sort(j2,j2+n);
	sort(j4,j4+n,cmp);
	for(int i=0;i<n;i++){
		x+=j4[i];
	}
	if(x>=0){
		for(int i=0;i<n/2;i++){
			l+=j1[i]+j2[i];	
			//cout<<j1[i]<<endl;
			//cout<<l<<endl;
		}
	cout<<l;
	}
	else if(x<0){
		sort(j2,j2+n,cmp);
		sort(j1,j1+n);
		for(int i=0;i<n/2;i++){
			l+=j1[i]+j2[i];	
			//cout<<j1[i]<<endl;
			//cout<<l<<endl;
		}
	cout<<l;
	}
	
}
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		ans();
		if(i!=t-1){
			cout<<endl;
		}
	}
	return 0;
}//Ren5Jie4Di4Ling5%
