#include<bits/stdc++.h>
using namespace std;
struct Peo{
	int a,b,c;
}arr[100005];
struct Xz{
	int zu,xq;
}brr[100005];
int crr[4]={}; 
int drr[4]={}; 
int err[50005]={};
int frr[3][100005]={};
int grr[3][100005]={};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>arr[i].a>>arr[i].b>>arr[i].c; 
			brr[i].xq=max(arr[i].a,max(arr[i].b,arr[i].c));
			ans+=brr[i].xq;
			if(brr[i].xq==arr[i].a){
				crr[1]++;
				brr[i].zu=1;
				frr[1][crr[1]]=brr[i].xq;
			}else if(brr[i].xq==arr[i].b){
				crr[2]++;
				brr[i].zu=2;
				frr[2][crr[2]]=brr[i].xq;
			}else{
				crr[3]++;
				brr[i].zu=3;
				frr[3][crr[3]]=brr[i].xq;
			}
		}
		if(crr[1]<=n/2&&crr[2]<=n/2&&crr[3]<=n/2){
			cout<<ans<<"\n";
			continue;
		}
		int qq=0,ww=0,ee=0;
		if(crr[1]>n/2){
			for(int i=1;i<=crr[1];i++){
				qq++;
				grr[1][qq]=arr[i].a;
			}
		}
		if(crr[2]>n/2){
			for(int i=1;i<=crr[2];i++){
				ww++;
				grr[3][ww]=arr[i].a;
			}
		}
		if(crr[3]>n/2){
			for(int i=1;i<=crr[3];i++){
				ee++;
				grr[3][ee]=arr[i].a;
			}
		}
		sort(grr[1]+1,grr[1]+qq);
		sort(grr[2]+1,grr[2]+ww);
		sort(grr[3]+1,grr[3]+ee);
		for(int i=1;i<=crr[1]-n/2;i++){ 
			brr[i].xq=max(arr[i].b,arr[i].c);
			ans-=brr[i].xq;
			if(brr[i].xq==arr[i].b){
				crr[2]++;
				brr[i].zu=2;
				frr[2][crr[2]]=brr[i].xq;
			}else{
				crr[3]++;
				brr[i].zu=3;
				frr[3][crr[3]]=brr[i].xq;
			}
			crr[1]--;
		}
		for(int i=1;i<=crr[3]-n/2;i++){ 
			brr[i].xq=max(arr[i].a,arr[i].b);
			ans-=brr[i].xq;
			if(brr[i].xq==arr[i].a){
				crr[1]++;
				brr[i].zu=1;
				frr[1][crr[1]]=brr[i].xq;
			}else{
				crr[2]++;
				brr[i].zu=2;
				frr[2][crr[2]]=brr[i].xq;
			}
			crr[2]--;
		}
		for(int i=1;i<=crr[2]-n/2;i++){ 
			brr[i].xq=max(arr[i].b,arr[i].a);
			ans+=brr[i].xq;
			if(brr[i].xq==arr[i].a){
				crr[2]++;
				brr[i].zu=2;
				frr[2][crr[2]]=brr[i].xq;
			}else{
				crr[2]++;
				brr[i].zu=2;
				frr[2][crr[2]]=brr[i].xq;
			}
			crr[1]--;
		}
		if(crr[1]<=n/2&&crr[2]<=n/2&&crr[3]<=n/2){
			cout<<ans<<"\n";
			continue;
		}
		qq=0,ww=0,ee=0;
		if(crr[1]>n/2){
			for(int i=1;i<=crr[1];i++){
				qq++;
				grr[1][qq]=arr[i].a;
			}
		}
		if(crr[2]>n/2){
			for(int i=1;i<=crr[2];i++){
				ww++;
				grr[3][ww]=arr[i].a;
			}
		}
		if(crr[3]>n/2){
			for(int i=1;i<=crr[3];i++){
				ee++;
				grr[3][ee]=arr[i].a;
			}
		}
		sort(grr[1]+1,grr[1]+qq);
		sort(grr[2]+1,grr[2]+ww);
		sort(grr[3]+1,grr[3]+ee);
		for(int i=1;i<=crr[1]-n/2;i++){ 
			brr[i].xq=max(arr[i].b,arr[i].c);
			ans-=brr[i].xq;
			if(brr[i].xq==arr[i].b){
				crr[2]++;
				brr[i].zu=2;
				frr[2][crr[2]]=brr[i].xq;
			}else{
				crr[3]++;
				brr[i].zu=3;
				frr[3][crr[3]]=brr[i].xq;
			}
			crr[1]--;
		}
		for(int i=1;i<=crr[3]-n/2;i++){ 
			brr[i].xq=max(arr[i].a,arr[i].b);
			ans-=brr[i].xq;
			if(brr[i].xq==arr[i].a){
				crr[1]++;
				brr[i].zu=1;
				frr[1][crr[1]]=brr[i].xq;
			}else{
				crr[2]++;
				brr[i].zu=2;
				frr[2][crr[2]]=brr[i].xq;
			}
			crr[2]--;
		}
		for(int i=1;i<=crr[2]-n/2;i++){ 
			brr[i].xq=max(arr[i].b,arr[i].a);
			ans+=brr[i].xq;
			if(brr[i].xq==arr[i].a){
				crr[2]++;
				brr[i].zu=2;
				frr[2][crr[2]]=brr[i].xq;
			}else{
				crr[2]++;
				brr[i].zu=2;
				frr[2][crr[2]]=brr[i].xq;
			}
			crr[1]--;
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
