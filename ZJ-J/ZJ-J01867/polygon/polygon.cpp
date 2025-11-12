#include<bits/stdc++.h>
using namespace std;
int n,a[10001],d,b[10001];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
if(n==1)    {for(int i1=0;i1<2;i1++)
        {
        b[1]=i1;
        
    }
int t=0,l=0;
for(int k=0;k<n;k++){
if(b[k]==1)
{
t=k;
l+=a[k];
}
if(a[t]*2<l) d++;
}
    }if(n==2)    {for(int i1=0;i1<2;i1++)
        {
for(int i2=0;i2<2;i2++)
            {
            b[1]=i1;
            b[2]=i2;
int t=0,l=0;
for(int k=0;k<n;k++){
if(b[k]==1)
{
t=k;
l+=a[k];
}
if(a[t]*2<l) d++;
    }}
}
    }if(n==3)    {for(int i1=0;i1<2;i1++)
        {
for(int i2=0;i2<2;i2++)
            {
for(int i3=0;i3<2;i3++)
                {
                b[1]=i1;
                b[2]=i2;
                b[3]=i3;
int t=0,l=0;
for(int k=0;k<n;k++){
if(b[k]==1)
{
t=k;
l+=a[k];
}
if(a[t]*2<l) d++;
        }}
    }
}
    }if(n==4)    {for(int i1=0;i1<2;i1++)
        {
for(int i2=0;i2<2;i2++)
            {
for(int i3=0;i3<2;i3++)
                {
for(int i4=0;i4<2;i4++)
                    {
                    b[1]=i1;
                    b[2]=i2;
                    b[3]=i3;
                    b[4]=i4;
int t=0,l=0;
for(int k=0;k<n;k++){
if(b[k]==1)
{
t=k;
l+=a[k];
}
if(a[t]*2<l) d++;
            }
        }
    }}
}
    }if(n==5)    {for(int i1=0;i1<2;i1++)
        {
for(int i2=0;i2<2;i2++)
            {
for(int i3=0;i3<2;i3++)
                {
for(int i4=0;i4<2;i4++)
                    {
for(int i5=0;i5<2;i5++)
                        {
                        b[1]=i1;
                        b[2]=i2;
                        b[3]=i3;
                        b[4]=i4;
                        b[5]=i5;
int t=0,l=0;
for(int k=0;k<n;k++){
if(b[k]==1)
{
t=k;
l+=a[k];
}
if(a[t]*2<l) d++;
                }
            }}
        }
    }
}
    }if(n==6)    {for(int i1=0;i1<2;i1++)
        {
for(int i2=0;i2<2;i2++)
            {
for(int i3=0;i3<2;i3++)
                {
for(int i4=0;i4<2;i4++)
                    {
for(int i5=0;i5<2;i5++)
                        {
for(int i6=0;i6<2;i6++)
                            {
                            b[1]=i1;
                            b[2]=i2;
                            b[3]=i3;
                            b[4]=i4;
                            b[5]=i5;
                            b[6]=i6;
int t=0,l=0;
for(int k=0;k<n;k++){
if(b[k]==1)
{
t=k;
l+=a[k];
}
if(a[t]*2<l) d++;
                    }
                }
            }}
        }
    }
}
    }if(n==7)    {for(int i1=0;i1<2;i1++)
        {
for(int i2=0;i2<2;i2++)
            {
for(int i3=0;i3<2;i3++)
                {
for(int i4=0;i4<2;i4++)
                    {
for(int i5=0;i5<2;i5++)
                        {
for(int i6=0;i6<2;i6++)
                            {
for(int i7=0;i7<2;i7++)
                                {
                                b[1]=i1;
                                b[2]=i2;
                                b[3]=i3;
                                b[4]=i4;
                                b[5]=i5;
                                b[6]=i6;
                                b[7]=i7;
int t=0,l=0;
for(int k=0;k<n;k++){
if(b[k]==1)
{
t=k;
l+=a[k];
}
if(a[t]*2<l) d++;
                        }
                    }}
                }
            }
        }
    }
}
    }if(n==8)    {for(int i1=0;i1<2;i1++)
        {
for(int i2=0;i2<2;i2++)
            {
for(int i3=0;i3<2;i3++)
                {
for(int i4=0;i4<2;i4++)
                    {
for(int i5=0;i5<2;i5++)
                        {
for(int i6=0;i6<2;i6++)
                            {
for(int i7=0;i7<2;i7++)
                                {
for(int i8=0;i8<2;i8++)
                                    {
                                    b[1]=i1;
                                    b[2]=i2;
                                    b[3]=i3;
                                    b[4]=i4;
                                    b[5]=i5;
                                    b[6]=i6;
                                    b[7]=i7;
                                    b[8]=i8;
int t=0,l=0;
for(int k=0;k<n;k++){
if(b[k]==1)
{
t=k;
l+=a[k];
}
if(a[t]*2<l) d++;
                            }
                        }
                    }
                }
            }
        }}
    }
}
    }if(n==9)    {for(int i1=0;i1<2;i1++)
        {
for(int i2=0;i2<2;i2++)
            {
for(int i3=0;i3<2;i3++)
                {
for(int i4=0;i4<2;i4++)
                    {
for(int i5=0;i5<2;i5++)
                        {
for(int i6=0;i6<2;i6++)
                            {
for(int i7=0;i7<2;i7++)
                                {
for(int i8=0;i8<2;i8++)
                                    {
for(int i9=0;i9<2;i9++)
                                        {
                                        b[1]=i1;
                                        b[2]=i2;
                                        b[3]=i3;
                                        b[4]=i4;
                                        b[5]=i5;
                                        b[6]=i6;
                                        b[7]=i7;
                                        b[8]=i8;
                                        b[9]=i9;
int t=0,l=0;
for(int k=0;k<n;k++){
if(b[k]==1)
{
t=k;
l+=a[k];
}
if(a[t]*2<l) d++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }}
}
    }if(n==10)    {for(int i1=0;i1<2;i1++)
        {
for(int i2=0;i2<2;i2++)
            {
for(int i3=0;i3<2;i3++)
                {
for(int i4=0;i4<2;i4++)
                    {
for(int i5=0;i5<2;i5++)
                        {
for(int i6=0;i6<2;i6++)
                            {
for(int i7=0;i7<2;i7++)
                                {
for(int i8=0;i8<2;i8++)
                                    {
for(int i9=0;i9<2;i9++)
                                        {
for(int i10=0;i10<2;i10++)
                                            {
                                            b[1]=i1;
                                            b[2]=i2;
                                            b[3]=i3;
                                            b[4]=i4;
                                            b[5]=i5;
                                            b[6]=i6;
                                            b[7]=i7;
                                            b[8]=i8;
                                            b[9]=i9;
                                            b[10]=i10;
int t=0,l=0;
for(int k=0;k<n;k++){
if(b[k]==1)
{
t=k;
l+=a[k];
}
if(a[t]*2<l) d++;
                                    }
                                }
                            }
                        }
                    }
                }
            }}
        }
    }
}
    }if(n==11)    {for(int i1=0;i1<2;i1++)
        {
for(int i2=0;i2<2;i2++)
            {
for(int i3=0;i3<2;i3++)
                {
for(int i4=0;i4<2;i4++)
                    {
for(int i5=0;i5<2;i5++)
                        {
for(int i6=0;i6<2;i6++)
                            {
for(int i7=0;i7<2;i7++)
                                {
for(int i8=0;i8<2;i8++)
                                    {
for(int i9=0;i9<2;i9++)
                                        {
for(int i10=0;i10<2;i10++)
                                            {
for(int i11=0;i11<2;i11++)
                                                {
                                                b[1]=i1;
                                                b[2]=i2;
                                                b[3]=i3;
                                                b[4]=i4;
                                                b[5]=i5;
                                                b[6]=i6;
                                                b[7]=i7;
                                                b[8]=i8;
                                                b[9]=i9;
                                                b[10]=i10;
                                                b[11]=i11;
int t=0,l=0;
for(int k=0;k<n;k++){
if(b[k]==1)
{
t=k;
l+=a[k];
}
if(a[t]*2<l) d++;
                                        }
                                    }
                              }  }
                            }
                        }
                    }
                }
            }
        }
    }
}
    }if(n==12)    {for(int i1=0;i1<2;i1++)
        {
for(int i2=0;i2<2;i2++)
            {
for(int i3=0;i3<2;i3++)
                {
for(int i4=0;i4<2;i4++)
                    {
for(int i5=0;i5<2;i5++)
                        {
for(int i6=0;i6<2;i6++)
                            {
for(int i7=0;i7<2;i7++)
                                {
for(int i8=0;i8<2;i8++)
                                    {
for(int i9=0;i9<2;i9++)
                                        {
for(int i10=0;i10<2;i10++)
                                            {
for(int i11=0;i11<2;i11++)
                                                {
for(int i12=0;i12<2;i12++)
                                                    {
                                                    b[1]=i1;
                                                    b[2]=i2;
                                                    b[3]=i3;
                                                    b[4]=i4;
                                                    b[5]=i5;
                                                    b[6]=i6;
                                                    b[7]=i7;
                                                    b[8]=i8;
                                                    b[9]=i9;
                                                    b[10]=i10;
                                                    b[11]=i11;
                                                    b[12]=i12;
int t=0,l=0;
for(int k=0;k<n;k++){
if(b[k]==1)
{
t=k;
l+=a[k];
}
if(a[t]*2<l) d++;
                                            }
                                        }
                                    }
                                }
                            }
                      }  }
                    }
                }
            }
        }
    }
}
    }if(n==13)    {for(int i1=0;i1<2;i1++)
        {
for(int i2=0;i2<2;i2++)
            {
for(int i3=0;i3<2;i3++)
                {
for(int i4=0;i4<2;i4++)
                    {
for(int i5=0;i5<2;i5++)
                        {
for(int i6=0;i6<2;i6++)
                            {
for(int i7=0;i7<2;i7++)
                                {
for(int i8=0;i8<2;i8++)
                                    {
for(int i9=0;i9<2;i9++)
                                        {
for(int i10=0;i10<2;i10++)
                                            {
for(int i11=0;i11<2;i11++)
                                                {
for(int i12=0;i12<2;i12++)
                                                    {
for(int i13=0;i13<2;i13++)
                                                        {
                                                        b[1]=i1;
                                                        b[2]=i2;
                                                        b[3]=i3;
                                                        b[4]=i4;
                                                        b[5]=i5;
                                                        b[6]=i6;
                                                        b[7]=i7;
                                                        b[8]=i8;
                                                        b[9]=i9;
                                                        b[10]=i10;
                                                        b[11]=i11;
                                                        b[12]=i12;
                                                        b[13]=i13;
int t=0,l=0;
for(int k=0;k<n;k++){
if(b[k]==1)
{
t=k;
l+=a[k];
}
if(a[t]*2<l) d++;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                 }   }
                }
            }
        }
    }
}
    }if(n==14)    {for(int i1=0;i1<2;i1++)
        {
for(int i2=0;i2<2;i2++)
            {
for(int i3=0;i3<2;i3++)
                {
for(int i4=0;i4<2;i4++)
                    {
for(int i5=0;i5<2;i5++)
                        {
for(int i6=0;i6<2;i6++)
                            {
for(int i7=0;i7<2;i7++)
                                {
for(int i8=0;i8<2;i8++)
                                    {
for(int i9=0;i9<2;i9++)
                                        {
for(int i10=0;i10<2;i10++)
                                            {
for(int i11=0;i11<2;i11++)
                                                {
for(int i12=0;i12<2;i12++)
                                                    {
for(int i13=0;i13<2;i13++)
                                                        {
for(int i14=0;i14<2;i14++)
                                                            {
                                                            b[1]=i1;
                                                            b[2]=i2;
                                                            b[3]=i3;
                                                            b[4]=i4;
                                                            b[5]=i5;
                                                            b[6]=i6;
                                                            b[7]=i7;
                                                            b[8]=i8;
                                                            b[9]=i9;
                                                            b[10]=i10;
                                                            b[11]=i11;
                                                            b[12]=i12;
                                                            b[13]=i13;
                                                            b[14]=i14;
int t=0,l=0;
for(int k=0;k<n;k++){
if(b[k]==1)
{
t=k;
l+=a[k];
}
if(a[t]*2<l) d++;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }}
        }
    }
}
    }if(n==15)    {for(int i1=0;i1<2;i1++)
        {
for(int i2=0;i2<2;i2++)
            {
for(int i3=0;i3<2;i3++)
                {
for(int i4=0;i4<2;i4++)
                    {
for(int i5=0;i5<2;i5++)
                        {
for(int i6=0;i6<2;i6++)
                            {
for(int i7=0;i7<2;i7++)
                                {
for(int i8=0;i8<2;i8++)
                                    {
for(int i9=0;i9<2;i9++)
                                        {
for(int i10=0;i10<2;i10++)
                                            {
for(int i11=0;i11<2;i11++)
                                                {
for(int i12=0;i12<2;i12++)
                                                    {
for(int i13=0;i13<2;i13++)
                                                        {
for(int i14=0;i14<2;i14++)
                                                            {
for(int i15=0;i15<2;i15++)
                                                                {
                                                                b[1]=i1;
                                                                b[2]=i2;
                                                                b[3]=i3;
                                                                b[4]=i4;
                                                                b[5]=i5;
                                                                b[6]=i6;
                                                                b[7]=i7;
                                                                b[8]=i8;
                                                                b[9]=i9;
                                                                b[10]=i10;
                                                                b[11]=i11;
                                                                b[12]=i12;
                                                                b[13]=i13;
                                                                b[14]=i14;
                                                                b[15]=i15;
int t=0,l=0;
for(int k=0;k<n;k++){
if(b[k]==1)
{
t=k;
l+=a[k];
}
if(a[t]*2<l) d++;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }}
    }
}
    }if(n==16)    {for(int i1=0;i1<2;i1++)
        {
for(int i2=0;i2<2;i2++)
            {
for(int i3=0;i3<2;i3++)
                {
for(int i4=0;i4<2;i4++)
                    {
for(int i5=0;i5<2;i5++)
                        {
for(int i6=0;i6<2;i6++)
                            {
for(int i7=0;i7<2;i7++)
                                {
for(int i8=0;i8<2;i8++)
                                    {
for(int i9=0;i9<2;i9++)
                                        {
for(int i10=0;i10<2;i10++)
                                            {
for(int i11=0;i11<2;i11++)
                                                {
for(int i12=0;i12<2;i12++)
                                                    {
for(int i13=0;i13<2;i13++)
                                                        {
for(int i14=0;i14<2;i14++)
                                                            {
for(int i15=0;i15<2;i15++)
                                                                {
for(int i16=0;i16<2;i16++)
                                                                    {
                                                                    b[1]=i1;
                                                                    b[2]=i2;
                                                                    b[3]=i3;
                                                                    b[4]=i4;
                                                                    b[5]=i5;
                                                                    b[6]=i6;
                                                                    b[7]=i7;
                                                                    b[8]=i8;
                                                                    b[9]=i9;
                                                                    b[10]=i10;;
                                                                    b[11]=i11;
                                                                    b[12]=i12;
                                                                    b[13]=i13;
                                                                    b[14]=i14;
                                                                    b[15]=i15;
                                                                    b[16]=i16;
int t=0,l=0;
for(int k=0;k<n;k++){
if(b[k]==1)
{
t=k;
l+=a[k];
}
if(a[t]*2<l) d++;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}}
    }if(n==17)    {for(int i1=0;i1<2;i1++)
        {
for(int i2=0;i2<2;i2++)
            {
for(int i3=0;i3<2;i3++)
                {
for(int i4=0;i4<2;i4++)
                    {
for(int i5=0;i5<2;i5++)
                        {
for(int i6=0;i6<2;i6++)
                            {
for(int i7=0;i7<2;i7++)
                                {
for(int i8=0;i8<2;i8++)
                                    {
for(int i9=0;i9<2;i9++)
                                        {
for(int i10=0;i10<2;i10++)
                                            {
for(int i11=0;i11<2;i11++)
                                                {
for(int i12=0;i12<2;i12++)
                                                    {
for(int i13=0;i13<2;i13++)
                                                        {
for(int i14=0;i14<2;i14++)
                                                            {
for(int i15=0;i15<2;i15++)
                                                                {
for(int i16=0;i16<2;i16++)
                                                                    {
for(int i17=0;i17<2;i17++)
                                                                        {
                                                                        b[1]=i1;
                                                                        b[2]=i2;
                                                                        b[3]=i3;
                                                                        b[4]=i4;
                                                                        b[5]=i5;
                                                                        b[6]=i6;
                                                                        b[7]=i7;
                                                                        b[8]=i8;
                                                                        b[9]=i9;
                                                                        b[10]=i10;
                                                                        b[11]=i11;
                                                                        b[12]=i12;
                                                                        b[13]=i13;
                                                                        b[14]=i14;
                                                                        b[15]=i15;
                                                                        b[16]=i16;
                                                                        b[17]=i17;
int t=0,l=0;
for(int k=0;k<n;k++){
if(b[k]==1)
{
t=k;
l+=a[k];
}
if(a[t]*2<l) d++;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}}
    }if(n==18)    {for(int i1=0;i1<2;i1++)
        {
for(int i2=0;i2<2;i2++)
            {
for(int i3=0;i3<2;i3++)
                {
for(int i4=0;i4<2;i4++)
                    {
for(int i5=0;i5<2;i5++)
                        {
for(int i6=0;i6<2;i6++)
                            {
for(int i7=0;i7<2;i7++)
                                {
for(int i8=0;i8<2;i8++)
                                    {
for(int i9=0;i9<2;i9++)
                                        {
for(int i10=0;i10<2;i10++)
                                            {
for(int i11=0;i11<2;i11++)
                                                {
for(int i12=0;i12<2;i12++)
                                                    {
for(int i13=0;i13<2;i13++)
                                                        {
for(int i14=0;i14<2;i14++)
                                                            {
for(int i15=0;i15<2;i15++)
                                                                {
for(int i16=0;i16<2;i16++)
                                                                    {
for(int i17=0;i17<2;i17++)
                                                                        {
for(int i18=0;i18<2;i18++)
                                                                            {
                                                                            b[1]=i1;
                                                                            b[2]=i2;
                                                                            b[3]=i3;
                                                                            b[4]=i4;
                                                                            b[5]=i5;
                                                                            b[6]=i6;
                                                                            b[7]=i7;
                                                                            b[8]=i8;
                                                                            b[9]=i9;
                                                                            b[10]=i10;;
                                                                            b[11]=i11;
                                                                            b[12]=i12;
                                                                            b[13]=i13;
                                                                            b[14]=i14;
                                                                            b[15]=i15;
                                                                            b[16]=i16;
                                                                            b[17]=i17;
                                                                            b[18]=i18;
int t=0,l=0;
for(int k=0;k<n;k++){
if(b[k]==1)
{
t=k;
l+=a[k];
}
if(a[t]*2<l) d++;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
    }}if(n==19)    {for(int i1=0;i1<2;i1++)
        {
for(int i2=0;i2<2;i2++)
            {
for(int i3=0;i3<2;i3++)
                {
for(int i4=0;i4<2;i4++)
                    {
for(int i5=0;i5<2;i5++)
                        {
for(int i6=0;i6<2;i6++)
                            {
for(int i7=0;i7<2;i7++)
                                {
for(int i8=0;i8<2;i8++)
                                    {
for(int i9=0;i9<2;i9++)
                                        {
for(int i10=0;i10<2;i10++)
                                            {
for(int i11=0;i11<2;i11++)
                                                {
for(int i12=0;i12<2;i12++)
                                                    {
for(int i13=0;i13<2;i13++)
                                                        {
for(int i14=0;i14<2;i14++)
                                                            {
for(int i15=0;i15<2;i15++)
                                                                {
for(int i16=0;i16<2;i16++)
                                                                    {
for(int i17=0;i17<2;i17++)
                                                                        {
for(int i18=0;i18<2;i18++)
                                                                            {
for(int i19=0;i19<2;i19++)
                                                                                {
                                                                                b[1]=i1;
                                                                                b[2]=i2;
                                                                                b[3]=i3;
                                                                                b[4]=i4;
                                                                                b[5]=i5;
                                                                                b[6]=i6;
                                                                                b[7]=i7;
                                                                                b[8]=i8;
                                                                                b[9]=i9;
                                                                                b[10]=i10;
                                                                                b[11]=i11;
                                                                                b[12]=i12;
                                                                                b[13]=i13;
                                                                                b[14]=i14;
                                                                                b[15]=i15;
                                                                                b[16]=i16;
                                                                                b[17]=i17;
                                                                                b[18]=i18;
                                                                                b[19]=i19;
int t=0,l=0;
for(int k=0;k<n;k++){
if(b[k]==1)
{
t=k;
l+=a[k];
}
if(a[t]*2<l) d++;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }}
}
    }if(n==20)    {for(int i1=0;i1<2;i1++)
        {
for(int i2=0;i2<2;i2++)
            {
for(int i3=0;i3<2;i3++)
                {
for(int i4=0;i4<2;i4++)
                    {
for(int i5=0;i5<2;i5++)
                        {
for(int i6=0;i6<2;i6++)
                            {
for(int i7=0;i7<2;i7++)
                                {
for(int i8=0;i8<2;i8++)
                                    {
for(int i9=0;i9<2;i9++)
                                        {
for(int i10=0;i10<2;i10++)
                                            {
for(int i11=0;i11<2;i11++)
                                                {
for(int i12=0;i12<2;i12++)
                                                    {
for(int i13=0;i13<2;i13++)
                                                        {
for(int i14=0;i14<2;i14++)
                                                            {
for(int i15=0;i15<2;i15++)
                                                                {
for(int i16=0;i16<2;i16++)
                                                                    {
for(int i17=0;i17<2;i17++)
                                                                        {
for(int i18=0;i18<2;i18++)
                                                                            {
for(int i19=0;i19<2;i19++)
                                                                                {
for(int i20=0;i20<2;i20++)
                                                                                    {
                                                                                    b[1]=i1;
                                                                                    b[2]=i2;
                                                                                    b[3]=i3;
                                                                                    b[4]=i4;
                                                                                    b[5]=i5;
                                                                                    b[6]=i6;
                                                                                    b[7]=i7;
                                                                                    b[8]=i8;
                                                                                    b[9]=i9;
                                                                                    b[10]=i10;
                                                                                    b[11]=i11;
                                                                                    b[12]=i12;
                                                                                    b[13]=i13;
                                                                                    b[14]=i14;
                                                                                    b[15]=i15;
                                                                                    b[16]=i16;
                                                                                    b[17]=i17;
                                                                                    b[18]=i18;
                                                                                    b[19]=i19;
                                                                                    b[20]=i20;
int t=0,l=0;
for(int k=0;k<n;k++){
if(b[k]==1)
{
t=k;
l+=a[k];
}
if(a[t]*2<l) d++;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
}
	
 }cout<<d;
	return 0;
 }
