#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T;
int n;
struct node{
	int a[4];
}s[N];
int f;
bool cmp(node x,node y){
	int maxx=-1,mzx=-1;
	for(int i=0;i<3;i++){
		if(i==f)continue;
		if(x.a[i]>maxx){
			mzx=maxx,maxx=x.a[i];
		}else if(x.a[i]>mzx)mzx=x.a[i];
	}
	int maxy=-1,mzy=-1;
	for(int i=0;i<3;i++){
		if(i==f)continue;
		if(y.a[i]>maxy){
			mzy=maxy,maxy=y.a[i];
		}else if(y.a[i]>mzy)mzy=y.a[i];
	}
	return maxx-mzx > maxy-mzy;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].a[0]>>s[i].a[1]>>s[i].a[2]; 
		}
		f=-1;
		sort(s+1,s+1+n,cmp);
		int k=1;
		int num[3]={0,0,0};
		int ans=0;
		for(;k<=n;k++){
			if(num[0]==n/2){
				f=0;break;
			}
			if(num[1]==n/2){
				f=1;break;
			}
			if(num[2]==n/2){
				f=2;break;
			}
			int j=3;
			for(int i=0;i<3;i++){
				if(s[k].a[i]>s[k].a[j])j=i;
			}
			num[j]++;
			ans+=s[k].a[j];
		}
		sort(s+k,s+1+n,cmp);
		for(;k<=n;k++){
			if(f!=0 &&num[0]==n/2){
				f=0;break;
			}
			if(f!=1 && num[1]==n/2){
				f=1;break;
			}
			if(f!=2 && num[2]==n/2){
				f=2;break;
			}
			int j=3;
			for(int i=0;i<3;i++){
				if(f==i)continue;
				if(s[k].a[i]>s[k].a[j])j=i;
			}
			num[j]++;
			ans+=s[k].a[j];
		}
		int j=3;
		for(int i=0;i<3;i++){
			if(num[i]<n/2){
				j=i;break;
			}
	    }
	    for(;k<=n;k++){
	    	ans+=s[k].a[j];
		}
		cout<<ans<<endl;
	}
	return 0;
} 
