#include<bits/stdc++.h>
using namespace std;
//string n;
//vector<int> ans;
bool cmp(int a,int b){
	return a>b;
}

bool f[500010];
int n,k;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int ans=0;
	int y=0;
	int u=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1){
			if(a[i]==0){
			}else{
				u=1;
			}
			y=1;
		}
	}
	if(y==0){
		cout<<1<<endl;
		u=1;
	}
	if(u==0){
		for(int i=1;i<n;i++){
			if(a[i-1]==0 && a[i]==1) a[i]=1;
			if(a[i-1]==0 && a[i]==0) a[i]=0;
			if(a[i-1]==1) a[i]=(a[i]==0)?1:0;
		}
//		for(int i=0;i<n;i++){
//			cout<<a[i]<<" ";
//		}
//		cout<<endl;
		
	}
	if(y==0){
		for(int i=0;i<n;i++){
			if(i%2==0) a[i]=1;
			else{
				a[i]=0;
			}
		}
//		goto 35;
	}
	else if(u==1){
		for(int i=1;i<n;i++){
			a[i]=a[i]^a[i-1];
//			cout<<a[i]<<endl;
		}
	}
	if(u==1 && (u==1 && y==0)){
		for(int i=1;i<n;i++){
			a[i]=a[i]+a[i-1];
		}
	}
	
//	for(int i=0;i<n;i++){
//			cout<<a[i]<<" ";
//		}
//	cout<<endl;
//	cout<<a[1]|a[1-1];
//	sort(a,a+n,cmp);
//	for(int i=0;i<n;i++){
//		int sum=0;
//		f[i]=1;
//		int ni=0;
//		bool yes=0;
//		while(sum!=k){
//			if(ni>=n) break;
//			if(sum+a[ni]>k || f[ni]){
//				ni++;
//				continue;
//			}
//			sum+=a[ni];
//			if(sum==k){
//				yes=1;
//				break;
//			}
//			f[ni]=1;
//			ni++;
//		}
//		if(yes){
//			ans++;
//		}
//	}
//	cout<<ans-1;
	if(u==0){
		int i=0;
		while(1){
			int sum=0;
			int ui=i;
			f[1]=0;
			while(sum!=k){
				if(ui>n){
					i=ui+1;
					sum=0;
					break;
				}
				if(ui==0 && a[ui]==1){
//					cout<<1<<endl;
					sum++;
				}
				else if(f[ui]==0 && a[ui]==1) {
//					cout<<ui<<endl;
					sum++;
				}
				if(sum==k){
//					cout<<ui<<endl;
//					f[ui]=0;
					ans++;
					i=ui+1;
					sum=0;
					break;
				}
				else f[ui]=1;
				ui++;
			}
			if(i>n) break;
		}
	}
	if(y==0){
		if(k%2==0){
			for(int r=k+k/2;r<=n;r+=k+k/2+1){
				ans++;
			}
		}else{
			for(int r=k+k/2;r<=n;r+=k+k/2+2){
				ans++;
			}
		}	
	}else{
		for(int l=0;l<n;l++){
			for(int r=l;r<n;r++){
//				if(l==0){
//					if(a[r]&a[l]==k) ans++;
//				}else{
//					if(a[r]&a[l-1]==k) ans++;
//				}
				int sum=l;
				for(int i=l+1;i<=r;i++){
					sum^=a[i-1];
				}
				if(sum==k){
					ans++;
				}
			}
		}
		ans=ans;
//		sort(a,a+n,cmp);
//		for(int i=0;i<n;i++){
//			int sum=0;
//			f[i]=1;
//			int ni=0;
//			bool yes=0;
//			while(sum!=k){
//				if(ni>=n) break;
//				if(sum+a[ni]>k || f[ni]){
//					ni++;
//					continue;
//				}
//				sum+=a[ni];
//				if(sum==k){
//					yes=1;
//					break;
//				}
//				f[ni]=1;
//				ni++;
//			}
//			if(yes){
//				ans++;
//			}
//		}
//		ans;
//		cout<<0;
//		return 0;
	}
	cout<<ans;
	return 0;
}
