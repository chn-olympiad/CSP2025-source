#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n],b[n],c[n];
		int am[n],bm[n],cm[n];
		for(int i=0;i<n;i++){
			am[i]=0,bm[i]=0,cm[i]=0;
		}
		
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>b[i]){
				if(a[i]>c[i]){
					am[i]=a[i];
				}else{
					cm[i]=c[i];	
				}
			}else{
				if(b[i]>c[i]){
					bm[i]=b[i];
				}else{
					cm[i]=c[i];	
				}
			}
		}	
		int cnt=0,maxa=0;
		for(int i=0;i<n/2;i++){
			for(int j=0;j<n;j++){
				if(am[j]-max(b[j],c[j])>am[maxa]-max(b[maxa],c[maxa]) && a[j]!=0){
					maxa=j;
				}
			}
			cnt+=am[maxa];
			am[maxa]=0;
		}
		for(int i=0;i<n;i++){
			if(am[i]>0){
				if(b[i]>c[i]){
					bm[i]=b[i];
				}else{
					cm[i]=c[i];
				}
				am[i]=0;
			}
		}
		int maxb=0;
		for(int i=0;i<n/2;i++){
			for(int j=0;j<n;j++){
				if(bm[j]-max(a[j],c[j])>bm[maxb]-max(a[maxb],c[maxb]) && b[j]!=0){
					maxb=j;
				}
			}
			cnt+=bm[maxb];
			bm[maxb]=0;
		}
		for(int i=0;i<n;i++){
			if(bm[i]>0){
				if(a[i]>c[i]){
					am[i]=a[i];
				}else{
					cm[i]=c[i];
				}
				bm[i]=0;
			}
		}
		int maxc=0;
		for(int i=0;i<n/2;i++){
			for(int j=0;j<n;j++){
				if(cm[j]-max(a[j],b[j])>cm[maxc]-max(a[maxc],b[maxc]) && cm[j]!=0){
					maxc=j;
				}
			}
			cnt+=cm[maxc];
			cm[maxc]=0;
		}
		for(int i=0;i<n;i++){
			if(cm[i]>0){
				if(a[i]>b[i]){
					am[i]=a[i];
				}else{
					bm[i]=b[i];
				}
				cm[i]=0;
			}
		}
		for(int i=0;i<n;i++){
			cnt+=(am[i]+bm[i]+cm[i]);
		}
		cout<<cnt<<" ";
	}
		
	return 0;
}

