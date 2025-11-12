#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n;
ll a[114514][14];
ll st[14];
ll ans1,ans2,ans3,ans,op;
ll b[14][114514];
ll cnt1,cnt2,cnt3;
int x,y,z;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//ios::sync_with.stdio(0),cin.tie(0),cout.tie(0); 
	 //scanf("%lf",&t);
	cin>>t;
	while(t--){
		ans=0;ans1=0;ans2=0;ans3=0;op=0;
		cnt1=0;cnt2=0;cnt3=0;
		memset(st,0,sizeof st);
    
    //scanf("%lf",&n);
		cin>>n;
		for(int i=1;i<=n;i++){
		/*	scanf("%lf%lf%lf",&x,&y,&z);
			a[i][1]=x;
			a[i][2]=y;
			a[i][3]=z;*/
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			
		  if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
				st[1]++;
				b[1][++cnt1]=a[i][1]-max(a[i][2],a[i][3]);
				ans1+=a[i][1];
			}
			else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
				st[2]++;
				b[2][++cnt2]=a[i][2]-max(a[i][1],a[i][3]);
				ans2+=a[i][2];
			} 
			else if(a[i][3]>a[i][1]&&a[i][3]>a[i][2]){
				st[3]++;
				b[3][++cnt3]=a[i][3]-max(a[i][1],a[i][2]);
				ans3+=a[i][3];
			}
			else
		  	op+=max(a[i][1],max(a[i][2],a[i][3]));  	  
	  }	
	  
	  //sort(b[2]+1,b[2]+cnt2);
		ans=ans1+ans2+ans3+op;
		
		if(st[1]>n/2){
			sort(b[1]+1,b[1]+cnt1+1);
			for(int i=1;i<=cnt1-n/2;i++)
				ans-=b[1][i]; 
		}
		else if(st[2]>n/2){
			sort(b[2]+1,b[2]+cnt2+1);
    	for(int i=1;i<=cnt2-n/2;i++)
     	 ans-=b[2][i];
		}
		else if(st[3]>n/2){
			sort(b[3]+1,b[3]+cnt3+1);
			for(int i=1;i<=cnt3-n/2;i++)
			  ans-=b[3][i];
		}
	  //cout<<cnt1<<' '<<cnt2<<" "<<cnt3<<' '<<op<<'\n'; 
		cout<<ans<<'\n';
  }
  
	return 0;
}
