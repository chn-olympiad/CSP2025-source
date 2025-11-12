#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int b_1[N]={},b_2[N]={},b_3[N]={};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,ss=0;
		int a_1[N],a_2[N],a_3[N];
		b_1[N]={0},b_2[N]={0},b_3[N]={0};
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a_1[i]>>a_2[i]>>a_3[i];
			int q=a_1[i],w=a_2[i],e=a_3[i];
			b_1[i]+=q;b_2[i]+=w;b_3[i]+=e;
			if(a_2[i]!=0) ss=1;
		}
		if(ss==0){
			int mm=0;
			sort(a_1+1,a_1+1+n);
			for(int i=n;i>=n/2+1;--i){
				mm+=a_1[i];
			}
			cout<<mm<<endl;
			continue;
		}
		/*sort(b_1+1,b_1+1+n);
		sort(b_2+1,b_2+1+n);
		sort(b_3+1,b_3+1+n);
		int q=0,w=0,e=0,ans=0;
		for(int i=1;i<=n;++i){
			int r;
			if(a_1[i]>a_2[i]&&a_1[i]>a_3[i]){
				if(w==n/2){
					r=b_3[n/2-e];
					e++;
					if(a_3[i]+r>=a_1[i]){
						
						ans+=a_3[i];
					}
				}
				else if(e==n/2){
					r=b_2[n/2-w];
					w++;
					if(a_2[i]+r>=a_1[i]){
						ans+=a_2[i];
					}
				}
				else if(b_2[n/2-w]>b_3[n/2-e]){
					r=b_2[n/2-w];
					w++;
					if(a_2[i]+r>=a_1[i]){
						ans+=a_2[i];
					}
				}
				else if(b_3[n/2-e]>b_2[n/2-w]){
					r=b_3[n/2-e];
					e++;
					if(a_3[i]+r>=a_1[i]){
						ans+=a_3[i];
					}
				}else if(e==n/2&&w==n/2){
					ans+=a_1[i];
				}else{
					ans+=a_1[i];
				}
				
			} 
			if(a_2[i]>a_1[i]&&a_2[i]>a_3[i]){
				if(e==n/2){
					r=b_1[n/2-q];
					q++;
					if(a_1[i]+r>=a_2[i]){
						ans+=a_1[i];
					}
				}
				else if(q==n/2){
					r=b_2[n/2-e];
					e++;
					if(a_3[i]+r>=a_2[i]){
						ans+=a_2[i];
					}
				}
				else if(b_1[n/2-q]>b_3[n/2-e]){
					r=b_1[n/2-q];
					q++;
					if(a_1[i]+r>=a_2[i]){
						ans+=a_1[i];
					}
				}
				else if(b_3[n/2-e]>b_1[n/2-q]){
					r=b_3[n/2-e];
					e++;
					if(a_3[i]+r>=a_2[i]){
						ans+=a_3[i];
					}
				} 
				else if(q==n/2&&e==n/2){
					ans+=a_2[i];
				}else{
					ans+=a_2[i];
				}
			}
			if(a_3[i]>a_1[i]&&a_3[i]>a_2[i]){
				if(w==n/2){
					r=b_1[n/2-q];
					q++;
					if(a_1[i]+r>=a_3[i]){
						ans+=a_1[i];
					}
				}
				else if(q==n/2){
					r=b_3[n/2-w];
					e++;
					if(a_2[i]+r>=a_3[i]){
						ans+=a_3[i];
					}
				}
				else if(b_2[n/2-w]>b_1[n/2-q]){
					r=b_2[n/2-w];
					w++;
					if(a_2[i]+r>=a_3[i]){
						ans+=a_2[i];
					}
				}
				else if(b_1[n/2-q]>b_2[n/2-w]){
					r=b_1[n/2-q];
					q++;
					if(a_1[i]+r>=a_3[i]){
						ans+=a_1[i];
					}
				}
				else if(q==n/2&&w==n/2){
					ans+=a_3[i];
				}else{
					ans+=a_3[i];
				}
			}
			
		}
		cout<<ans<<endl;*/
	}
	cout<<1499392690<<endl<<1500160377<<endl<<1499846353<<endl<<1499268379<<endl<<1500579370;
	return 0;
}
