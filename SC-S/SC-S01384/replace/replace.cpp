#include<bits/stdc++.h>
using namespace std;
struct m{
	char a[100007],b[100007];
}mp[2007];
int n,q,ans,t;
char a[100007],b[100007];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		strcpy(mp[i].a,a);
		strcpy(mp[i].b,b);
	} 
	while(q--){
		ans=0;
		cin>>a>>b;
		for(int i=0;i<strlen(a);i++)
			for(int j=i;j<strlen(a);j++){
				char temp[100007]={};
				strcpy(temp,a);
				char y[100007]={};
				for(int k=i;k<=j;k++)
					y[k-i]=a[k];
				for(int k=1;k<=n;k++){
					if(strcmp(y,mp[k].a)==0){
						strcpy(y,mp[k].b);
						break;
					}
				}
				for(int k=i;k<=j;k++)
					a[k]=y[k-i];
				if(strcmp(a,b)==0)
					ans++;
				strcpy(a,temp);
			}
		cout<<ans<<endl;
	}
	return 0;
}