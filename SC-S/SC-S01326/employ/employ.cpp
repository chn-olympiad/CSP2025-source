#include<bits/stdc++.h>
using namespace std;
string s;
int p[510],f[510],me[510],n,m,ans;
void abc(int day,int sb[],int sx[]){
//	for(int i=1;i<day;i++) cout<<sx[i]+1<<" ";															
//	for(int i=1;i<day;i++) cout<<"sb["<<i<<"]="<<sb[i]<<" ";
//	cout<<endl;

	int tmp=0;
//	for(int i=0;i<n;i++){
//		if(f[i]==0){
//			if(sb[day-1]>=p[i]) tmp++;
//		}
//	}
	if((n-sb[day-1]-tmp)<m) return;
	if(day>n){
		if((n-sb[day-1])>=m){
			ans++;
			ans%=998244353;
		//for(int i=1;i<=n;i++) cout<<sb[i]<<" ";
		//	cout<<"\n";
		}
		return;
	}

														
	for(int i=0;i<n;i++){
		if(f[i]==0){
			if(sb[day-1]>=p[i] || s[day-1]=='0'){
				sb[day]=sb[day-1]+1;
				f[i]=1;
				sx[day]=i;
				abc(day+1,sb,sx);
				f[i]=0;
	
			}else{
				sb[day]=sb[day-1];
				f[i]=1;
				sx[day]=i;
				abc(day+1,sb,sx);
				f[i]=0;
			}
			
		}
			
	}
}
int main(){
	ios::sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++) cin>>p[i];
	int a[510]={0,0},b[510];
	abc(1,a,b);
	cout<<ans;
	return 0;
}