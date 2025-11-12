#include<bits/stdc++.h>
using namespace std;
int array[100000][3];
int da[100000],zhong[100000],cha[100000];
int c1[100000],c2[100000],c3[100000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int ans=0,a=0,b=0,c=0;
		for(int i=0;i<100000;i++){
			for(int j=0;j<3;j++){
				array[i][j]=0;
			}
			da[i]=0;
			zhong[i]=0;
			cha[i]=0;
			c1[i]=0;
			c2[i]=0;
			c3[i]=0;
		}
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>array[i][j];
			}
		}
		for(int i=0;i<n;i++){
			da[i]=max(max(array[i][0],array[i][1]),array[i][2]);
			zhong[i]=array[i][0]+array[i][1]+array[i][2]-max(max(array[i][0],array[i][1]),array[i][2])-min(min(array[i][0],array[i][1]),array[i][2]);
			c1[i]=array[i][0];
			c2[i]=array[i][1];
			c3[i]=array[i][2];
			cha[i]=da[i]-zhong[i];
		}
		for(int i=0;i<n*n;i++){
			if(cha[i]>cha[i+1]){
				int z=cha[i];
				cha[i]=cha[i+1];
				cha[i+1]=z;
			}
		}
		for(int i=0;i<n;i++){
			if(da[i]==c1[i]){
				a++;
			}if(da[i]==c2[i]){
				b++;
			}if(da[i]==c3[i]){
				c++;
			}
		}
		for(int i=0;i<n;i++){
			ans+=da[i];
		}
		if(a<=n/2&&b<=n/2&&c<=n/2){
			cout<<ans<<endl;
		}else if(a>n/2){
			for(int i=0;i<(a-n/2);i++){
				ans-=cha[i];
			}
			cout<<ans<<endl;
		}else if(b>n/2){
			for(int i=0;i<(b-n/2);i++){
				ans-=cha[i];
			}
			cout<<ans<<endl;
		}else if(c>n/2){
			for(int i=0;i<(c-n/2);i++){
				ans-=cha[i];
			}
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
