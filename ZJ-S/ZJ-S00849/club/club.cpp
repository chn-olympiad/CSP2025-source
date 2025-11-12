#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,t,sx,sum,j;
int visa[N],visb[N];

struct Node{
	int a,st;
}a[N],b[N],c[N];
bool cmp(Node a,Node b){
	return a.a>b.a;
}
int cheak(int cc,int d){
	if (d==1){
		for (int i=1;i<=N;i++){
			if(a[i].st==cc) return i;
		}
	}
	if (d==2){
		for (int i=1;i<=N;i++){
			if(b[i].st==cc) return i;
		}
	}
	
}
int d,e,f;
int main(){
	freopen("./club.in","r",stdin);
	freopen("./club.out","w",stdout);
	cin>>t;
	while (t--){
		//初始化 
		cin>>n;
		sum=0;
		if (n==2){
			int ea[4],eb[4];
			cin>>ea[1]>>ea[2]>>ea[3];
			cin>>eb[1]>>eb[2]>>eb[3];


			sum=max(sum,ea[1]+eb[2]);
			sum=max(sum,ea[1]+eb[3]);
			sum=max(sum,ea[2]+eb[1]);
			sum=max(sum,ea[2]+eb[3]);
			sum=max(sum,ea[3]+eb[1]);
			sum=max(sum,ea[3]+eb[2]);
					
				
			
		}
		else{
			sx=n/2;

		
			memset(visa,0,sizeof(visa));
			memset(visb,0,sizeof(visb));
			for (int i=1;i<=n;i++){
				cin>>a[i].a>>b[i].a>>c[i].a;
				a[i].st=i;b[i].st=i;c[i].st=i;
			}
			sort(a+1,a+n+1,cmp);
			sort(b+1,b+n+1,cmp);
			sort(c+1,c+n+1,cmp);
			//选择A 
			for (int i=1;i<=sx;i++){
				sum+=a[i].a;
				visa[a[i].st]=1;
				
			}
			//选择B 
			j=1;
			for (int i=1;i<=sx;i++){
				
				if(visa[b[j].st]==0){
					sum+=b[j].a;
					visb[b[j].st]=1;
	
				}
				else{
					int ac=cheak(b[j].st,1);
					if(a[ac].a>b[j].a) {
						j++;
						i--;
					}
					else {
						visa[a[ac].st]=0;
						sum-=a[ac].a;
						visb[b[j].st]=1;
						sum+=b[j].st;
					
					}
				}
				j++;
			}
			//选择C 
			j=1;
			for (int i=1;i<=sx;i++){
	
				if(visa[c[j].st]==0&&visb[c[j].st]==0){
					sum+=c[j].a;
	
				}
				
				
				else{
					if(visa[c[j].st]!=0){
						int ac=cheak(c[j].st,1);
						if(a[ac].a>=c[j].a) {
							j++;
							i--;
						}
						else {
							visa[c[j].st]=0;
							sum-=a[ac].a;
							visb[c[j].st]=1;
							sum+=c[j].a;
							
						}
					}
					else if (visb[c[j].st]!=0){
						int ac=cheak(c[j].st,2);
						if(b[ac].a>=c[j].a) {
							j++;
							i--;
						}
						else {
							visb[c[j].st]=0;
							sum-=b[ac].a;
							sum+=c[j].a;
				
						}
					}
				}
				j++;
			}
		}
		
		
		cout<<sum<<"\n";
	}
	return 0;
}

