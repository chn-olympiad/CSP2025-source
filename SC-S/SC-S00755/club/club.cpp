#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct num{
	int x[4],id[4];
}a[100010];
bool cmp(num m,num n){
	return m.x[1]+m.x[2]>n.x[1]+n.x[2];
}
bool cmp2(num m,num n){
	return m.x[1]>n.x[1];
}
bool cmp3(num m,num n){
	return m.x[2]>m.x[2];
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x[1]>>a[i].x[2]>>a[i].x[3];
		a[i].id[1]=1;a[i].id[2]=2;a[i].id[3]=3;
		
		if(a[i].x[1]<a[i].x[2]){
			swap(a[i].x[1],a[i].x[2]);
			swap(a[i].id[1],a[i].id[2]);
		}if(a[i].x[1]<a[i].x[3]){
			swap(a[i].x[1],a[i].x[3]);
			swap(a[i].id[1],a[i].id[3]);
		}if(a[i].x[2]<a[i].x[3]){
			swap(a[i].x[2],a[i].x[3]);
			swap(a[i].id[2],a[i].id[3]);
		}
	}
	sort(a+1,a+n+1,cmp);
	int c[4]={};
	int ans=0,ans2=0,ans3=0,ans4=0,ans5=0,ans6=0;
	for(int i=1;i<=n;i++){
		if(c[a[i].id[1]]==n/2){
			if(a[i].x[2]==a[i].x[3]){
				if(c[a[i].id[2]]<c[a[i].id[3]])c[a[i].id[2]]++;
				else c[a[i].id[3]]++;
			}ans+=a[i].x[2];
		}
		else if(c[a[i].id[2]]==n/2){
			c[a[i].id[1]]++;
			ans+=a[i].x[1];
		}
		else{
			if(a[i].x[1]>a[i].x[2]){
				c[a[i].id[1]]++;
				ans+=a[i].x[1];
			}else if(a[i].x[1]<a[i].x[2]){
				c[a[i].id[2]]++;
				ans+=a[i].x[2];
			}else{
				if(c[a[i].id[2]]<c[a[i].id[1]])c[a[i].id[2]]++;
				else c[a[i].id[1]]++;
				ans+=a[i].x[2];
			}
		}
	}
	c[1]=c[2]=c[3]=0;
	for(int i=n;i>=1;i--){
		if(c[a[i].id[1]]==n/2){
			if(a[i].x[2]==a[i].x[3]){
				if(c[a[i].id[2]]<c[a[i].id[3]])c[a[i].id[2]]++;
				else c[a[i].id[3]]++;
			}
			ans2+=a[i].x[2];
		}
		else if(c[a[i].id[2]]==n/2){
			c[a[i].id[1]]++;
			ans2+=a[i].x[1];
		}
		else{
			if(a[i].x[1]>a[i].x[2]){
				c[a[i].id[1]]++;
				ans2+=a[i].x[1];
			}else if(a[i].x[1]<a[i].x[2]){
				c[a[i].id[2]]++;
				ans2+=a[i].x[2];
			}else{
				if(c[a[i].id[2]]<c[a[i].id[1]])c[a[i].id[2]]++;
				else c[a[i].id[1]]++;
				ans2+=a[i].x[2];
			}
		}
	}
	ans3=ans,ans4=ans2;
	
	sort(a+1,a+n+1,cmp2);
	c[1]=c[2]=c[3]=0;
	ans=ans2=0;
	for(int i=1;i<=n;i++){
		if(c[a[i].id[1]]==n/2){
			if(a[i].x[2]==a[i].x[3]){
				if(c[a[i].id[2]]<c[a[i].id[3]])c[a[i].id[2]]++;
				else c[a[i].id[3]]++;
			}ans+=a[i].x[2];
		}
		else if(c[a[i].id[2]]==n/2){
			c[a[i].id[1]]++;
			ans+=a[i].x[1];
		}
		else{
			if(a[i].x[1]>a[i].x[2]){
				c[a[i].id[1]]++;
				ans+=a[i].x[1];
			}else if(a[i].x[1]<a[i].x[2]){
				c[a[i].id[2]]++;
				ans+=a[i].x[2];
			}else{
				if(c[a[i].id[2]]<c[a[i].id[1]])c[a[i].id[2]]++;
				else c[a[i].id[1]]++;
				ans+=a[i].x[2];
			}
		}
	}
	c[1]=c[2]=c[3]=0;
	for(int i=n;i>=1;i--){
		if(c[a[i].id[1]]==n/2){
			if(a[i].x[2]==a[i].x[3]){
				if(c[a[i].id[2]]<c[a[i].id[3]])c[a[i].id[2]]++;
				else c[a[i].id[3]]++;
			}
			ans2+=a[i].x[2];
		}
		else if(c[a[i].id[2]]==n/2){
			c[a[i].id[1]]++;
			ans2+=a[i].x[1];
		}
		else{
			if(a[i].x[1]>a[i].x[2]){
				c[a[i].id[1]]++;
				ans2+=a[i].x[1];
			}else if(a[i].x[1]<a[i].x[2]){
				c[a[i].id[2]]++;
				ans2+=a[i].x[2];
			}else{
				if(c[a[i].id[2]]<c[a[i].id[1]])c[a[i].id[2]]++;
				else c[a[i].id[1]]++;
				ans2+=a[i].x[2];
			}
		}
	}
	ans5=ans,ans6=ans2;
	
	sort(a+1,a+n+1,cmp3);
	c[1]=c[2]=c[3]=0;
	ans=ans2=0;
	for(int i=1;i<=n;i++){
		if(c[a[i].id[1]]==n/2){
			if(a[i].x[2]==a[i].x[3]){
				if(c[a[i].id[2]]<c[a[i].id[3]])c[a[i].id[2]]++;
				else c[a[i].id[3]]++;
			}ans+=a[i].x[2];
		}
		else if(c[a[i].id[2]]==n/2){
			c[a[i].id[1]]++;
			ans+=a[i].x[1];
		}
		else{
			if(a[i].x[1]>a[i].x[2]){
				c[a[i].id[1]]++;
				ans+=a[i].x[1];
			}else if(a[i].x[1]<a[i].x[2]){
				c[a[i].id[2]]++;
				ans+=a[i].x[2];
			}else{
				if(c[a[i].id[2]]<c[a[i].id[1]])c[a[i].id[2]]++;
				else c[a[i].id[1]]++;
				ans+=a[i].x[2];
			}
		}
	}
	c[1]=c[2]=c[3]=0;
	for(int i=n;i>=1;i--){
		if(c[a[i].id[1]]==n/2){
			if(a[i].x[2]==a[i].x[3]){
				if(c[a[i].id[2]]<c[a[i].id[3]])c[a[i].id[2]]++;
				else c[a[i].id[3]]++;
			}
			ans2+=a[i].x[2];
		}
		else if(c[a[i].id[2]]==n/2){
			c[a[i].id[1]]++;
			ans2+=a[i].x[1];
		}
		else{
			if(a[i].x[1]>a[i].x[2]){
				c[a[i].id[1]]++;
				ans2+=a[i].x[1];
			}else if(a[i].x[1]<a[i].x[2]){
				c[a[i].id[2]]++;
				ans2+=a[i].x[2];
			}else{
				if(c[a[i].id[2]]<c[a[i].id[1]])c[a[i].id[2]]++;
				else c[a[i].id[1]]++;
				ans2+=a[i].x[2];
			}
		}
	}
	
	cout<<max(max(max(ans3,ans4),max(ans,ans2)),max(ans5,ans6))<<"\n";
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=3;j++){
//			cout<<a[i].x[j]<<" "<<a[i].id[j]<<" ";
//		}cout<<"\n";
//	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>t;
	while(t--)solve();
}