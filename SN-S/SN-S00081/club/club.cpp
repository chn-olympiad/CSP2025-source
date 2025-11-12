//刘睿  SN-S00081  西安铁一中滨河高级中学
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
struct nem{
	int a1;
	int a2;
	int a3;
};
long long t,n,ans,temp,num1,num2,num3;
int ye;
nem ren[100010];
bool used[100010];
bool cmp(nem ren1,nem ren2){
	return ren1.a1>ren2.a1;
}
void dfs(int q){
    if(q==0){
    	if(temp<ans)temp=ans;
		return ;
	}for(int i=1;i<=n;i++){
		if(!used[i]){
			int tem;
			if(num1==n/2){
				if(num2==n/2){
					tem=ren[i].a3;
				}else {
					if(num3==n/2)tem=ren[i].a2;
					else tem=max(ren[i].a2,ren[i].a3);
				}
			}else if(num2==n/2){
				if(num3==n/2)tem=ren[i].a1;
				else tem=max(ren[i].a1,ren[i].a3);
			}else if(num3==n/2){
				tem=max(ren[i].a1,ren[i].a2);
			}else {
		    	tem=max(ren[i].a1,max(ren[i].a2,ren[i].a3));
			}ans+=tem;
			if(tem==ren[i].a1)num1++;
			else if(tem==ren[i].a2)num2++;
			else num3++;
			used[i]=1;
			dfs(q-1);
			used[i]=0;
			ans-=tem;
			if(tem==ren[i].a1)num1--;
			else if(tem==ren[i].a2)num2--;
			else num3--;
		}
	}return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int j=1;j<=t;j++){
		temp=0;
		cin>>n;
		int ling=0;
		for(int i=1;i<=n;i++){
			cin>>ren[i].a1>>ren[i].a2>>ren[i].a3;
			if(ren[i].a2==0&&ren[i].a3==0)ling++;
		}if(ling!=n)dfs(n);
		else{
		    sort(ren+1,ren+1+n,cmp);
			temp=0;
			for(int i=1;i<=n/2;i++){
				temp+=ren[i].a1;
			}
		}
		cout<<temp<<endl;
	}return 0;
}
