#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,ans;
const int N=1e5+5;
struct node{
	int d,m,b;
}a[3*N];
int v[N],b1[5],bb[5];
bool cmp(node x,node y){
	return x.m<y.m;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
cin>>t;
while(t--){
	int n;
	cin>>n;
	bool bo=0,bo1=0;
	for(int i=1;i<=3*n;i+=3){
		cin>>a[i].m>>a[i+1].m>>a[i+2].m;
		int js=0;
		if(a[i].m==0)js++;
		if(a[i+1].m==0)js++;
		if(a[i+2].m==0)js++;
		if(js!=2)bo=1;
		if(js=1)bo1=1; 
		a[i].d=a[i+1].d=a[i+2].d=i;
		a[i].b=1;
		a[i+1].b=2;
		a[i+2].b=3;
	}
	sort(a+1,a+3*n+1,cmp);
	int ans=0;
	for(int i=3*n;i>=1;i--){
//		cout<<a[i].m<<' ';
		if(!v[a[i].d]){
//			cout<<'\n'<<a[i].m<<'\n';
			if(b1[a[i].b]+1==n/2){
				
				int aans=0;
				int ii=i-1;
				while(a[ii].d==a[i].d){
					ii--;
				} 
				if(ii!=i-1&&a[ii].b==a[i].b){
					if(a[i-1].m+a[ii].m>a[i].m){
						b1[a[ii].b]++;
						b1[a[i-1].b]++;
						v[a[ii].d]=1;
						ans+=a[i-1].m+a[ii].m;v[a[i].d]=1;
//						cout<<"%"<<a[i-1].m+a[ii].m<<'\n';
						continue;	
					}
				}
				b1[a[i].b]++;
				ans+=a[i].m;v[a[i].d]=1;
//				cout<<"#"<<a[i].m<<'\n';
					
			}
			else if(b1[a[i].b]+1>n/2)continue;
			else{
				b1[a[i].b]++;
				ans+=a[i].m;v[a[i].d]=1;
//				cout<<"#"<<a[i].m<<'\n';
			}
		}
	}
	cout<<ans<<'\n';
	ans=0;
	for(int i=1;i<=3*n;i++)v[i]=0,b1[i]=0;
}

return 0;
}

