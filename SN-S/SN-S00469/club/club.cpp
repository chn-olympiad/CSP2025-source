//王培翔 SN-S00496 雁塔第一学校
#include<bits/stdc++.h>
using namespace std;
int n,t,ans;
struct people{
	int f,s,t;
	int s1,s2,s3;	
}a[100005];
int t1[1000005],q;
int t2[1000005],p;
bool cmp(int x,int y){
    return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.in","w",stdout)
   	cin>>t;
	while(t--){ 
    	ans=0;
    	cin>>n;
   	    for(int i=1;i<=n;i++){
    		cin>>a[i].f>>a[i].s>>a[i].t;
		}
		//B特性
		int cnt=0,cnn=0;	
		for(int i=1;i<=n;i++){
			if(a[i].f>a[i].s){
				cnt++;
				t1[++q]=a[i].f;
			}else{
				cnn++;
				t2[++p]=a[i].s;
			}
		}
		if(cnt>(n/2)){
			sort(t1+1,t1+q+1,cmp);
			for(int i=1;i<=(n/2);i++){
				ans+=a[i].f;
			}
			for(int i=(n/2)+1;i<=n;i++){
				ans+=a[i].s;
			}
		}else if(cnn>(n/2)){
			sort(t1+1,t1+q+1,cmp);
			for(int i=1;i<=(n/2);i++){
				ans+=a[i].s;
			}
			for(int i=(n/2)+1;i<=n;i++){
				ans+=a[i].f;
			}
		}else{
			for(int i=1;i<=q;i++){
				ans+=a[i].f;
			}
			for(int i=q+1;i<=p;i++){
				ans+=a[i].s;
			}
		}		
		cout<<ans<<'\n';
	}
	
	return 0;
}
