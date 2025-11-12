#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int n,cnta,cntb,cntc,qa,qb,qc,flg;
long long maxn,toa;
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		toa=0; 
		maxn=0;
		flg=0;
		cin>>n;
		vector<int>a(n+1);
		vector<int>b(n+1);
		vector<int>c(n+1);
		int x[n+1][4];
		int y[n+1][4];
		int z[n+1][4];	
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i] != c[i] || b[i] != 0){
				flg=1;
			}
			if(a[i] > b[i] && a[i]>b[i]){
				cnta++;
				x[cnta][1]=a[i];
				x[cnta][2]=b[i];
				x[cnta][3]=c[i];
				maxn+=a[i];
			}
			else if(b[i] > a[i] && b[i]>a[i]){
				cntb++;
				maxn+=b[i];
			}		
			if(c[i] > a[i] && c[i]>b[i]){
				cntc++;
				maxn+=c[i];
			}
			if(a[i]>=b[i] &&a[i]>=c[i] && qa < n/2){
				qa++;
				toa+=a[i];
			}
			else if(b[i]>=a[i] &&b[i]>=c[i] && qb < n/2){
				qb++;
				toa+=b[i]; 
			}
			else if(c[i]>=a[i] &&c[i]>=b[i] && qc < n/2){
				qc++;
				toa+=c[i]; 
			}
		}
		if(flg==0){
			sort(a.begin()+1,a.end(),cmp);
			toa=0;
			for(int i=1;i<= n/2;i++){
				toa+=a[i];
			}
			cout<<"我是特判toa:"<<toa<<endl;
			continue;
		}
		if(cnta <= n/2 && cntb <= n/2 && cntc<=n/2){
			cout<<"我是maxn："<<maxn<<endl;
			continue;
		}
		cout<<"我是toa:"<<toa<<endl;
	}
	return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
long long toa;
int cnta,cntb,cntc;
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		toa=0,cnta=0,cntb=0,cntc=0;
		int n;cin>>n;
		vector<int> a(n+1);
		vector<int> b(n+1);
		vector<int> c(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];	
			if(a[i]>=b[i] &&a[i]>=c[i] && qa < n/2){
				qa++;
				toa+=a[i];
			}
			else if(b[i]>=a[i] &&b[i]>=c[i] && qb < n/2){
				qb++;
				toa+=b[i]; 
			}
			else if(c[i]>=a[i] &&c[i]>=b[i] && qc < n/2){
				qc++;
				toa+=c[i]; 
			}
		}
		cout<<toa<<endl; 
	}
	return 0;
}
*/ 
