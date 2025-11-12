#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=1e5+5;
int lim,cna,cnb,cnc,j,sum,n,tn;
struct stu{
	int v,id;
}a[N],b[N],c[N];
int mar[N];
bool cmp(stu a,stu b){
	return a.v>b.v;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		sum=0;
		cin>>n;
		tn=n,lim=n/2,cna=0,cnb=0,cnc=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].v>>b[i].v>>c[i].v;
			a[i].id=i;b[i].id=i;c[i].id=i;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		sort(c+1,c+1+n,cmp);
		j=1;
		while(n){
			for(int i=1;i<=3;i++){
				if(n==0) break;
				if(i==1&&(!mar[a[j].id])&&cna<=lim){
					sum+=a[j].v;
					mar[a[j].id]=1;
					n--;cna++;
				}
				if(i==2&&(!mar[b[j].id])&&cnb<=lim){
					sum+=b[j].v;
					mar[b[j].id]=1;
					n--;cnb++;
				}
				if(i==3&&(!mar[c[j].id])&&cnc<=lim){
					sum+=c[j].v;
					mar[c[j].id]=1;
					n--;cnc++;
				}
			}
			j++;
		}
		cout<<sum<<endl;
		
		for(int i=1;i<=tn;i++){
			a[i].v=0;a[i].id=0;
			b[i].v=0;b[i].id=0;
			c[i].v=0;c[i].id=0;
			mar[i]=0;
		}
		
	}
	
	return 0;
}