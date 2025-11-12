#include<bits/stdc++.h>
using namespace std;
struct note{
	int a,b,c,i;
	int t1,t2,t3;
};
bool cmp(note a,note b){
	return a.b<b.b || (a.b==b.b && a.a<b.a);
}
note v[100010];
void solve(){
	int n,i,j,t;
	int cnt[3]={0,0,0},sum=0;
	int a,b,c,t1,t2,t3;
	cin>>n;
	for(i=0;i<n;i++){
		t1=1;t2=2;t3=3;
		scanf("%d%d%d",&a,&b,&c);
		if(b<c){swap(b,c);swap(t2,t3);}
		if(a<b){swap(a,b);swap(t1,t2);}
		if(b<c){swap(b,c);swap(t2,t3);}
		v[i].a=a;v[i].b=a-b;v[i].c=b-c;
		v[i].t1=t1;v[i].t2=t2;v[i].t3=t3;
		cnt[t1]++;
		sum+=a;
	}
	if(n==2){
		if(cnt[0]<=n/2 && cnt[1]<=n/2 && cnt[2]<=n/2) cout<<sum<<" \n";
		else{
			if(v[0].b<v[1].b) cout<<sum-v[0].b<<" \n";
			else cout<<sum-v[1].b<<" \n";
		}
		return;
	}
	else if(n==4){
		if(cnt[0]<=n/2 && cnt[1]<=n/2 && cnt[2]<=n/2) cout<<sum<<" \n";
		else{
			if(cnt[0]>n/2) t=0;
			else if(cnt[1]>n/2) t=1;
			else if(cnt[2]>n/2) t=2;
			note v2[50005];
			j=0;
			for(i=0;i<n;i++){
				if(v[i].t1==t){
					v2[j]=v[i];
					v2[j].i=i;
					j++;
				}
			}
			sort(v2,v2+j,cmp);
			if(cnt[t]==3){
				sum-=v[v2[0].i].b;
				cout<<sum<<" \n";
				return;
			}
			if(cnt[t]==4){
				sum-=v[v2[0].i].b;
				sum-=v[v2[1].i].b;
				cout<<sum<<" \n";
			}
		}
		return;
	}
	if(cnt[0]<=n/2 && cnt[1]<=n/2 && cnt[2]<=n/2) cout<<sum<<"\n";
	else{
		if(cnt[0]>n/2) t=0;
		else if(cnt[1]>n/2) t=1;
		else if(cnt[2]>n/2) t=2;
		note v2[50005];
		j=0;
		for(i=0;i<n;i++){
			if(v[i].t1==t){
				v2[j]=v[i];
				v2[j].i=i;
				j++;
			}
		}
		sort(v2,v2+j,cmp);
		int t2;
		for(i=0;i<=n/2;i++){
			v[v2[i].i].a-=v[v2[i].i].b;
			v[v2[i].i].b=-v[v2[i].i].b;
			v[v2[i].i].c-=v[v2[i].i].b;
			t2=v[v2[i].i].t1;
			v[v2[i].i].t1=v[v2[i].i].t2;
			v[v2[i].i].t2=t2;
			sum+=v[v2[i].i].b;
			cnt[v[v2[i].i].t1]++;
			cnt[v[v2[i].i].t2]--;
			if(cnt[t]==n/2) break;
		}
		cout<<sum<<"\n";
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t){
		solve();
		t--;
	}
	return 0;
}

