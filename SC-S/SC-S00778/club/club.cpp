#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N],b[N],c[N],tmp,r[5],temp;
bool flag=0;
long long maxn,sum;
vector <int> e[5];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		maxn=0;
		tmp=n/2;
		flag=0;
		r[1]=0;
		r[2]=0;
		r[3]=0;
		e[1].clear();
		e[2].clear();
		e[3].clear();
		sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0||c[i]!=0)//性质A 
				flag=1;
			if(a[i]>=b[i]&&a[i]>=c[i]){
				r[1]++;
				sum+=a[i];
				temp=max(b[i],c[i]);
				temp=a[i]-temp;
				e[1].push_back(temp);
			}
			if(b[i]>a[i]&&b[i]>=c[i]){
				r[2]++;
				sum+=b[i];
				temp=max(a[i],c[i]);
				temp=b[i]-temp;
				e[2].push_back(temp);
			}
				
			if(c[i]>a[i]&&c[i]>b[i]){
				r[3]++;
				sum+=c[i];
				temp=max(b[i],a[i]);
				temp=c[i]-temp;
				e[3].push_back(temp);
			}	 
		}	
		if(flag==0){
			sort(a+1,a+1+n);
			for(int i=n;i>tmp;i--)
				maxn+=a[i];
			cout<<maxn<<'\n';
			continue;
		}
		else{
			if(r[1]<=tmp&&r[2]<=tmp&&r[3]<=tmp){
				cout<<sum<<'\n';
				continue;
			}
			else{
				if(r[1]>tmp){
					sort(e[1].begin(),e[1].end());
					temp=e[1].size()-1;
					for(int i=0;i<=temp-tmp;i++)
						sum-=e[1][i];
					cout<<sum<<'\n';
					continue;
				} 
				if(r[2]>tmp){
					sort(e[2].begin(),e[2].end());
					temp=e[2].size()-1;
					
					for(int i=0;i<=temp-tmp;i++)
						sum-=e[2][i];
					cout<<sum<<'\n';
					continue;
				}
				if(r[3]>tmp){
					sort(e[3].begin(),e[3].end());
					temp=e[3].size()-1;
					for(int i=0;i<=temp-tmp;i++)
						sum-=e[3][i];
					cout<<sum<<'\n';
					continue;
				}
			}	
		}	
	}
	return 0;
} 