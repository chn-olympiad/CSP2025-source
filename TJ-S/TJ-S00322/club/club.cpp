#include<bits/stdc++.h>
using namespace std;
//int a[4][100001];
const int MAXS=2e4+1;
int F1(int n){
	int ans=-1;
	int a[4][100001];
	for(int i=1;i<=n;i++){
		cin>>a[1][i]>>a[2][i]>>a[3][i];
	}
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(i==j){
				continue;
			}
			if(a[i][1]+a[j][2]>ans){
				ans=a[i][1]+a[j][2];
			}
		}
	}
	return ans;
}
int A(int n,int st1[]){
	int m=n/2;
	int ans=0;
//	int T1[n+2];
//	for(int i=1;i<=n;i++){
	//	int t2,t3;
	//	cin>>T1[i]>>t2>>t3
	//}
	int tong[MAXS];
	memset(tong,0,sizeof(tong));
	int zd=0;
	for(int i=1;i<=n;i++){
		tong[st1[i]]+=1;
		zd=max(zd,st1[i]);
	}
	if(tong[zd]>=m){
		ans=m*zd;
	}
	else{
		while(m){
			ans+=zd*tong[zd];
			m-=tong[zd];
			if(m<0){
				ans=ans-(0-m)*zd;
			}
			zd--;
		}
	}
	return ans;
}
int f(int n){
	int shetuan1=0,shetuan2=0,shetuan3=0;
	int ans=0;
	int st1[n+1],st2[n+1],st3[n+1];
	int t12[n+1],t23[n+1];
	int yx1[n+1],yx1_[n+1];
	int yx2[n+1],yx2_[n+1];
	//int t12_[n+1]
	for(int i=1;i<=n;i++){
		cin>>st1[i]>>st2[i]>>st3[i];
		t12[i]=max(st1[i],st2[i])-min(st1[i],st2[i]);
		t23[i]=max(st2[i],st3[i])-min(st3[i],st2[i]);
	}
	int ls2=0,ls3=0;
	for(int i=1;i<=n;i++){
		ls2+=st2[i];
		ls3+=st3[i];
	}
	if(ls2==0&&ls3==0){
		return A(n,st1);
	}
	for(int i=1;i<=n;i++){
		int ma1=-1;
		int ma1_=-1;
		int ma2=-1;
		int ma2_=-1;
		for(int j=1;j<=n;j++){
			if(ma1<t12[j]){
				ma1=t12[j];
				ma1_=j;
			}
		}
		for(int j=1;j<=n;j++){
		//	cout<<t23[2]<<endl;
			if(ma2<t23[j]){
				ma2=t23[j];
				ma2_=j;
			}
		}
		//int ma=max(ma1,ma2);
//		cout<<ma1<<" "<<ma1_<<endl<<ma2<<" "<<ma2_<<endl;
		if(ma1>ma2){
			if(st1[ma1_]>st2[ma1_]){
				shetuan1+=1;
			}
			else if(st1[ma1_]<st2[ma1_]){
				shetuan2+=1;
			}
			else{
				if(shetuan1<shetuan2){
					shetuan1++;
				}
				else{
					shetuan2++;
				}
			}
			ans+=max(st1[ma1_],st2[ma1_]);
			st1[ma1_]=0;
			st2[ma1_]=0;
			st3[ma1_]=0;
			t12[ma1_]=-1;
			t23[ma1_]=-1;
		//	shetuan1+=1;
		}
		if(ma2>ma1){
			if(st1[ma2_]>st2[ma2_]){
				shetuan1+=1;
			}
			else if(st1[ma2_]<st2[ma2_]){
				shetuan2+=1;
			}
			else{
				if(shetuan1<shetuan2){
					shetuan1++;
				}
				else{
					shetuan2++;
				}
			}
			ans+=max(st3[ma2_],st2[ma2_]);
			st1[ma2_]=0;
			st2[ma2_]=0;
			st3[ma2_]=0;
			t23[ma2_]=-1;
			t12[ma2_]=-1;
			//shetuan2+=1
		}
		if(ma1==ma2){
			if(st1[ma1_]>st2[ma1_]&&st1[ma1_]>st3[ma1_]){
				shetuan1+=1;
			}
			else if(st1[ma1_]<st2[ma1_]&&st3[ma1_]<st2[ma1_]){
				shetuan2+=1;
			}
			else if(st1[ma1_]<st3[ma1_]&&st3[ma1_]>st2[ma1_]){
				shetuan3+=1;
			}
			else{
				if(shetuan1<shetuan2&&shetuan1<shetuan3){
					shetuan1++;
				}
				else if(shetuan3>shetuan2&&shetuan3>shetuan1){
					shetuan3++;
				}
				else{
					shetuan2++;
				}
			}
			ans+=max(st3[ma2_],max(st1[ma1_],st2[ma1_]));
			//if(st3[ma2_]>)
			st1[ma2_]=0;
			st2[ma2_]=0;
			st3[ma2_]=0;
			t12[ma1_]=-1;
			t23[ma1_]=-1;
		}
		if(shetuan1==n/2){
			for(int i=1;i<=n;i++){
				t12[n]=-1;
			}
		}
		if(shetuan3==n/2){
			for(int i=1;i<=n;i++){
				t23[n]=-1;
			}
		}
	}
	/*	yx1[i]=ma;
		yx1_[i]=ma_;
		t12[ma_]=-1;
	
	for(int i=1;i<=n;i++){
		int ma=-1;
		int ma_=-1;
		
		yx2[i]=ma;
		yx2_[i]=ma_;
		t23[ma_]=-1;
	}
	for(int i=1;i<=n;i++){
		int ma=-1;
		int ma_=-1;
		bool x=0;
		for(int j=1;j<=n;j++){
			if(yx1[j]>ma){
				ma=yx1[j];
				ma_=j;
				x=0;
			}
			if(yx2[j]>ma){
				ma=yx2[j];
				ma_=j;
				x=1;
			}
		}
		if(x==0){
			ans+=
		}
	}*/
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int I=1;I<=t;I++){
		int n;
		cin>>n;
		if(n==2){
			cout<<F1(n);
			continue;
		}
		//if(m==n){
	//		cout<<A(n);
		//	continue;
	//	}
		cout<<f(n)<<endl;
	}
}
