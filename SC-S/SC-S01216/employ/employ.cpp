#include<bits/stdc++.h>
using namespace std;
int t1,n,m,c[505],nn[505]/*字符转数字*/,cha[505],cha1[505];//差分;
string s;
long long ans,cishu;
/*static void cheng(int aa,int bb){
	int aaa[505],bbb[505],ccc[1010],aaaa=1,bbbb=1;
	while(aa!=0){
		 aaa[aaaa++]=aa%10;
		 aa/=10;
	}
	while(bb!=0){
		 bbb[bbbb++]=bb%10;
		 bb/=10;
	}
	for(int aaaaa=aaaa;aaaaa>0;aaaaa--){
		int x=0;
			for(int bbbbb=bbbb;bbbbb>0;bbbb--){
			ccc[aaaaa+bbbbb-1]=(ccc[bbbbb]+x+aaa[aaaaa]*bbb[bbbbb])/10;
			int x=(aaa[aaaaa]*bbb[bbbbb]+ccc[bbbbb])%10;
		} 	
	} 
	while(ccc[aaaa+bbbb]==0&&aaaa+bbbb>0)aaaa--;
	for(int cccc=aaaa+bbbb;cccc>=1;cccc--){
		cout<<ccc[cccc];
	}
}*/
int check(int a){
	int ansss;
	for(int f=1;f<=a;f++){
		ansss+=cha[f]; 
	} 
	return ansss;
} 
static long long jiecheng(int xx){
	int aa[505];
	aa[1]=1;
	aa[2]=2;
	for(int ii=3;ii<=xx;ii++){
		aa[ii]=aa[ii-1]*aa[ii-2];
		if(aa[xx])return aa[xx];
	}
}
static void zuhe(long long x){
	//x=jiecheng(s.length())/cheng(jiecheng(t1),jiecheng(s.length-t1));
	x=jiecheng(s.length())/(jiecheng(t1)*jiecheng(s.length()-t1));
}
static void dfs(){
	int peo=0;
	for(int j=1;j<=n;j++){
		if(check(j)>=0&&nn[j]==1){
			peo++;
		}
			if(check(j)<0||nn[j]==0){
			cha[j]--; 
		}
	}
	if(peo>=m){
		ans++;
		return;
	}
}
int main(){
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	zuhe(cishu);
	nn[0]=1;
	for(int i=1;i<=n;i++){
		nn[i]=s[i]-'0';
		if(nn[i]==1)t1++;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		cha[i]=c[i]-c[i-1];
		cha1[i]=cha[i];
	}
	sort(nn+1,nn+n+1);
	for(int i=1;i<=n;i++){
	cout<<nn[i];
	}
	for(int i=1;i<=cishu;i++){
		dfs(); 
		for(int j=1;j<=n;j++){
			cha[i]=cha1[i]; 
		for(int k=n;n>=1;k--){
			if(nn[k]!=1||nn[k-1]!=0)continue;
			int kk=nn[k];
			nn[k]=nn[k-1];
			nn[k-1]==kk;
			break;	
		}	
			
			
			
			
			
			/*全组合!!!!!!*/ 
		}
	}
	cout<<ans%998224353;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
} 