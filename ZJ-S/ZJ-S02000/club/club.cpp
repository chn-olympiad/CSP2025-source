#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,n12,n23,n13,n123,s12[100009],s13[100009],s23[100009];
struct mann{
	int num,no[5];
}a[100009],mx;
bool cmp1(mann a,mann b){
	if(a.no[1]!=b.no[1]){
		return a.no[1]>b.no[1];
	}
	if(a.no[2]!=b.no[2]){
		return a.no[2]>b.no[2];
	}
	return a.no[3]>b.no[3];
}
bool cmp2(mann a,mann b){
	if(a.no[1]!=b.no[1]){
		return a.no[1]>b.no[1];
	}
	if(a.no[3]!=b.no[3]){
		return a.no[3]>b.no[3];
	}
	return a.no[2]>b.no[2];
}
bool cmp3(mann a,mann b){
	if(a.no[2]!=b.no[2]){
		return a.no[2]>b.no[2];
	}
	if(a.no[1]!=b.no[1]){
		return a.no[1]>b.no[1];
	}
	return a.no[3]>b.no[3];
}
bool cmp4(mann a,mann b){
	if(a.no[2]!=b.no[2]){
		return a.no[2]>b.no[2];
	}
	if(a.no[3]!=b.no[3]){
		return a.no[3]>b.no[3];
	}
	return a.no[1]>b.no[1];
}
bool cmp5(mann a,mann b){
	if(a.no[3]!=b.no[3]){
		return a.no[3]>b.no[3];
	}
	if(a.no[1]!=b.no[1]){
		return a.no[1]>b.no[1];
	}
	return a.no[2]>b.no[2];
}
bool cmp6(mann a,mann b){
	if(a.no[3]!=b.no[3]){
		return a.no[3]>b.no[3];
	}
	if(a.no[2]!=b.no[2]){
		return a.no[2]>b.no[2];
	}
	return a.no[1]>b.no[1];
}
bool cmpcmp(mann a,mann b){
	return a.no[1]>b.no[1];
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int xyz=1;xyz<=T;xyz++){
		cin>>n;
		bool A=1;
		for(int i=1;i<=n;i++){
			a[i].num=i;
			cin>>a[i].no[1]>>a[i].no[2]>>a[i].no[3];
			if(a[i].no[2]||a[i].no[3]){
				A=0;
			}
			if(a[i].no[1]>mx.num){
				mx.num=a[i].no[1];
				mx.no[1]=i;
				mx.no[2]=1;
			}
			if(a[i].no[2]>mx.num){
				mx.num=a[i].no[2];
				mx.no[1]=i;
				mx.no[2]=2;
			}
			if(a[i].no[3]>mx.num){
				mx.num=a[i].no[3];
				mx.no[1]=i;
				mx.no[2]=3;
			}
		}
		if(A){
			sort(a+1,a+n+1,cmpcmp);
			int s=0;
			for(int i=1;i<=n/2;i++){
				s+=a[i].no[1];
			}
			cout<<s;
			continue;
		}
		int aa=0,b=0,c=0,s=0;
		for(int i=1;i<=n;i++){
			if(a[i].no[1]>=a[i].no[2]&&a[i].no[1]>=a[i].no[3]){
				aa++;
			}else if(a[i].no[2]>=a[i].no[1]&&a[i].no[2]>=a[i].no[3]){
				b++;
			}else{
				c++;
			}
			s+=max(a[i].no[1],max(a[i].no[2],a[i].no[3]));
		}
		if(aa<=n/2&&b<=n/2&&c<=n/2){
			cout<<s<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			if(a[i].no[1]==a[i].no[2]){
				s12[++n12]=i;
			}
			if(a[i].no[1]==a[i].no[3]){
				s13[++n13]=i;
			}
			if(a[i].no[3]==a[i].no[2]){
				s23[++n23]=i;
			}
		}
		
	}
	
	return 0;
}
//12345554344432135
//12345554344432131
//666545554344432135
//666545554344432131
//12345554344432135
//12345554344432131
