#include<bits/stdc++.h> 
using namespace std;
int a[100005],b[100005],c[100005];
int aa[50005],bb[50005],cc[50005];
bool cmp(int x,int y){
	return x>y;
}
void tppxa(int x,int tha){
	for(int i=tha;i>=1;i--){
		if(a[x]<=aa[i]){
			for(int j=tha;j>=i-1;j--) a[j+1]=a[j];
			a[x]=a[i-1];
			break;
		}
	}
}
void tppxb(int x,int thb){
	for(int i=thb;i>=1;i--){
		if(b[x]<=bb[i]){
			for(int j=thb;j>=i-1;j--) b[j+1]=b[j];
			b[x]=b[i-1];
			break;
		}
	}
}
void tppxc(int x,int thc){
	for(int i=thc;i>=1;i--){
		if(c[x]<=cc[i]){
			for(int j=thc;j>=i-1;j--) c[j+1]=c[j];
			c[x]=c[i-1];
			break;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bool flag=true;
		int ta=0,tb=0,tc=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0||c[i]!=0) flag=false;
			if(a[i]>b[i]&&a[i]>c[i]){
				if(a[i]<a[ta]){
					if(b[i]>c[i]) tppxb(i,tb),ans+=b[i],tb++;
					if(c[i]>b[i]) tppxc(i,tc),ans+=c[i],tc++;
				}
				if(a[i]>a[ta]){
					tppxa(i,ta),ans+=a[i],ta++;
					if(b[ta]>c[ta]) tppxb(ta,tb),ans+=b[ta],tb++;
					if(c[ta]>b[ta])tppxc(ta,tc),ans+=c[ta],tc++;
				}
				if(a[i]==a[ta]){
					int max1=max(b[i],c[i]),max2=max(b[ta],c[ta]);
					if(max1>max2){
						if(b[i]>c[i]) tppxb(i,tb),ans+=b[i],tb++;
						if(c[i]>b[i]) tppxc(i,tc),ans+=c[i],tc++;
					}
					if(max1<max2){
						if(b[ta]>c[ta]) tppxb(ta,tb),ans+=b[ta],tb++;
						if(c[ta]>b[ta])tppxc(ta,tc),ans+=c[ta],tc++;
					}
				}
			}
			if(b[i]>a[i]&&b[i]>c[i]){
				if(b[i]<b[ta]){
					if(a[i]>c[i]) tppxa(i,ta),ans+=a[i],ta++;
					if(c[i]>a[i]) tppxc(i,tc),ans+=c[i],tc++;
				}
				if(b[i]>b[ta]){
					tppxa(i,tb),ans+=b[i],tb++;
					if(a[tb]>c[tb]) tppxa(tb,ta),ans+=a[tb],ta++;
					if(c[tb]>a[tb]) tppxc(tb,tc),ans+=c[tb],tc++;
				}
				if(a[i]==a[ta]){
					int max1=max(a[i],c[i]),max2=max(a[tb],c[tb]);
					if(max1>max2){
						if(a[i]>c[i]) tppxa(i,ta),ans+=a[i],ta++;
						if(c[i]>a[i]) tppxc(i,tc),ans+=c[i],tc++;
					}
					if(max1<max2){
						if(a[tb]>c[tb]) tppxa(tb,ta),ans+=a[tb],ta++;
						if(c[tb]>a[tb]) tppxc(tb,tc),ans+=c[tb],tc++;
					}
				}
			}
			if(c[i]>b[i]&&c[i]>a[i]){
				if(c[i]<c[tc]){
					if(a[i]>b[i]) tppxa(i,ta),ans+=a[i],ta++;
					if(b[i]>a[i]) tppxb(i,tb),ans+=b[i],tb++;
				}
				if(c[i]>c[tc]){
					tppxc(i,tc),ans+=c[i],tc++;
					if(b[ta]>a[ta]) tppxb(tc,tb),ans+=b[tc],tb++;
					if(a[ta]>b[ta]) tppxa(tc,ta),ans+=a[tc],ta++;
				}
				if(a[i]==a[ta]){
					int max1=max(b[i],a[i]),max2=max(b[tc],a[tc]);
					if(max1>max2){
						if(a[i]>b[i]) tppxa(i,ta),ans+=a[i],ta++;
						if(b[i]>a[i]) tppxb(i,tb),ans+=b[i],tb++;
					}
					if(max1<max2){
						if(b[ta]>a[ta]) tppxb(tc,tb),ans+=b[tc],tb++;
						if(a[ta]>b[ta]) tppxa(tc,ta),ans+=a[tc],ta++;
					}
				}
			}
			if(a[i]==b[i]){
				if(ta<tb) tppxb(i,tb),ans+=b[i],tb++;
				if(tb>ta) tppxa(i,ta),ans+=a[i],ta++;
			}
			if(a[i]==c[i]){
				if(ta<tc) tppxc(i,tc),ans+=c[i],tc++;
				if(tc>ta) tppxa(i,ta),ans+=a[i],ta++;
			}
			if(b[i]==c[i]){
				if(tc<tb) tppxb(i,tb),ans+=b[i],tb++;
				if(tb<tc) tppxc(i,tc),ans+=c[i],tc++;
			}
			if(flag==true){
				sort(a+1,a+n+1,cmp);
				int anss=0;
				for(int i=1;i<=n/2;i++) anss+=a[i];
				cout<<anss<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

