#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans;
int s[1005],c[1005];
string st;
int tmp[1005],vis[1005];
void fun(int pos){
	if(pos>n){
		/*for(int i=1;i<=n;i++){
			cout<<tmp[i]<<" ";
		}
		cout<<"\n";*/
		int cnt=0,an=0;
		for(int i=1;i<=n;i++){
			int k=tmp[i];
			if(cnt>=c[k]){
				cnt++;
				continue;
			}
			else{
				if(s[i]==0){
					cnt++;
				}
				else{
					an++;
				}
			}
		}
		if(an>=m){
			ans++;
		}	
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			tmp[pos]=i;
			fun(pos+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%1d",&s[i]);
	}
	/*cin>>st;
	int len=st.size();
	int fl=0;
	for(int i=0;i<len;i++){
		s[i+1]=st[i]-'0';
		if(s[i+1]!=1){
			fl=1;
		}
	}*/
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	if(n<=18){
		fun(1);
		printf("%d",ans);
	}
	else{
		printf("0");
	}
	return 0;
}
/*
3 2
101
1 1 2
*/
