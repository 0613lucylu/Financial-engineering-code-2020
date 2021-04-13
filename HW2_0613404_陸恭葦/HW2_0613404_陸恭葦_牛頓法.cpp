#include <bits/stdc++.h>
using namespace std;

int main()
{
    float c[100],x,n,r;
    cout<<"期數"<<endl;
    cin>>n;
    cout<<"期初投入"<<endl;
    cin>>x;
    cout<<"每期報酬"<<endl;
    for(int i=1;i<=n;i++)
    	cin>>c[i];
    cout<<"初始值"<<endl;
	cin>>r; 
    float value=0 ; 
	float value_dev ;
    float discount,discount_dev;
    for(int i=1;i<=n;i++)
        {
            discount=1;
            for(int j=1;j<=i;j++)
            {
                discount=discount/(1+r);
            }
            value=value+discount*c[i];
        }
        value=value-x;
    while(value>0.0001)
    {
    	value =0;
    	value_dev =0;
        for(int i=1;i<=n;i++)
        {
            discount=1;
            for(int j=1;j<=i;j++)
            {
                discount=discount/(1+r);
                discount_dev=discount/((1+r)*(1+r));
            }
            value=value+discount*c[i];
            value_dev=value_dev-(discount_dev*i*c[i]);
        }
        value=value-x;
        r=r-(value/value_dev);
    }
    cout<<"yeild rate"<<r<<endl;
    return 0;
}
