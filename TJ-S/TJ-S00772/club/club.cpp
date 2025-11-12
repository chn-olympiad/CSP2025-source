#include<bits/stdc++.h>
using namespace std;
//°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡£¡ 
struct amaxxx{
	int a;
	int b;
}amaxx[10001];
struct bmaxxx{
	int a;
	int b;
}bmaxx[10001];
struct cmaxxx{
	int a;
	int b;
}cmaxx[10001];
struct xx{
	int a;
	int b;
}x[10001];
struct bxx{
	int a;
	int b;
}bx[10001];
int asum[10001],anum[10001],bsum[10001],bnum[10001],csum[10001],cnum[10001];
bool sa[10001];
int aama[10001],bbma[10001],ccma[10001];
int asa[10001],bsa[10001],csa[10001];
int apre[10001],bpre[10001],cpre[10001];
void solve1(int p,int n){
	sort(aama+1,aama+n+1);
	long long ans=0;
	for(int i=p;i>=1;i--){
		ans+=aama[i];
	}
	cout<<ans;
}
bool cmp5(xx nn,xx mm){
	return nn.a>mm.a;
}
bool cmp4(bxx nn,bxx mm){
	return nn.a>mm.a;
}
bool isi[10001];
void solve2(int p,int n){
	sort(x+1,x+n+1,cmp5);
	sort(bx+1,bx+n+1,cmp4);
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(x[i].a>=bx[i].a&&isi[i]==0) {
			ans+=x[i].a;
			isi[x[i].b]=0;
		}
		else {
			ans+=bx[i].a;
			isi[bx[i].b]=0;
		}
	}
	cout<<ans;
}

/*
struct nnnum{
	int asum;
	int anum;
	//int acnt;
	int bsum;
	int bnum;
	//int bcnt;
	int csum;
	int cnum;
	//int ccnt;
}na[10001];
*/
bool cmp1(amaxxx nn,amaxxx mm){
	return nn.a>mm.a;
}
bool cmp2(bmaxxx nn,bmaxxx mm){
	return nn.a>mm.a;
}
bool cmp3(cmaxxx nn,cmaxxx mm){
	return nn.a>mm.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int jl=0,jr=0;
	while(t--){
		
		int n;
		long long aans=0,bans=0,cans=0;
		long long aanss=0,banss=0,canss=0;
		long long ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) sa[i]=0;
		int ama=0,bma=0,cma=0;
		for(int i=1;i<=n;i++){
			int ma,mb,mc;
			cin>>ma>>mb>>mc;
			amaxx[i].a=ma;
			amaxx[i].b=i;
			bmaxx[i].a=mb;
			bmaxx[i].b=i;
			cmaxx[i].a=mc;
			cmaxx[i].b=i;
			x[i].a=ma;
			x[i].b=i;
			bx[i].a=mb;
			bx[i].b=i;
			/*
			if(ma>=mb&&ma>=mc){//ÅÐ¶Ï×î´óÖµ 
				anum[i]=ma;
				asum[i]=1;
			} 
			else if(mb>=ma&&mb>=mc){//ÅÐ¶Ï×î´óÖµ 
				anum[i]=mb;
				asum[i]=2;
			} 
			else if(mc>=mb&&mc>=ma){//ÅÐ¶Ï×î´óÖµ 
				anum[i]=mc;
				asum[i]=3;
			} 
			if(anum[i]>=ma&&(ma>=mb||ma>=mc)&&asum[i]!=1){
				bnum[i]=ma;
				bsum[i]=1;
			}
			else if(anum[i]>=mb&&(mb>=ma||mb>=mc)&&asum[i]!=2){
				bnum[i]=mb;
				bsum[i]=2;
			}
			else if(anum[i]>=mc&&(mc>=ma||mc>=mb)&&asum[i]!=3){
				bnum[i]=mc;
				bsum[i]=3;
			}
			if(asum[i]!=1&&asum[i]!=2&&bsum[i]!=1&&bsum[i]!=2){
				cnum[i]=mc;
				csum[i]=3;
			}
			if(asum[i]!=2&&asum[i]!=3&&bsum[i]!=2&&bsum[i]!=3){
				cnum[i]=ma;
				csum[i]=1;
			}
			if(asum[i]!=1&&asum[i]!=3&&bsum[i]!=1&&bsum[i]!=3){
				cnum[i]=mb;
				csum[i]=2;
			}
			*/
			aama[i]=ma;
			bbma[i]=mb;
			ccma[i]=mc;
			if(bbma[i]==0&&bbma[i-1]==0&&ccma[i]==0&&ccma[i-1]==0){
				jl=1;
			}
			if(ccma[i]==0&&ccma[i-1]==0){
				jr=1;
			}
			/*
			if(ama<m[i].a) ama=m[i].a;
			if(bma<m[i].b) bma=m[i].b;
			if(bma<m[i].c) cma=m[i].c;
			*/
		}
		if(jl==1){
			solve1(n/2,n);
			return 0;
		}
		if(jr==1){
			solve2(n/2,n);
			return 0;
		}
		//sort(m+1,m+n+1,cmp);
		sort(amaxx+1,amaxx+n+1,cmp1);
		sort(bmaxx+1,bmaxx+n+1,cmp2);
		sort(cmaxx+1,cmaxx+n+1,cmp3);
		int p=n/2;
		
		// ÎÊÌâÔÚÕâ 
		//int an=0,bn=0,cn=0;
		for(int i=1;i<=p;i++){
			aanss+=amaxx[i].a;
			asa[i]=amaxx[i].b;
			banss+=bmaxx[i].a;
			bsa[i]=bmaxx[i].b;
			canss+=cmaxx[i].a;
			csa[i]=cmaxx[i].b;
		}
		
		for(int i=1;i<=n;i++){
			apre[i]=amaxx[i].a+apre[i-1];
			bpre[i]=bmaxx[i].a+bpre[i-1];
			cpre[i]=cmaxx[i].a+cpre[i-1];
		}
		
		int q;
		//if(aanss>=banss&&aanss>=canss){
			for(int i=1;i<=n-p;i++){
				long long ke=apre[i+p-1]-apre[i-1];
				for(int j=1;j<=n;j++) sa[i]=0;
				for(int j=i;j<=i+p-1;j++){
					sa[amaxx[j].b]=1;
				}
				/* 
				for(int j=1;j<=n;j++){
					for(int k=i;k<=i+p-1;k++){
						if(k==1){
							ke-=aama[j];
						}
						if(k==2){
							ke-=bbma[j];
						}
						if(k==3){
							ke-=ccma[j];
						}
					}
				}
				*/ 
				for(int j=1;j<=n;j++){
					if(sa[j]==0){
						if(asum[i]!=1) ke+=anum[i];
						else ke+=bnum[i];
					}
				}
				ans=max(ans,ke);
			}
		//}
		/*else if(banss>=aanss&&banss>=canss){
			for(int i=1;i<=n-p;i++){
				long long ke=bpre[i+p-1]-bpre[i-1];
				for(int j=1;j<=n;j++) sa[i]=0;
				for(int j=i;j<=i+p-1;j++){
					sa[bmaxx[j].b]=1;
				}
				for(int j=1;j<=n;j++){
					if(!sa[j]){
						if(asum[i]!=2) ke+=anum[i];
						else ke+=bnum[i];
					}
				}
				ans=max(ans,ke);
			}
		}*/
		/*else if(canss>=banss&&canss>=aanss){
			for(int i=1;i<=n-p;i++){
				long long ke=cpre[i+p-1]-cpre[i-1];
				for(int j=1;j<=n;j++) sa[i]=0;
				for(int j=i;j<=i+p-1;j++){
					sa[cmaxx[j].b]=1;
				}
				for(int j=1;j<=n;j++){
					if(!sa[j]){
						if(asum[i]!=3) ke+=anum[i];
						else ke+=bnum[i];
					}
				}
				ans=max(ans,ke);
			}
		//}
		*/
		/*
		for(int i=1;i<=n;i++){
			if(!sa[i]){
				if(asum[i]==q){
					ans+=bnum[i];
				}
				else{
					ans+=anum[i];
				}
			}
		}
		*/ 
		/*
		for(int i=1;i<=n-p;i++){
			long long ke=apre[i+p-1]-apre[i-1];
			 
		}
		*/
		cout<<ans<<endl;
	}
	return 0;
} 
