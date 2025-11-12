#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,cnt[5],ct,bcnt[5],ans;
int sum,ansum;//dfs
struct node{
	int x,y,z,o;
}a[100005];
struct nope{
	int x,y;
}b[100005];
bool cmp(node q,node w){
	return max(max(q.x,q.y),q.z)>max(max(w.x,w.y),w.z);
}
bool bbcmp(nope q,nope w){
	return max(q.x,q.y)>max(w.x,w.y);
}
void dfs(int step){
//	cout<<step<<" "<<sum<<"\n";
	if(step==ct+1){
		ansum=max(ansum,sum);
		return ;
	}
	if(bcnt[1]+1<=ct/2){
		bcnt[1]++;
		sum+=b[step].x;
		dfs(step+1);
		bcnt[1]--;
		sum-=b[step].x;
	}
	if(bcnt[2]+1<=ct/2){
		bcnt[2]++;
		sum+=b[step].y;
		dfs(step+1);
		bcnt[2]--;
		sum-=b[step].y;
	}
}


int ssum=0;
void baoli(int step){
//	cout<<step<<" "<<ssum<<"\n";
	if(step==n+1){
		ans=max(ans,ssum);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]+1<=n/2){
			cnt[i]++;
			if(i==1){
				ssum+=a[step].x;
			}
			if(i==2){
				ssum+=a[step].y;
			}
			if(i==3){
				ssum+=a[step].z;
			}
			baoli(step+1);
			cnt[i]--;
			if(i==1){
				ssum-=a[step].x;
			}
			if(i==2){
				ssum-=a[step].y;
			}
			if(i==3){
				ssum-=a[step].z;
			}
		}
	}
}

void solve(){
	cnt[1]=cnt[2]=cnt[3]=0;
	ct=0;
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
		if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
			a[i].o=1;
		}
		else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
			a[i].o=2;
		}
		else{
			a[i].o=3;
		}
	}
	sort(a+1,a+n+1,cmp);
	if(n<=10){
		baoli(0);
		cout<<ans<<"\n";
		return ;
	}
	int flag=0,x=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
//			cout<<cnt[j]<<" ";
			if(cnt[j]==n/2){
				flag=j;
				x=i;
				break;
			}
		}
//		cout<<"\n";
		if(flag!=0){
			break;
		}
		cnt[a[i].o]++;
		ans+=max(max(a[i].x,a[i].y),a[i].z);
	}
//	cout<<flag<<" "<<x<<"falg$&x\n";
	if(flag==1){
		for(int i=x;i<=n;i++){
			ct++;
			b[ct].x=a[i].y;
			bcnt[1]=cnt[2];
			b[ct].y=a[i].z;
			bcnt[2]=cnt[3];
		}
	}
	if(flag==2){
		for(int i=x;i<=n;i++){
			ct++;
			b[ct].x=a[i].x;
			bcnt[1]=cnt[1];
			b[ct].y=a[i].z;
			bcnt[2]=cnt[3];
		}
	}
	if(flag==3){
		for(int i=x;i<=n;i++){
			ct++;
			b[ct].x=a[i].x;
			bcnt[1]=cnt[1];
			b[ct].y=a[i].y;
			bcnt[2]=cnt[2];
		}
	}
	sort(b+1,b+ct+1,bbcmp);
	if(n<=30){
		sum=0;
//		cout<<ct<<"ct\n";
		dfs(0);
		ans+=ansum;
		cout<<ans<<"\n";
		return ;
	} 
	for(int i=1;i<=ct;i++){
		if(bcnt[1]>n/2){
			ans+=b[i].y;
			bcnt[2]++;
			continue;
		}
		if(bcnt[2]>n/2){
			ans+=b[i].x;
			bcnt[1]++;
			continue;
		}
		if(b[i].x>b[i].y){
			ans+=b[i].x;
			bcnt[1]++;
		}else{
			ans+=b[i].y;
			bcnt[2]++;
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}