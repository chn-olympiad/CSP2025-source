#include <bits/stdc++.h>
using namespace std;
long long t,a[100100][5],a1cnt,a3cnt,a2cnt,n,mxn,mxm,ans,sec;
struct abc{
	long long m;
	long long c;
}abc1[100100],abc2[100100],abc3[100100];
bool cmp(abc ax,abc bx){
	return ax.c<bx.c;
}
int mx3(long long ax,long long bx,long long cx){
	if(ax>bx){
		if(ax>cx)return 1;
		else{
			if(bx>cx)return 2;
			else return 3;
		}
	}
	else{
		if(bx>cx)return 2;
		else {
			if(ax>cx)return 1;
			else return 3;
		    }
	    }
}
long long sec3(long long ax,long long bx,long long cx){
	if(ax>bx){
		if(bx>cx)return bx;
		else{
			if(ax>cx)return cx;
			else return ax;
		}
	}
	else{
		if(ax>cx)return ax;
		else {
			if(bx>cx)return cx;
			else return bx;
		    }
	    }
}
int main(){
	//ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in ","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(abc1,0,sizeof(abc1));
		memset(abc2,0,sizeof(abc2));
		memset(abc3,0,sizeof(abc3));
		memset(a,0,sizeof(a));
		a1cnt = 0;
		a2cnt = 0;
		a3cnt = 0;
		ans = 0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1];
			cin>>a[i][2];
			cin>>a[i][3];
			mxn = mx3(a[i][1],a[i][2],a[i][3]);
			mxm = max(a[i][1],max(a[i][2],a[i][3]));
			sec = sec3(a[i][1],a[i][2],a[i][3]);
			ans += mxm;
			//cout<<sec;
			//cout<<mxm<<" "<<mxn<<endl;//
			if(mxn == 1){
				abc1[++a1cnt].m = mxm;
				abc1[a1cnt].c = abc1[a1cnt].m-sec;
			}
			else if(mxn ==2){
				abc2[++a2cnt].m = mxm;
				abc2[a2cnt].c = abc2[a2cnt].m-sec;
				//cout<<mxm<<endl;//
			}
			else if(mxn == 3){
				abc3[++a3cnt].m = mxm;
				abc3[a3cnt].c = abc3[a3cnt].m-sec;
			}
		}
		//cout<<a1cnt<<endl<<a2cnt<<endl<<a3cnt<<endl;//
		if(a1cnt > n/2){
			//cout<<114514;
			int d = a1cnt-n/2;
			sort(abc1+1,abc1+a1cnt+1,cmp);
			for(int i=1;i<=d;i++){
				ans -= abc1[i].c; 
				//cout<<abc1[i].c<<endl;//
			}
		}else if(a2cnt > n/2){
			int d = a2cnt-n/2;
			sort(abc2+1,abc2+a2cnt+1,cmp);
			for(int i=1;i<=d;i++){
				ans -= abc2[i].c; 
				//cout<<abc2[i].c;
			}
		}else if(a3cnt > n/2){
			int d = a3cnt-n/2;
			sort(abc3+1,abc3+a3cnt+1,cmp);
			for(int i=1;i<=d;i++)ans -= abc3[i].c; 
		}
		cout<<ans<<'\n';
	}

	
	return 0;
}
