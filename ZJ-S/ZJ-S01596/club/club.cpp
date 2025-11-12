#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+5;
long long n,a[N],b[N],c[N],maxx[N],cha[N],t,ans,m,x1,x2,x3,sum,u1[N],u2[N],u3[N];
void solve(){
	cin>>n;
	m=n/2;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		if(a[i]>=b[i]&&a[i]>=c[i]){
//			cout<<"x1:"<<i<<"\n";
			maxx[i]=a[i];
			cha[i]=min(a[i]-b[i],a[i]-c[i]);
			x1++;
			sum+=a[i];
			u1[x1]=i;
		}else{
			if(b[i]>=a[i]&&b[i]>=c[i]){
//				cout<<"x2:"<<i<<"\n";
				maxx[i]=b[i];
				cha[i]=min(b[i]-a[i],b[i]-c[i]);
				x2++;
				sum+=b[i];
				u2[x2]=i;
			}else{
				if(c[i]>=b[i]&&c[i]>=a[i]){
//					cout<<"x3:"<<i<<"\n";
					maxx[i]=c[i];
					cha[i]=min(c[i]-b[i],c[i]-a[i]);
					x3++;
					sum+=c[i];
					u3[x3]=i;
				}
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" "<<b[i]<<' '<<c[i]<<' '<<maxx[i]<<' '<<cha[i]<<'\n';
//	}
//	cout<<"x1:"<<x1<<'\n';
//	for(int i=1;i<=x1;i++){
//		cout<<u1[i]<<"--"<<cha[u1[i]]<<'\n';
//	}
//	cout<<"x2:"<<x2<<'\n';
//	for(int i=1;i<=x2;i++){
//		cout<<u2[i]<<"--"<<cha[u2[i]]<<'\n';
//	}
//	cout<<"x3:"<<x3<<'\n';
//	for(int i=1;i<=x3;i++){
//		cout<<u3[i]<<"--"<<cha[u3[i]]<<'\n';
//	}
	long long k=0;
//	cout<<x1<<" "<<x2<<" "<<x3<<"\n";
	while(x1>m+k){
		long long minn=INT_MAX,x=0;
		for(int i=1;i<=x1;i++){
//			cout<<minn<<" "<<cha[u1[i]]<<'\n';
			if(minn>cha[u1[i]]){
				minn=cha[u1[i]];
				x=u1[i];
			}
		}
		cha[x]=INT_MAX;
		sum-=minn;
		k++;
	}
	while(x2>m+k){
		long long minn=INT_MAX,x=0;
		for(int i=1;i<=x2;i++){
//			cout<<minn<<" "<<cha[u2[i]]<<'\n';
			if(minn>cha[u2[i]]){
				minn=cha[u2[i]];
				x=u2[i];
			}
		}
		cha[x]=INT_MAX;
		sum-=minn;
		k++;
	}
	while(x3>m+k){
		long long minn=INT_MAX,x=0;
		for(int i=1;i<=x3;i++){
//			cout<<minn<<" "<<cha[u3[i]]<<'\n';
			if(minn>cha[u3[i]]){
				minn=cha[u3[i]];
				x=u3[i];
			}
		}
		cha[x]=INT_MAX;
		sum-=minn;
		k++;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		solve();
		cout<<sum<<'\n';
		sum=0;
		for(int i=1;i<=n;i++){
			maxx[i]=0;
			cha[i]=0;
			u1[i]=0;
			u2[i]=0;
			u3[i]=0;
		}
		x1=0;
		x2=0;
		x3=0;
	}      
	return 0;
}