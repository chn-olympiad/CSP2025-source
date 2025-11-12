//SN-J00787  王煜曼 
#include<bits/stdc++.h>
using namespace std;
int n,a[5005],cnt,z=0;
string s[5005];
bool check(int l,int r)
{
	int qq=0;
	int maxx=-1;
	int ans=0;
	for(int i=l;i<=r;i++){
		maxx=max(maxx,a[i]);
		ans+=a[i];
	} 
	int lang=maxx*2;
	int cha=1;

	if(ans>lang)
	{
		
		for(int j=l;j<=r;j++){
			s[++z][j]=a[j];
			//cout<<a[j]<<' ';
		}
		//cout<<endl;
		cha=ans-lang;
		for(int i=l;i<=r;i++) if(a[i]<cha)
		{
			//cnt++;
			for(int j=l;j<=r;j++) if(j!=i){
			s[++z][j]=a[j]; //cout<<a[j]<<' ';
			}
			//cout<<endl;	
		 } 
		 return 1;
	 } 
	 return 0;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	//增加的岗位
	for(int q=3;q<=n;q++){
		//起始
		for(int i=1;i<=n-q+1;i++) {
			//便利选择
			//for(int l=i;l<=n-q;l++) {
			int l=i;
			int r=l+q-1;
			if(check(a[l],a[r])) cnt++;
			//if(check(a[l],a[r])) cnt++;
			//}
		}	
	} 
	/*int mp=z;
	for(int i=1;i<=z;i++)
		for(int j=i;j<=z;j++) {
			cout<<s[i]<<endl;
			int lo=0;
			for(int p=0;p<=max(s[i].size(),s[j].size());p++)
				if(s[i][p]==s[j][p]) lo++;
			if(lo==max(s[i].size(),s[j].size())) mp--;
		}*/
	printf("%d",cnt);
	return 0;
}
/*
5 
1 2 3 4 5
*/
