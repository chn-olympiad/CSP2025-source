#include <bits/stdc++.h>
using namespace std;
priority_queue <int> q1,q2,q3;
int s[10001][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int ans[101],o;
	o=t+1;
	while(t>0){
		int n,cnt=0;
		bool flag1=0;
		bool f[10001]={0};		
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i][1]>>s[i][2]>>s[i][3];
			q1.push(s[i][1]);
			q2.push(s[i][2]);
			q3.push(s[i][3]);
			if(s[i][1]==0&&s[i][2]==0||s[i][1]==0&&s[i][3]==0||s[i][2]==0&&s[i][3]==0){
				flag1=1;
			}
		}
		if(flag1){
			ans[t]=q1.top()+q2.top()+q3.top();
		}else{
			for(int i=1;i<=n/2;i++){
				int id;
				for(int j=1;j<=n/2;j++){
					if(s[j][1]==q1.top()){
						id=j;
					}
					if(s[id][1]<s[id][2]||s[id][1]<s[id][3]){
						q1.pop();
					}	
				}
				ans[t]+=q1.top();
				q1.pop();
				f[id]=1;
			}
			for(int i=1;i<=n/2;i++){
				int id;
				for(int j=1;j<=n/2;j++){
					if(s[j][2]==q2.top()){
						id=j;
					}
					if(s[id][2]<s[id][3]){
						q2.pop();
					}	
				}
				if(f[id]!=1){
					ans[t]+=q2.top();
					q2.pop();
					f[id]=1;					
				}else{
					q2.pop();
				}
			}
			for(int i=1;i<=n/2;i++){
				int id;
				for(int j=1;j<=n/2;j++){
					if(s[j][3]==q3.top()){
						id=j;
					}
				if(f[id]!=1){
					ans[t]+=q3.top();
					q3.pop();					
				}else{
					q3.pop();
				}
			}						
		}
		t--;
	}
	for(int i=o;i>=0;i--){
		cout<<ans[i];
	}
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

