#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	int n,a[100005][4],b,c;//
	while(t--){
		long long ans=0;
		int d[4];
		cin>>n;
		d[1]=0,d[2]=0,d[3]=0;
		for(int i=1;i<=n;i++){
			b=0;c=0;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>b){
					b=a[i][j];
					c=j;
				}
			}
			ans+=b;
			//cout<<b[i]<<" ";
			d[c]++;
		}
		if(d[1]<=n/2&&d[2]<=n/2&&d[3]<=n/2){
			cout<<ans<<endl;
		}
		else {
			int e,e1;
			if(d[1]>d[2]&&d[1]>d[3]){
				e=d[1];
				e1=1;
			}
			else if(d[2]>d[3]&&d[2]>d[1]){
				e=d[2];
				e1=2;
			}
			else if(d[3]>d[1]&&d[3]>d[2]){
				e=d[3];
				e1=3;
			}
			int cnt=e-(n/2);
			int ch[100006];
			int cnt1=0;
			for(int i=1;i<=n;i++){
				if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]&&e1!=1){
					continue;
			    }
			    else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]&&e1!=2){
			    	continue;
			    }
			    else if(a[i][3]>a[i][2]&&a[i][3]>a[i][1]&&e1!=3){
			    	continue;
			    }
			    else{
				int mx=0;
				int mx1=max(a[i][1],max(a[i][2],a[i][3]));
				for(int j=1;j<=3;j++){
					if(a[i][1]==a[i][2]==mx1||a[i][2]==a[i][3]==mx1||a[i][1]==a[i][3]==mx1){
						mx=mx1;
					}
					else if(a[i][j]>mx&&a[i][j]<mx1){
						mx=a[i][j];
					}
				}
				ch[++cnt1]=mx1-mx;
			    }
			}
			sort(ch+1,ch+cnt1+1);
			for(int i=1;i<=cnt;i++){
				ans-=ch[i];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}