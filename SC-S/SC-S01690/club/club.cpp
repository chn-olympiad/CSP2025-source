#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,t;
int arr[N][3];
int l1=0,l2=0,l3=0;
int c1[N],c2[N],c3[N];
int ans=0;
void dl1(){
	int bh=l1,minn=arr[c1[l1]][1]-max(arr[c1[l1]][2],arr[c1[l1]][3]);
	for(int i=1;i<l1;i++){
		int t0=c1[i];
		if(min(arr[t0][1]-arr[t0][2],arr[t0][1]-arr[t0][3])<=minn)
			minn=min(arr[t0][1]-arr[t0][2],min(arr[t0][1]-arr[t0][3],minn)),bh=i;
	}
	if(arr[bh][2]>=arr[bh][3]){
		ans-=arr[bh][1]-arr[bh][2];swap(c1[bh],c1[l1]);
		c1[l1]=0,c2[++l2]=bh,l1--;
	}else{
		ans-=arr[bh][1]-arr[bh][3];swap(c1[bh],c1[l1]);
		c1[l1]=0,c3[++l3]=bh,l1--;
	}
}
void dl2(){
	int bh=l2,minn=arr[c2[l2]][2]-max(arr[c2[l2]][1],arr[c2[l2]][3]);
	for(int i=1;i<l2;i++){
		int t0=c2[i];
		if(min(arr[t0][2]-arr[t0][1],arr[t0][2]-arr[t0][3])<=minn)
			minn=min(arr[t0][2]-arr[t0][1],min(arr[t0][2]-arr[t0][3],minn)),bh=i;
	}
	if(arr[bh][1]>=arr[bh][3]){
		ans-=arr[bh][2]-arr[bh][1];swap(c2[bh],c2[l2]);
		c2[l2]=0,c1[++l1]=bh,l2--;
	}else{
		ans-=arr[bh][2]-arr[bh][3];swap(c2[bh],c2[l2]);
		c2[l2]=0,c3[++l3]=bh,l2--;
	}
}
void dl3(){
	int bh=l3,minn=arr[c3[l3]][3]-max(arr[c3[l3]][1],arr[c3[l3]][2]);
	for(int i=1;i<l3;i++){
		int t0=c3[i];
		if(min(arr[t0][3]-arr[t0][1],arr[t0][3]-arr[t0][1])<=minn)
	    	minn=min(arr[t0][3]-arr[t0][1],min(arr[t0][3]-arr[t0][2],minn)),bh=i;
	}
	if(arr[bh][1]>=arr[bh][2]){
		ans-=arr[bh][3]-arr[bh][1];swap(c3[bh],c3[l3]);
		c3[l3]=0,c1[++l1]=bh,l3--;
	}else{
		ans-=arr[bh][3]-arr[bh][2];swap(c3[bh],c3[l3]);
		c3[l3]=0,c2[++l2]=bh,l3--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		l1=0,l2=0,l3=0,ans=0;
		for(int i=1;i<=n;i++)cin>>arr[i][1]>>arr[i][2]>>arr[i][3];
		for(int i=1;i<=n;i++){
			int a=arr[i][1],b=arr[i][2],c=arr[i][3];
			if(a>b&&a>c)ans+=a,l1++,c1[l1]=i;
			else if(a<b&&b>c)ans+=b,l2++,c2[l2]=i;
			else ans+=c,l3++,c3[l3]=i;
			if(l1>n/2)dl1();
			if(l2>n/2)dl2();
			if(l3>n/2)dl3();
		}
		cout<<ans<<endl;
	}
	return 0;
}