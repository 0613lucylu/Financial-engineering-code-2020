#include <bits/stdc++.h>
using namespace std;
float zerorate[5];
float yield[5];
float c,x,n,r;
float yieldspread;

void newton()
{
	
    cout<<"初始值"<<endl;
	cin>>r; 
    float value=0,bond=0 ; 
	float value_dev ;
    float discount,discount_dev,disbond;
    for(int i=1;i<=n;i++)
        {
            discount=1;
            disbond=1;
            for(int j=0;j<i;j++)
            {
                discount=discount/(1+r+zerorate[i-1]);
                disbond=disbond/(1+yieldspread+yield[i-1]);
            }
            //cout<<"disbond"<<disbond*c<<endl;
            bond=bond+disbond*c;
            value=value+discount*c;
            if(i==n)
            {
            	bond=bond+disbond*100;
				value=value+discount*100;
        	}
        }
        //cout<<value<<endl;
        value=value-bond;
        //cout<<bond<<endl;
        //cout<<value;
    while(abs(value)>0.0001)
    {
    	value =0;
    	bond=0;
    	value_dev =0;
        for(int i=1;i<=n;i++)
        {
        	disbond=1;
            discount=1;
            for(int j=0;j<i;j++)
            {
                discount=discount/(1+zerorate[i-1]+r);
                discount_dev=discount/((1+zerorate[i-1]+r)*(1+zerorate[i-1]+r));
                disbond=disbond/(1+yieldspread+yield[i-1]);
            }
            bond=bond+disbond*c;
            value=value+discount*c;
            value_dev=value_dev-(discount_dev*i*c);
            if(i==n)
            {
            	bond=bond+disbond*100;
            	value=value+discount*100;
            	value_dev=value_dev-discount*100;
			}
        }
        value=value-bond;
        r=r-(value/value_dev);
    }
    cout<<"static spread"<<r<<endl;
}


void bootstrap()
{
	cout<<"期數"<<endl;
    cin>>n;
	cout<<"每期報酬"<<endl;
    cin>>c;
	for(int i=0;i<n;i++)
	{
		cout<<"輸入yield rate"<<i+1<<"期 (以小數表示)"<<endl;
		cin>>yield[i]; 
	}
	cout<<"輸入yield spread "<<endl;
	cin>>yieldspread;
	zerorate[0]=yield[0];
	for(int i=1;i<=n-1;i++)
	{
		float bondvalue=0;
		for(int j=0;j<=i;j++)
		{
			float discount=1;
			for(int k=0;k<=j;k++)
				discount=discount/(1+yield[i]);
			bondvalue=bondvalue+discount*c;
			if(j==i)
				bondvalue=bondvalue+discount*100;
		}
		for(int j=0;j<i;j++)
		{
			float pv=c;
			for(int k=0;k<=j;k++)
				pv=pv/(1+zerorate[j]);
			bondvalue=bondvalue-pv;
		}
		zerorate[i]=pow((c+100)/bondvalue,1.0/(i+1))-1;
	}
	for(int i =0;i<=n-1;i++)
		cout<<"第"<<i+1<<"期zero rate: "<<zerorate[i]<<endl; 
	
}

int main()
{
    bootstrap();
    newton();
    return 0;
}
