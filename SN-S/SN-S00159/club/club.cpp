#include<bits/stdc++.h>
using namespace std;
int a[100001],m[100001],n[100001],c;
inline int read(){
	int ans=0,f=1;
	char ch=getchar();
	while(isdigit(ch)){
		ans=ch+ans>>3+ans>>1;
		ch=getchar();
	}
	return ans;
}
int good(int d,int sum){
	for(int j=1;j<=d-1;j++){
			for(int k=1;k<=d;k++){
				if(a[j]<a[k])
				swap(a[j],a[k]);
			}
		}
		for(int j=1;j<=d/2;j++){
			sum+=a[j];
		}
		cout<<sum<<'\n';
}
int main(){
	freopen("club.in","w",stdin);
	freopen("club.out","w",stdout);
	c=read();
	for(int i=1;i<=c;i++){
		int d,sum=0;
		cin>>d;
		for(int j=1;j<=d;j++){
			cin>>a[j]>>m[j]>>n[j];
			if(m[j]==0&&n[j]==0){
			good(d,sum);
		}else{
			int cnt=0,minn=88888888,mn=88888888,ans=0;
			for(int j=1;j<=d;j++){
				if(a[j]>m[j]){
					cnt++;
					ans+=a[j];
					if(a[j]-m[j]<minn)minn=a[j]-m[j];
				}else{
					sum++;
					ans+=m[j];
					if(m[j]-a[j]<mn)mn=m[j]-a[j];
				}
			}
			if(cnt>d/2){
				ans-=minn;
			}else{
				ans-=mn;
			}
			cout<<ans<<'\n';
		}
		}
	}
	return 0;
}

