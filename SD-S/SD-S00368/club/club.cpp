#include<bits/stdc++.h>
using namespace std;
#define LL long long


//t1暴力25分左右 

LL n,t;
struct A{
	LL data,idx,wh;	//idx第几个组,wh第几个人; 
}al[350006];

//LL al[350006];
LL a[100006],b[100006],c[100006];
LL sa[100006],sb[100006],sc[100006];
//LL used[100006];
LL maxx;

void tian(LL a,LL b,LL c,LL id){
	al[1*id].data=a;
	al[1*id].wh=id;
	al[1*id].idx=1;	
	al[1*id].data=b;
	al[1*id].wh=id;
	al[1*id].idx=2;
	al[3*id].data=c;		
	al[3*id].wh=id;
	al[3*id].idx=3;
}

bool cmp(LL a,LL b){
	return a>b;
}

bool cmp1(A a,A b){
	return a.data>b.data;
}

//不知道咋改的错误思路 
//
//void fd(LL i,LL ans,LL acnt,LL bcnt,LL ccnt){
//	if(acnt+bcnt+ccnt==n || i>=n*3){
//		maxx=max(ans,maxx);
//		return;
//	}
//	if(al[i].idx==1){
//		if(used[al[i].wh]==0 || acnt+1<=n/2){
//			used[al[i].wh]=1;
//			fd(i+1,ans+al[i].data,acnt+1,bcnt,ccnt);
//			used[al[i].wh]=0;
//		}
//	}
//	if(al[i].idx==2){
//		if(used[al[i].wh]==0 || bcnt+1<=n/2){
//			used[al[i].wh]=1;
//			fd(i+1,ans+al[i].data,acnt,bcnt+1,ccnt);
//			used[al[i].wh]=0;
//		}
//	}
//	if(al[i].idx==3){
//		if(used[al[i].wh]==0 || ccnt+1<=n/2){
//			used[al[i].wh]=1;
//			fd(i+1,ans+al[i].data,acnt,bcnt,ccnt+1);
//			used[al[i].wh]=0;
//		}
//	}
//
//
//	fd(i+1,ans,acnt,bcnt,ccnt);
//}

//前四个测试点 
void find(LL i,LL ans,LL acnt,LL bcnt,LL ccnt){
	if(i==n+1){
		maxx=max(maxx,ans);
		return;
	}
	if(acnt+1<=n/2){
		find(i+1,ans+a[i],acnt+1,bcnt,ccnt);
	}
	if(bcnt+1<=n/2){
		find(i+1,ans+b[i],acnt,bcnt+1,ccnt);
	}
	if(ccnt+1<=n/2){
		find(i+1,ans+c[i],acnt,bcnt,ccnt+1);
	}
}
//struct M{
//	LL fr,se,th,fri,sei,thi;
//	LL idx;
//}q[100006];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>t;
	while(t--){
		//清空数组 
		memset(a,sizeof(a),0);
		memset(b,sizeof(b),0);
		memset(c,sizeof(c),0);
		//memset(used,sizeof(used),0);
		maxx=0;
//		for(int i=1;i<=n;i++){
//			q[i].idx=[i].fr=q[i].fri=q[i].se=q[i].sei=q[i].th=q[i].thi=0;	
//		}
		cin>>n;
	//	LL useda,usedb,usedc,used;
	//	useda=usedb=usedc=used=0;
		
		bool flag=1;
		bool fl=1;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
//			used+=max(a[i],max(b[i],c[i]));
//			if(a[i]>=b[i] && a[i]>=c[i]){
//				useda++;
//			}
//			if(b[i]>=a[i] && b[i]>=c[i]){
//				usedb++;
//			}
//			if(c[i]>=a[i] && c[i]>=b[i]){
//				usedc++;
//			}


//			sa[i]=sa[i-1]+a[i];
//			sb[i]=sb[i-1]+b[i];
//			sc[i]=sc[i-1]+c[i];
		//	tian(a[i],b[i],c[i],i);
			//判断特殊性质A 
			if(b[i]!=0 || c[i]!=0){
				flag=0;
			}
//			if(c[i]!=0){
//				fl=0;
//			}
		}
		//sort(al+1,al+1+n*3,cmp1);
		
		//特殊性质A 5分 
//		if(fl && !flag){
//			
//		}
//		if(!flag && useda<=n/2 && usedb<=n/2 && usedc<=n/2){
//			cout<<used<<endl;
//		}
		
		if(flag){
			sort(a+1,a+1+n,cmp);
			LL anss=0;
			for(int i=1;i<=n/2;i++){
				anss+=a[i];
			}
			cout<<anss<<endl;
		}
		else{
			//fd(1,0,0,0,0);
			find(1,0,0,0,0);
			cout<<maxx<<endl;
		}
	}
	return 0;
}
