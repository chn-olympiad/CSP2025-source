#include<bits/stdc++.h>
using namespace std;
map<string,string>a;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		string s,s1;
		cin>>s>>s1;
		a[s]=s1;
	}
	while(q--){
		int ans=0;
		string s,s1;
		cin>>s>>s1; 
		int jl1=-1,jl2=-1;
		int ls=s.size()-1,ls1=s1.size()-1;
		if(ls!=ls1){
			printf("0\n");
			continue;
		}
		for(int i=0;i<=ls;i++){
			if(s[i]!=s1[i]){
				if(jl1==-1)jl1=i;
				jl2=i;
			}
		}
		if(jl1==-1){
			printf("0\n");
			continue;
		}
		string que="",que1="";
		for(int i=jl1;i<=jl2;i++)
			que+=s[i],que1+=s1[i];
		string qian="",hou="",qian1="",hou1="";
//		cout<<que<<' '<<que1<<"\n";
		if(a[que]==que1)ans++;
		for(int i=jl1-1;i>=0;i--)
		{
//			cout<<i<<' ';
			qian=s[i]+qian;
			qian1=s1[i]+qian1;
//			cout<<qian<<' '<<qian1;
			for(int j=jl2+1;j<=ls;j++){
				hou=hou+s[j];
				hou1=hou1+s1[j];
				if(a[qian+que+hou]==qian1+que1+hou1)ans++;
//				cout<<qian+que+hou<<' '<<a[qian+que+hou]<<' '<<qian1+que1+hou1<<"\n";		
			}
//			cout<<"\n";
			hou="";
			hou1="";
		}
		printf("%d\n",ans);
	}
	return 0;
}
