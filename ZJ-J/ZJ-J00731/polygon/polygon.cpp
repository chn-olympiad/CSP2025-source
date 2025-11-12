#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,t,w,bao,mid,ans,a[6000],ma,num,b[6000],j,i[30];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	ma=0;
	for(int i=1;i<=n;i++) cin>>a[i],ma=max(ma,a[i]);
	if(ma==1){
		int i=0;
		b[1]=1;
		for(i=2;i<=n;i++) b[i]=b[i-1]*i,b[i]%=mod;
		for(i=3;i<=n;i++){
			ans=1;
			for(j=0;j<i;j++) ans*=(n-j),ans%=mod;
			ans/=b[i];
			num+=ans;num%=mod;
		}
		cout<<num;
		return 0;
	}
	if(n<=20){
		for(i[1]=!(1>n);i[1]>=0;i[1]--)
			for(i[2]=!(2>n);i[2]>=0;i[2]--)
				for(i[3]=!(3>n);i[3]>=0;i[3]--)
					for(i[4]=!(4>n);i[4]>=0;i[4]--)
						for(i[5]=!(5>n);i[5]>=0;i[5]--)
							for(i[6]=!(6>n);i[6]>=0;i[6]--)
								for(i[7]=!(7>n);i[7]>=0;i[7]--)
									for(i[8]=!(8>n);i[8]>=0;i[8]--)
										for(i[9]=!(9>n);i[9]>=0;i[9]--)
											for(i[10]=!(10>n);i[10]>=0;i[10]--)
												for(i[11]=!(11>n);i[11]>=0;i[11]--)
													for(i[12]=!(12>n);i[12]>=0;i[12]--)
														for(i[13]=!(13>n);i[13]>=0;i[13]--)
															for(i[14]=!(14>n);i[14]>=0;i[14]--)
																for(i[15]=!(15>n);i[15]>=0;i[15]--)
																	for(i[16]=!(16>n);i[16]>=0;i[16]--)
																		for(i[17]=!(17>n);i[17]>=0;i[17]--)
																			for(i[18]=!(18>n);i[18]>=0;i[18]--)
																				for(i[19]=!(19>n);i[19]>=0;i[19]--)
																					for(i[20]=!(10>n);i[20]>=0;i[20]--){
																						int x=0;
																						for(j=1;j<=20;j++) x+=i[j];
																						if(x>=3&&a[1]*i[1]+a[2]*i[2]+a[3]*i[3]+a[4]*i[4]+a[5]*i[5]+a[6]*i[6]+a[7]*i[7]+a[8]*i[8]+a[9]*i[9]+a[10]*i[10]+a[11]*i[11]+a[12]*i[12]+a[13]*i[13]+a[14]*i[14]+a[15]*i[15]+a[16]*i[16]+a[17]*i[17]+a[18]*i[18]+a[19]*i[19]+a[20]*i[20]>2*max({a[1]*i[1],a[2]*i[2],a[3]*i[3],a[4]*i[4],a[5]*i[5],a[6]*i[6],a[7]*i[7],a[8]*i[8],a[9]*i[9],a[10]*i[10],a[11]*i[11],a[12]*i[12],a[13]*i[13],a[14]*i[14],a[15]*i[15],a[16]*i[16],a[17]*i[17],a[18]*i[18],a[19]*i[19],a[20]*i[20]})) ans++,ans%=mod;
																					}
																						
		cout<<ans;
		return 0;
	}
}
