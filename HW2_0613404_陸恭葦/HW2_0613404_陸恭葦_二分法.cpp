#include <bits/stdc++.h>
using namespace std;

int main()
{
    float c[100],x,discount,n;
	float low=0,high=0.018;
    //float low=0.02,high=0.021; //�γo������ɤU��if-else�n�������ѵ{���X 
    cout<<"����"<<endl;
    cin>>n;
    cout<<"�����J"<<endl;
    cin>>x;
    cout<<"�C�����S"<<endl;
    for(int i=1;i<=n;i++)
    	cin>>c[i];
	while(abs(high-low)>=0.00001)
	{
		float middle = (low+high)/2;
		float value =0;
		        
    for(int i=1;i<=n;i++)
    {
        discount=1;
        for(int j=1;j<=i;j++)
        {
            discount=discount/(1+middle); 
        }
        value=value+discount*c[i];
    }
    value=value-x;

    if(value>0)
    {
        //high=middle;
        low=middle;
    }
    else
    {
        //low=middle;
        high=middle;
    }
    
	}
	cout<<"yield rate:"<<high<<endl;
	return 0;
    
}
