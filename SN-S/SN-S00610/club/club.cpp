#include<bits/stdc++.h>
using namespace std;
#define N 100001
int t,a[N][5];
int team[5];
bool ju[N];
struct edge{
	int a;
	int b;
};
edge t_one[N],t_two[N],t_three[N]; 
bool cmp(edge x,edge y){
	if(x.a<y.a)return true;
	return false;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		for(int i=1;i<=5;i++)
			team[i]=0;
		memset(ju,true,sizeof(ju));
		int n;
		cin>>n;
		int range=n/2;
		for(int i=1;i<=n;i++){
			int ma=0,s_ma;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				ma=max(ma,a[i][j]);
				if(ma==a[i][j])
					s_ma=j;
			}
			a[i][4]=ma;a[i][5]=s_ma;
			if(s_ma==1){
				t_two[i].a=a[i][1]-a[i][2];
				t_two[i].b=i;
				t_three[i].a=a[i][1]-a[i][3];
				t_three[i].b=i;
			}
			else if(s_ma==2){
				t_one[i].a=a[i][2]-a[i][1];
				t_one[i].b=i;
				t_three[i].a=a[i][2]-a[i][3];
				t_three[i].b=i;
			}
			else if(s_ma==3){
				t_two[i].a=a[i][3]-a[i][2];
				t_two[i].b=i;
				t_one[i].a=a[i][3]-a[i][1];
				t_one[i].b=i;
			}
		}
		sort(t_one+1,t_one+1+n,cmp);
		sort(t_two+1,t_two+1+n,cmp);
		sort(t_three+1,t_three+1+n,cmp);
		long long ans=0;
		for(int i=1;i<=n;i++){
			ans+=a[i][4];
			team[a[i][5]]++;
		}
		//for(int i=1;i<=n;i++)
		//	cout<<t_one[i].a<<" "<<t_one[i].b<<" "<<t_two[i].a<<" "<<t_two[i].b<<endl;
		int cnt1=1,cnt2=1;
		while(team[1]>range){
			//cout<<"y";
			while(t_two[cnt1].a==0)cnt1++;
			while(t_three[cnt2].a==0)cnt2++;
			//for(int i=1;i<=n;i++)if(t_one[i].a!=0)ju[t_one[i].b]=false;
			if(ju[t_two[cnt1].b]&&t_two[cnt1].a<t_three[cnt2].a){
				ans-=t_two[cnt1].a;
				ju[t_two[cnt1].b]=false;
				team[1]--;
				cnt1++;
				//cout<<"T1";
			}
			else if(ju[t_three[cnt2].b]){
				ans-=t_three[cnt2].a;
				ju[t_three[cnt2].b]=false;
				team[1]--;
				cnt2++;
				//cout<<"f1";
			}
		}
		while(team[2]>range){
			//cout<<"er";
			while(t_one[cnt1].a==0)cnt1++;
			while(t_three[cnt2].a==0)cnt2++;
			//for(int i=1;i<=n;i++)if(t_two[i].a!=0)ju[t_two[i].b]=false;
			if(ju[t_one[cnt1].b]&&t_one[cnt1].a<t_three[cnt2].a){
				ans-=t_one[cnt1].a;
				ju[t_one[cnt1].b]=false;
				team[2]--;
				cnt1++;//cout<<"T2";
			}
			else if(ju[t_three[cnt2].b]){
				ans-=t_three[cnt2].a;
				ju[t_three[cnt2].b]=false;
				team[2]--;
				cnt2++;//cout<<"f2"<<" "<<team[2]<<" ";
			}
		}
		while(team[3]>range){
			//cout<<"san";
			while(t_two[cnt1].a==0)cnt1++;
			while(t_one[cnt2].a==0)cnt2++;
			//for(int i=1;i<=n;i++)if(t_three[i].a!=0)ju[t_three[i].b]=false;
			if(ju[t_two[cnt1].b]&&t_two[cnt1].a<t_one[cnt2].a){
				ans-=t_two[cnt1].a;
				ju[t_two[cnt1].b]=false;
				team[3]--;
				cnt1++;//cout<<"T3";
			}
			else if(ju[t_one[cnt2].b]){
				ans-=t_one[cnt2].a;
				ju[t_one[cnt2].b]=false;
				team[3]--;
				cnt2++;//cout<<"f3";
			}
		}
		cout<<ans<<endl;
	}
		
	return 0;
}

