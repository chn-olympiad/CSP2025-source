#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int t,n;
struct node{
	int a,b,c;
} a[100001],ma[100001],mp[100001],mc[100001],b[100001];
int dp[2][151][151];
int cz=0;
int ac,bc,cc,lc;
int cmpo(node l,node r){
	return abs(l.a-l.b)>abs(r.a-r.b);
}
int cmp(node l,node r){
	return 2*max(l.a,max(l.b,l.c))-(l.a+l.b+l.c-max(l.a,max(l.b,l.c)))>2*max(r.a,max(r.b,r.c))-(r.a+r.b+r.c-max(r.a,max(r.b,r.c)));
	//return max(l.a,max(l.b,l.c))-min(l.a,min(l.b,l.c))>max(r.a,max(r.b,r.c))-min(r.a,min(r.b,r.c));
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int g=1;g<=t;g++){
		cin>>n;
		cz=0;
		//clear all on muti-check
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].c!=0){
				cz=1;
			}	
		}
		ac=bc=cc=lc=0;
		
		if(cz==0){
			int c=0;
			for(int i=1;i<=n;i++){
				if(a[i].a>=a[i].b){
					ac++;
					ma[ac].a=a[i].a;
					ma[ac].b=a[i].b;
				}
				else{
					bc++;
					mp[bc].a=a[i].a;
					mp[bc].b=a[i].b;
				}
			}
			sort(ma+1,ma+ac+1,cmpo);
			sort(mp+1,mp+bc+1,cmpo);
			int j=1;
			for(j=1;j<=min(ac,n/2);j++){
				c+=ma[j].a;
			}
			for(;j<=ac;j++){
				c+=ma[j].b;
			}	
			for(j=1;j<=min(bc,n/2);j++){
				c+=mp[j].b;
			}
			for(;j<=bc;j++){
				c+=mp[j].a;
			}	
			cout<<c<<endl;	
			continue;
		}
		else if(n<=300){
			int maxn=0;
			for(int i=0;i<=n/2;i++)	for(int j=0;j<=n/2;j++)	dp[0][i][j]=0;
			for(int i=0;i<=n/2;i++)	for(int j=0;j<=n/2;j++)	dp[1][i][j]=0;
			for(int i=1;i<=n;i++){
				for(int j=0;j<=n/2;j++){
					for(int k=0;k<=n/2;k++){
						if(j+k>i)	continue;
						if(n-j-k>n/2)	continue;
						if(j==0&&k==0)	dp[i&1][j][k]=max(0LL,max(0LL,dp[(i+1)&1][j][k]+a[i].c));
						else if(j==0)	dp[i&1][j][k]=max(0LL,max(dp[(i+1)&1][j][k-1]+a[i].b,dp[(i+1)&1][j][k]+a[i].c));
						else if(k==0)	dp[i&1][j][k]=max(dp[(i+1)&1][j-1][k]+a[i].a,max(0LL,dp[(i+1)&1][j][k]+a[i].c));
						else	dp[i&1][j][k]=max(dp[(i+1)&1][j-1][k]+a[i].a,max(dp[(i+1)&1][j][k-1]+a[i].b,dp[(i+1)&1][j][k]+a[i].c));
						if(i==n)	maxn=max(maxn,dp[i&1][j][k]);	
					//	cout<<dp[i&1][j][k]<<' ';
					}
				//	cout<<endl;
				}
			}
			cout<<maxn<<endl;
		}
		else{
			int c=0;
			for(int i=1;i<=n;i++){
				int maxn=max(a[i].a,max(a[i].b,a[i].c));
				if(maxn==a[i].a){
					ac++;
					ma[ac].a=a[i].a;
					ma[ac].b=a[i].b;
					ma[ac].c=a[i].c;
				}
				else if(maxn==a[i].b){
					bc++;
					mp[bc].a=a[i].a;
					mp[bc].b=a[i].b;
					mp[bc].c=a[i].c;
				}
				else{
					cc++;
					mc[cc].a=a[i].a;
					mc[cc].b=a[i].b;
					mc[cc].c=a[i].c;					
				}
			}
			sort(ma+1,ma+ac+1,cmp);
			sort(mp+1,mp+bc+1,cmp);
			sort(mc+1,mc+cc+1,cmp);
			int j=1;
			int dc=0;
			int d=0;
			int aq=0,bq=0,cq=0;
			for(j=1;j<=min(ac,n/2);j++){
				c+=ma[j].a;
				aq++;
			}	
			for(;j<=ac;j++){
				d=1;
				lc++;
				b[lc]=ma[j];
				if(j==ac)	dc++;
			}
			for(j=1;j<=min(bc,n/2);j++){
				c+=mp[j].b;
				bq++;
			}
			for(;j<=bc;j++){
				d=2;
				lc++;
				b[lc]=mp[j];
				if(j==bc)	dc++;
			}
			for(j=1;j<=min(cc,n/2);j++){
				c+=mc[j].c;
				cq++;
			}	
			for(;j<=cc;j++){
				d=3;
				lc++;
				b[lc]=mc[j];
				if(j==cc)	dc++;
			}
			if(dc==0){
				cout<<c<<endl;
				continue;
			}
			if(dc>=2){
				cout<<c<<endl;
				continue;
			}	
			if(d==1){
				for(j=1;j<=lc;j++)	swap(b[j].a,b[j].c);
				swap(aq,cq);
			}
			if(d==2){
				for(j=1;j<=lc;j++)	swap(b[j].b,b[j].c);
				swap(bq,cq);
			}
			ac=bc=cc=0;
			for(int i=1;i<=lc;i++){
				if(b[i].a>=b[i].b){
					ac++;
					ma[ac].a=b[i].a;
					ma[ac].b=b[i].b;
				}
				else{
					bc++;
					mp[bc].a=b[i].a;
					mp[bc].b=b[i].b;
				}
			}
			sort(ma+1,ma+ac+1,cmpo);
			sort(mp+1,mp+bc+1,cmpo);
			j=1;
			for(j=aq;j<=min(ac,n/2);j++){
				c+=ma[j].a;
			}
			for(;j<=ac;j++){
				c+=ma[j].b;
			}	
			for(j=bq;j<=min(bc,n/2);j++){
				c+=mp[j].b;
			}
			for(;j<=bc;j++){
				c+=mp[j].a;
			}	
			cout<<c<<endl;	
			continue;							
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
please remember to
*/
