#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,i,j,fl,s1,s2,s,ans,a[10001];
const int mod=998244353;
bool cmp(int h,int t){
	return h>t;
}
void s3(){
	int i1,i2,i3;
	for(i1=1;i1<=n;i1++)
		for(i2=i1+1;i2<=n;i2++)
			for(i3=i2+1;i3<=n;i3++)
				if(a[i1]+a[i2]+a[i3]>2*a[i1]) ans=(ans+1)%mod;
				else break;
}
void s4(){
	int i1,i2,i3,i4;
	for(i1=1;i1<=n;i1++)
		for(i2=i1+1;i2<=n;i2++)
			for(i3=i2+1;i3<=n;i3++)
				for(i4=i3+1;i4<=n;i4++)
					if(a[i1]+a[i2]+a[i3]+a[i4]>2*a[i1]) ans=(ans+1)%mod;
					else break;
}
void s5(){
	int i1,i2,i3,i4,i5;
	for(i1=1;i1<=n;i1++)
		for(i2=i1+1;i2<=n;i2++)
			for(i3=i2+1;i3<=n;i3++)
				for(i4=i3+1;i4<=n;i4++)
					for(i5=i4+1;i5<=n;i5++)
						if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]>2*a[i1]) ans=(ans+1)%mod;
						else break;
}
void s6(){
	int i1,i2,i3,i4,i5,i6;
	for(i1=1;i1<=n;i1++)
		for(i2=i1+1;i2<=n;i2++)
			for(i3=i2+1;i3<=n;i3++)
				for(i4=i3+1;i4<=n;i4++)
					for(i5=i4+1;i5<=n;i5++)
						for(i6=i5+1;i6<=n;i6++)
							if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]>2*a[i1]) ans=(ans+1)%mod;
							else break;
}
void s7(){
	int i1,i2,i3,i4,i5,i6,i7;
	for(i1=1;i1<=n;i1++)
		for(i2=i1+1;i2<=n;i2++)
			for(i3=i2+1;i3<=n;i3++)
				for(i4=i3+1;i4<=n;i4++)
					for(i5=i4+1;i5<=n;i5++)
						for(i6=i5+1;i6<=n;i6++)
							for(i7=i6+1;i7<=n;i7++)
								if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]>2*a[i1]) ans=(ans+1)%mod;
								else break;
}
void s8(){
	int i1,i2,i3,i4,i5,i6,i7,i8;
	for(i1=1;i1<=n;i1++)
		for(i2=i1+1;i2<=n;i2++)
			for(i3=i2+1;i3<=n;i3++)
				for(i4=i3+1;i4<=n;i4++)
					for(i5=i4+1;i5<=n;i5++)
						for(i6=i5+1;i6<=n;i6++)
							for(i7=i6+1;i7<=n;i7++)
								for(i8=i7+1;i8<=n;i8++)
									if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]>2*a[i1]) ans=(ans+1)%mod;
									else break;
}
void s9(){
	int i1,i2,i3,i4,i5,i6,i7,i8,i9;
	for(i1=1;i1<=n;i1++)
		for(i2=i1+1;i2<=n;i2++)
			for(i3=i2+1;i3<=n;i3++)
				for(i4=i3+1;i4<=n;i4++)
					for(i5=i4+1;i5<=n;i5++)
						for(i6=i5+1;i6<=n;i6++)
							for(i7=i6+1;i7<=n;i7++)
								for(i8=i7+1;i8<=n;i8++)
									for(i9=i8+1;i9<=n;i9++)
										if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]>2*a[i1]) ans=(ans+1)%mod;
										else break;
}
void s10(){
	int i1,i2,i3,i4,i5,i6,i7,i8,i9,i10;
	for(i1=1;i1<=n;i1++)
		for(i2=i1+1;i2<=n;i2++)
			for(i3=i2+1;i3<=n;i3++)
				for(i4=i3+1;i4<=n;i4++)
					for(i5=i4+1;i5<=n;i5++)
						for(i6=i5+1;i6<=n;i6++)
							for(i7=i6+1;i7<=n;i7++)
								for(i8=i7+1;i8<=n;i8++)
									for(i9=i8+1;i9<=n;i9++)
										for(i10=i9+1;i10<=n;i10++)
											if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]>2*a[i1]) ans=(ans+1)%mod;
											else break;
}
void s11(){
	int i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11;
	for(i1=1;i1<=n;i1++)
		for(i2=i1+1;i2<=n;i2++)
			for(i3=i2+1;i3<=n;i3++)
				for(i4=i3+1;i4<=n;i4++)
					for(i5=i4+1;i5<=n;i5++)
						for(i6=i5+1;i6<=n;i6++)
							for(i7=i6+1;i7<=n;i7++)
								for(i8=i7+1;i8<=n;i8++)
									for(i9=i8+1;i9<=n;i9++)
										for(i10=i9+1;i10<=n;i10++)
											for(i11=i10+1;i11<=n;i11++)
												if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]+a[i11]>2*a[i1]) ans=(ans+1)%mod;
												else break;
}
void s12(){
	int i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12;
	for(i1=1;i1<=n;i1++)
		for(i2=i1+1;i2<=n;i2++)
			for(i3=i2+1;i3<=n;i3++)
				for(i4=i3+1;i4<=n;i4++)
					for(i5=i4+1;i5<=n;i5++)
						for(i6=i5+1;i6<=n;i6++)
							for(i7=i6+1;i7<=n;i7++)
								for(i8=i7+1;i8<=n;i8++)
									for(i9=i8+1;i9<=n;i9++)
										for(i10=i9+1;i10<=n;i10++)
											for(i11=i10+1;i11<=n;i11++)
												for(i12=i11+1;i12<=n;i12++)
													if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]+a[i11]+a[i12]>2*a[i1]) ans=(ans+1)%mod;
													else break;
}
void s13(){
	int i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,i13;
	for(i1=1;i1<=n;i1++)
		for(i2=i1+1;i2<=n;i2++)
			for(i3=i2+1;i3<=n;i3++)
				for(i4=i3+1;i4<=n;i4++)
					for(i5=i4+1;i5<=n;i5++)
						for(i6=i5+1;i6<=n;i6++)
							for(i7=i6+1;i7<=n;i7++)
								for(i8=i7+1;i8<=n;i8++)
									for(i9=i8+1;i9<=n;i9++)
										for(i10=i9+1;i10<=n;i10++)
											for(i11=i10+1;i11<=n;i11++)
												for(i12=i11+1;i12<=n;i12++)
													for(i13=i12+1;i13<=n;i13++)
														if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]+a[i11]+a[i12]+a[i13]>2*a[i1]) ans=(ans+1)%mod;
														else break;
}
void s14(){
	int i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,i13,i14;
	for(i1=1;i1<=n;i1++)
		for(i2=i1+1;i2<=n;i2++)
			for(i3=i2+1;i3<=n;i3++)
				for(i4=i3+1;i4<=n;i4++)
					for(i5=i4+1;i5<=n;i5++)
						for(i6=i5+1;i6<=n;i6++)
							for(i7=i6+1;i7<=n;i7++)
								for(i8=i7+1;i8<=n;i8++)
									for(i9=i8+1;i9<=n;i9++)
										for(i10=i9+1;i10<=n;i10++)
											for(i11=i10+1;i11<=n;i11++)
												for(i12=i11+1;i12<=n;i12++)
													for(i13=i12+1;i13<=n;i13++)
														for(i14=i13+1;i14<=n;i14++)
															if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]+a[i11]+a[i12]+a[i13]+a[i14]>2*a[i1]) ans=(ans+1)%mod;
															else break;
}
void s15(){
	int i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,i13,i14,i15;
	for(i1=1;i1<=n;i1++)
		for(i2=i1+1;i2<=n;i2++)
			for(i3=i2+1;i3<=n;i3++)
				for(i4=i3+1;i4<=n;i4++)
					for(i5=i4+1;i5<=n;i5++)
						for(i6=i5+1;i6<=n;i6++)
							for(i7=i6+1;i7<=n;i7++)
								for(i8=i7+1;i8<=n;i8++)
									for(i9=i8+1;i9<=n;i9++)
										for(i10=i9+1;i10<=n;i10++)
											for(i11=i10+1;i11<=n;i11++)
												for(i12=i11+1;i12<=n;i12++)
													for(i13=i12+1;i13<=n;i13++)
														for(i14=i13+1;i14<=n;i14++)
															for(i15=i14+1;i15<=n;i15++)
																if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]+a[i11]+a[i12]+a[i13]+a[i14]+a[i15]>2*a[i1]) ans=(ans+1)%mod;
																else break;
}
void s16(){
	int i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,i13,i14,i15,i16;
	for(i1=1;i1<=n;i1++)
		for(i2=i1+1;i2<=n;i2++)
			for(i3=i2+1;i3<=n;i3++)
				for(i4=i3+1;i4<=n;i4++)
					for(i5=i4+1;i5<=n;i5++)
						for(i6=i5+1;i6<=n;i6++)
							for(i7=i6+1;i7<=n;i7++)
								for(i8=i7+1;i8<=n;i8++)
									for(i9=i8+1;i9<=n;i9++)
										for(i10=i9+1;i10<=n;i10++)
											for(i11=i10+1;i11<=n;i11++)
												for(i12=i11+1;i12<=n;i12++)
													for(i13=i12+1;i13<=n;i13++)
														for(i14=i13+1;i14<=n;i14++)
															for(i15=i14+1;i15<=n;i15++)
																for(i16=i15+1;i16<=n;i16++)
																	if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]+a[i11]+a[i12]+a[i13]+a[i14]+a[i15]+a[i16]>2*a[i1]) ans=(ans+1)%mod;
																	else break;
}
void s17(){
	int i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,i13,i14,i15,i16,i17;
	for(i1=1;i1<=n;i1++)
		for(i2=i1+1;i2<=n;i2++)
			for(i3=i2+1;i3<=n;i3++)
				for(i4=i3+1;i4<=n;i4++)
					for(i5=i4+1;i5<=n;i5++)
						for(i6=i5+1;i6<=n;i6++)
							for(i7=i6+1;i7<=n;i7++)
								for(i8=i7+1;i8<=n;i8++)
									for(i9=i8+1;i9<=n;i9++)
										for(i10=i9+1;i10<=n;i10++)
											for(i11=i10+1;i11<=n;i11++)
												for(i12=i11+1;i12<=n;i12++)
													for(i13=i12+1;i13<=n;i13++)
														for(i14=i13+1;i14<=n;i14++)
															for(i15=i14+1;i15<=n;i15++)
																for(i16=i15+1;i16<=n;i16++)
																	for(i17=i16+1;i17<=n;i17++)
																		if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]+a[i11]+a[i12]+a[i13]+a[i14]+a[i15]+a[i16]+a[i17]>2*a[i1]) ans=(ans+1)%mod;
																		else break;
}
void s18(){
	int i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,i13,i14,i15,i16,i17,i18;
	for(i1=1;i1<=n;i1++)
		for(i2=i1+1;i2<=n;i2++)
			for(i3=i2+1;i3<=n;i3++)
				for(i4=i3+1;i4<=n;i4++)
					for(i5=i4+1;i5<=n;i5++)
						for(i6=i5+1;i6<=n;i6++)
							for(i7=i6+1;i7<=n;i7++)
								for(i8=i7+1;i8<=n;i8++)
									for(i9=i8+1;i9<=n;i9++)
										for(i10=i9+1;i10<=n;i10++)
											for(i11=i10+1;i11<=n;i11++)
												for(i12=i11+1;i12<=n;i12++)
													for(i13=i12+1;i13<=n;i13++)
														for(i14=i13+1;i14<=n;i14++)
															for(i15=i14+1;i15<=n;i15++)
																for(i16=i15+1;i16<=n;i16++)
																	for(i17=i16+1;i17<=n;i17++)
																		for(i18=i17+1;i18<=n;i18++)
																			if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]+a[i11]+a[i12]+a[i13]+a[i14]+a[i15]+a[i16]+a[i17]+a[i18]>2*a[i1]) ans=(ans+1)%mod;
																			else break;
}
void s19(){
	int i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,i13,i14,i15,i16,i17,i18,i19;
	for(i1=1;i1<=n;i1++)
		for(i2=i1+1;i2<=n;i2++)
			for(i3=i2+1;i3<=n;i3++)
				for(i4=i3+1;i4<=n;i4++)
					for(i5=i4+1;i5<=n;i5++)
						for(i6=i5+1;i6<=n;i6++)
							for(i7=i6+1;i7<=n;i7++)
								for(i8=i7+1;i8<=n;i8++)
									for(i9=i8+1;i9<=n;i9++)
										for(i10=i9+1;i10<=n;i10++)
											for(i11=i10+1;i11<=n;i11++)
												for(i12=i11+1;i12<=n;i12++)
													for(i13=i12+1;i13<=n;i13++)
														for(i14=i13+1;i14<=n;i14++)
															for(i15=i14+1;i15<=n;i15++)
																for(i16=i15+1;i16<=n;i16++)
																	for(i17=i16+1;i17<=n;i17++)
																		for(i18=i17+1;i18<=n;i18++)
																			for(i19=i18+1;i19<=n;i19++)
																			if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]+a[i11]+a[i12]+a[i13]+a[i14]+a[i15]+a[i16]+a[i17]+a[i18]+a[i19]>2*a[i1]) ans=(ans+1)%mod;
																			else break;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) fl=1;
	}
	sort(a+1,a+n+1,cmp);
	if(n<=2) return cout<<0,0;
	if(!fl){
		for(i=3;i<=n;i++){
			s1=s2=1;
			for(j=1;j<=i;j++) s1=s1*j%mod;
			for(j=n;j>=n-i+1;j--) s2=s2*j%mod;
			ans=(ans%mod+s2/s1)%mod;
		}
		return cout<<ans%mod,0;
	}
	else{
		if(n==3){
			if(a[1]+a[2]+a[3]>2*a[1])
				return cout<<1,0;
		}
		if(n==4){
			s3();
			if(a[1]+a[2]+a[3]+a[4]>2*a[1])
				return cout<<(ans+1)%mod,0;
		}
		if(n==5){
			s3();s4();
			if(a[1]+a[2]+a[3]+a[4]+a[5]>2*a[1])
				return cout<<(ans+1)%mod,0;
		}
		if(n==6){
			s3();s4();s5();
			if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>2*a[1])
				return cout<<(ans+1)%mod,0;
		}
		if(n==7){
			s3();s4();s5();s6();
			if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]>2*a[1])
				return cout<<(ans+1)%mod,0;
		}
		if(n==8){
			s3();s4();s5();s6();s7();
			if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]>2*a[1])
				return cout<<(ans+1)%mod,0;
		}
		if(n==9){
			s3();s4();s5();s6();s7();s8();
			if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]>2*a[1])
				return cout<<(ans+1)%mod,0;
		}
		if(n==10){
			s3();s4();s5();s6();s7();s8();s9();
			if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]>2*a[1])
				return cout<<(ans+1)%mod,0;
		}
		if(n==11){
			s3();s4();s5();s6();s7();s8();s9();s10();
			for(i=1;i<=11;i++) s+=a[i];
			if(s>2*a[1]) return cout<<(ans+1)%mod,0;
		}
		if(n==12){
			s3();s4();s5();s6();s7();s8();s9();s10();s11();
			for(i=1;i<=12;i++) s+=a[i];
			if(s>2*a[1]) return cout<<(ans+1)%mod,0;
		}
		if(n==13){
			s3();s4();s5();s6();s7();s8();s9();s10();s11();s12();
			for(i=1;i<=13;i++) s+=a[i];
			if(s>2*a[1]) return cout<<(ans+1)%mod,0;
		}
		if(n==14){
			s3();s4();s5();s6();s7();s8();s9();s10();s11();s12();s13();
			for(i=1;i<=14;i++) s+=a[i];
			if(s>2*a[1]) return cout<<(ans+1)%mod,0;
		}
		if(n==15){
			s3();s4();s5();s6();s7();s8();s9();s10();s11();s12();s13();s14();
			for(i=1;i<=15;i++) s+=a[i];
			if(s>2*a[1]) return cout<<(ans+1)%mod,0;
		}
		if(n==16){
			s3();s4();s5();s6();s7();s8();s9();s10();s11();s12();s13();s14();s15();
			for(i=1;i<=16;i++) s+=a[i];
			if(s>2*a[1]) return cout<<(ans+1)%mod,0;
		}
		if(n==17){
			s3();s4();s5();s6();s7();s8();s9();s10();s11();s12();s13();s14();s15();s16();
			for(i=1;i<=17;i++) s+=a[i];
			if(s>2*a[1]) return cout<<(ans+1)%mod,0;
		}
		if(n==18){
			s3();s4();s5();s6();s7();s8();s9();s10();s11();s12();s13();s14();s15();s16();s17();
			for(i=1;i<=18;i++) s+=a[i];
			if(s>2*a[1]) return cout<<(ans+1)%mod,0;
		}
		if(n==19){
			s3();s4();s5();s6();s7();s8();s9();s10();s11();s12();s13();s14();s15();s16();s17();s18();
			for(i=1;i<=19;i++) s+=a[i];
			if(s>2*a[1]) return cout<<(ans+1)%mod,0;
		}
		if(n==20){
			s3();s4();s5();s6();s7();s8();s9();s10();s11();s12();s13();s14();s15();s16();s17();s18();s19();
			for(i=1;i<=20;i++) s+=a[i];
			if(s>2*a[1]) return cout<<(ans+1)%mod,0;
		}
	}
	return 0;
}
//#Shang4Shan3Ruo6Shui4
