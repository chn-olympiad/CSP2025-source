#include<bits/stdc++.h>
using namespace std;
int t,n,anss,ans,qq,ww,ee;
struct qwe{
	int q,w,e;
}a[10000];
int str(qwe x,qwe y){
	if(max(x.q,max(x.w,x.e)) == max(y.q,max(y.w,y.e))){
		if(max(x.w,x.e) == max(y.w,y.e)){
			return x.e>y.e;
		}
		else return max(x.w,x.e)>max(y.w,y.e);
	}
	else return max(x.q,max(x.w,x.e)) > max(y.q,max(y.w,y.e));
}
int str1(qwe x,qwe y){ 
	return x.q>y.q;
}
int str1(qwe x,qwe y){ 
	return x.w>y.w;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i = 0;i<t;i++){
		anss = 0,ans = 0,qq = 0,ww = 0,ee = 0;
		cin>>n;
		bool t = true,tt = false;
		for(int j = 0;j<n;j++){
			cin>>a[j].q>>a[j].w>>a[j].e;
			if(a[j].w>0||a[j].e>0) t = false;
			if(a[j].e>0) tt = false;
		}
		if(t){
			sort(a+0,a+n,str1);
			for(int j = 0;j<n/2;j++) ans+=a[j].q;
			cout<<ans;
			continue;
		}
		if(tt){
			sort(a+0,a+n,str1);
			for(int j = 0;j<n/2;j++) ans+=a[j].q;
			for(int j = n/2;j<n;j++) ans+=a[j].w;
			anss = ans;
			ans = 0;
			sort(a+0,a+n,str2);
			for(int j = 0;j<n/2;j++) ans+=a[j].w;
			for(int j = n/2;j<n;j++) ans+=a[j].q;
			cout<<max(anss,ans);
			continue;
		}
		sort(a+0,a+n,str);
		for(int j = 0;j<n;j++){
			if(qq<n/2&&a[j].q>=a[j].w&&a[j].q>=a[j].e) ans+=a[j].q,qq++;
			else if(ww<n/2&&a[j].w>=a[j].q&&a[j].w>=a[j].e) ans+=a[j].w,ww++;
			else if(ee<n/2&&a[j].e>=a[j].w&&a[j].e>=a[j].w) ans+=a[j].e,ee++;
			else{
				if(qq<n/2) ans+=a[j].q,qq++;
				else if(ww<n/2) ans+=a[j].w,ww++;
				else if(ee<n/2) ans+=a[j].e,ee++;
			}
		}
		anss = ans; 
		ans = 0,qq = 0,ww = 0,ee = 0;
		for(int j = n-1;j>=0;j--){
			if(qq<n/2&&a[j].q>=a[j].w&&a[j].q>=a[j].e) ans+=a[j].q,qq++;
			else if(ww<n/2&&a[j].w>=a[j].q&&a[j].w>=a[j].e) ans+=a[j].w,ww++;
			else if(ee<n/2&&a[j].e>=a[j].w&&a[j].e>=a[j].w) ans+=a[j].e,ee++;
			else{
				if(qq<n/2) ans+=a[j].q,qq++;
				else if(ww<n/2) ans+=a[j].w,ww++;
				else if(ee<n/2) ans+=a[j].e,ee++;
			}
		}
		cout<<max(anss,ans)<<endl;
	}
} 
