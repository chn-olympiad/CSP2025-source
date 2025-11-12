#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int n;
struct node{
	int x,y,z;
}a[N];

int cnt1,cnt2,cnt3;
int w[N],s[N],e[N];
int ans;

void dfs(int x,int cntx,int cnty,int cntz,int sum){
	if(x==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(cntx<n/2) dfs(x+1,cntx+1,cnty,cntz,sum+a[x].x);
	if(cnty<n/2) dfs(x+1,cntx,cnty+1,cntz,sum+a[x].y);
	if(cntz<n/2) dfs(x+1,cntx,cnty,cntz+1,sum+a[x].z);
	return ;
}

bool cmp(node x,node y){
	int maxx=max(x.x,max(x.y,x.z));
	int minx=min(x.x,min(x.y,x.z));
	int sum=x.x+x.y+x.z;
	int mid=sum-maxx-minx;
	
	int maxy=max(y.x,max(y.y,y.z));
	int miny=min(y.x,min(y.y,y.z));
	int sumy=y.x+y.y+y.z;
	int midy=sumy-maxy-miny;
	
	if(maxx-mid==maxy-midy){
		return mid-minx>midy-miny;
	}
	return maxx-mid>maxy-midy;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		cnt1=0;
		cnt2=0;
		cnt3=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		if(n<=10){
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
			continue;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].x>a[i].y && a[i].x>a[i].z) {
				if(cnt1<n/2){
					cnt1++;
					w[cnt1]=i;
				}
				else {
					if(a[i].y>a[i].z && cnt2<n/2) {
						cnt2++;
						s[cnt2]=i;
					}
					else{
						cnt3++;
						e[cnt3]=i;
					}
				}
			}
			else if(a[i].y>a[i].x && a[i].y>a[i].z){
				if(cnt2<n/2){
					cnt2++;
					s[cnt2]=i;
				}
				else {
					if(a[i].x>a[i].z && cnt1<n/2){
						cnt1++;
						w[cnt1]=i;
					}
					else{
						cnt3++;
						e[cnt3]=i;
					}
				}
			}
			else{
				if(cnt3<n/2){
					cnt3++;
					e[cnt3]=i;
				}
				else{
					if(a[i].x>a[i].y && cnt1<n/2){
						cnt1++;
						w[cnt1]=i;
					}
					else {
						cnt2++;
						s[cnt2]=i;
					}
				}
			}
		}
		for(int i=1;i<=cnt1;i++){
			ans+=a[w[i]].x;
		}
		for(int i=1;i<=cnt2;i++) {
			ans+=a[s[i]].y;
		}
		for(int i=1;i<=cnt3;i++){
			ans+=a[e[i]].z;
		}
		cout<<ans<<endl;
		continue;
		//sort(a+1,a+1+n,cmp1);
		//sort(b+1,b+1+n,cmp2);
		//sort(b+1,b+1+n,cmp2);
		for(int i=1;i<=n;i++){
			if(a[i].x>a[i].y && a[i].x>a[i].z){
				if(cnt1<n/2) {
					cnt1++;
					w[cnt1]=i;
				}
				else {
					if(cnt2<n/2 && cnt3<n/2){
						int temp2,temp3,min2=INT_MAX,min3=INT_MAX;
						for(int j=1;j<=cnt1;j++){
							if(a[w[j]].x-a[w[j]].y<min2){
								temp2=w[j];
								min2=a[w[j]].x-a[w[j]].y;
							}
						}
						for(int j=1;j<=cnt1;j++){
							if(a[w[j]].x-a[w[j]].z<min3){
								temp3=w[j];
								min3=a[w[j]].x-a[w[j]].z;
							}
						}
						if(min2<a[i].x || min3<a[i].x){
							if(min2<min3){
								w[cnt1]=i;
								cnt2++;
								s[cnt2]=temp2;
							}
							else {
								w[cnt1]=i;
								cnt3++;
								e[cnt3]=temp3;
							}
						}
					}
					else if(cnt2<n/2){
						int temp2,min2=INT_MAX;
						for(int j=1;j<=cnt1;j++){
							if(a[w[j]].x-a[w[j]].y<min2){
								temp2=w[j];
								min2=a[w[j]].x-a[w[j]].y;
							}
						}
						if(min2<a[i].x){
							w[cnt1]=i;
							cnt2++;
							s[cnt2]=temp2;
						}
					}
					else {
						int temp3,min3=INT_MAX;
						for(int j=1;j<=cnt1;j++){
							if(a[w[j]].x-a[w[j]].z<min3){
								temp3=w[j];
								min3=a[w[j]].x-a[w[j]].z;
							}
						}
						if(min3<a[i].x){
							w[cnt1]=i;
							cnt3++;
							e[cnt3]=temp3;
						}
					}
				}
			}
			else if(a[i].y>a[i].x && a[i].y>a[i].z){
				if(cnt2<n/2) {
					cnt2++;
					s[cnt2]=i;
				}
				else {
					if(cnt1<n/2 && cnt3<n/2){
						int temp1,temp3,min1=INT_MAX,min3=INT_MAX;
						for(int j=1;j<=cnt2;j++){
							if(a[s[j]].y-a[s[j]].x<min1){
								temp1=s[j];
								min1=a[s[j]].y-a[s[j]].x;
							}
						}
						for(int j=1;j<=cnt2;j++){
							if(a[s[j]].y-a[s[j]].z<min3){
								temp3=s[j];
								min3=a[s[j]].y-a[s[j]].z;
							}
						}
						if(-min1<a[i].y || -min3<a[i].y){
							if(-min1<-min3){
								s[cnt2]=i;
								cnt1++;
								w[cnt1]=temp1;
							}
							else {
								s[cnt2]=i;
								cnt3++;
								e[cnt3]=temp3;
							}
						}
					}
					else if(cnt1<n/2){
						int temp1,min1=INT_MAX;
						for(int j=1;j<=cnt2;j++){
							if(a[s[j]].y-a[s[j]].x<min1){
								temp1=s[j];
								min1=a[s[j]].y-a[s[j]].x;
							}
						}
						if(-min1<a[i].y){
							s[cnt2]=i;
							cnt1++;
							w[cnt1]=temp1;
						}
					}
					else {
						int temp3,min3=INT_MAX;
						for(int j=1;j<=cnt2;j++){
							if(a[s[j]].y-a[s[j]].z<min3){
								temp3=s[j];
								min3=a[s[j]].y-a[s[j]].z;
							}
						}
						if(-min3<a[i].y){
							s[cnt2]=i;
							cnt3++;
							e[cnt3]=temp3;
						}
					}
				}
			}
			else{
				if(cnt3<n/2) {
					cnt3++;
					e[cnt3]=i;
				}
				else {
					if(cnt1<n/2 && cnt2<n/2){
						int temp1,temp2,min1=INT_MAX,min2=INT_MAX;
						for(int j=1;j<=cnt3;j++){
							if(a[e[j]].z-a[e[j]].x<min1){
								temp1=e[j];
								min1=a[e[j]].z-a[e[j]].x;
							}
						}
						for(int j=1;j<=cnt3;j++){
							if(a[e[j]].z-a[e[j]].y<min2){
								temp2=e[j];
								min2=a[e[j]].z-a[e[j]].y;
							}
						}
						if(min2<a[i].z || min1<a[i].z){
							if(min2<min1){
								e[cnt3]=i;
								cnt2++;
								s[cnt2]=temp2;
							}
							else {
								e[cnt3]=i;
								cnt1++;
								e[cnt1]=temp1;
							}
						}
					}
					else if(cnt2<n/2){
						int temp2,min2=INT_MAX;
						for(int j=1;j<=cnt3;j++){
							if(a[e[j]].z-a[e[j]].y<min2){
								temp2=e[j];
								min2=a[e[j]].z-a[e[j]].y;
							}
						}
						if(min2<a[i].z){
							e[cnt3]=i;
							cnt2++;
							s[cnt2]=temp2;
						}
					}
					else {
						int temp1,min1=INT_MAX;
						for(int j=1;j<=cnt3;j++){
							if(a[e[j]].z-a[e[j]].x<min1){
								temp1=e[j];
								min1=a[e[j]].z-a[e[j]].x;
							}
						}
						if(min1<a[i].z){
							e[cnt3]=i;
							cnt1++;
							w[cnt1]=temp1;
						}
					}
				}
			}
		}
		for(int i=1;i<=cnt1;i++){
			ans+=a[w[i]].x;
		}
		for(int i=1;i<=cnt2;i++) {
			ans+=a[s[i]].y;
		}
		for(int i=1;i<=cnt3;i++){
			ans+=a[e[i]].z;
		}
		cout<<ans<<endl;
	}
	return 0;
}
