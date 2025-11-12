#include<bits/stdc++.h>
using namespace std;
int n,sum,flag[10005],a[100005],b[100005],c[100005],maxx=-1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		sum=0;
		int p=0,q=0,w=0;
		for(int i=1;i<=3;i++){
			flag[i]=0;
		}
		for(int i=1;i<=n;i++){
			
			cin>>a[i]>>b[i]>>c[i];
			maxx=max(max(a[i],b[i]),c[i]);
		    if(a[i]==maxx){
		    	flag[1]++;
		    	p+=a[i];
			}
			else if(b[i]==maxx){
				flag[2]++;
				q+=b[i];
			}
			else if(c[i]==maxx){
				flag[3]++;
				w+=c[i];
			}
			sum+=maxx;
		}
		if(flag[1]>n/2){
			sort(a+1,a+n+1,cmp);
			sum-=p;
			for(int i=1;i<=n/2;i++){
				sum+=a[i];
			}
		}
		else if(flag[2]>n/2){
			sort(b+1,b+n+1,cmp);
			sum-=q;
			for(int i=1;i<=n/2;i++){
				sum+=b[i];
			}
		}
		else if(flag[3]>n/2){
			sort(c+1,c+n+1,cmp);
			sum-=w;
			for(int i=1;i<=n/2;i++){
				sum+=c[i];
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
