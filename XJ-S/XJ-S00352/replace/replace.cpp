#include<bits/stdc++.h>
using namespace std;
int n,q;
int s1[1005][2005],s2[1005][2005],len[1005],k[1005];
string s11[1005],s22[1005],sx,sy;
char s33[1005][2005],s44[1005][2005],stx[2005],sty[2005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s11[i]>>s22[i];
		len[i]=s11[i].length();
		int st=0,ed=len[i]-1;
		
//		cout<<st<<' '<<ed<<' '<<s11[i][3]<<endl;
//		cout<<s22[i]-s11[i]<<endl;
		while(s11[i][st]==s22[i][st])st++;
		while(s11[i][ed]==s22[i][ed])ed--;
		len[i]=ed-st+1;
		k[i]=st;
		for(int j=st;j<=ed;j++){
			s33[i][j-st]=s11[i][j];
			s44[i][j-st]=s22[i][j];
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<s33[i]<<' '<<s44[i]<<endl;
//	}
	while(q--){
		cin>>sx>>sy;
		int le=sy.length();
		int st=0,ed=le-1,ans=0;
		while(sx[st]==sy[st])st++;
		while(sx[ed]==sy[ed])ed--;
		for(int j=st;j<=ed;j++){
			stx[j-st]=sx[j];
			sty[j-st]=sy[j];
		}
//		cout<<stx<<' '<<sty<<endl;
		for(int i=1;i<=n;i++){
			if(le-1<k[i]+len[i]-1)continue;
//			cout<<le<<' '<<k[i]<<' '<<len[i]<<endl;
			
			if(strcmp(s33[i],stx)==0&&strcmp(s44[i],sty)==0)ans++;
		}
		cout<<ans<<endl;
//		cout<<st<<' '<<ed<<' '<<s11[i][3]<<endl;
//		cout<<s22[i]-s11[i]<<endl;
		
	}
	
//	for(int i=1;i<=n;i++){
//		printf("%s\n",s1[i]+1);
//	}
	
	return 0;
}
