/*i was not able to complete my power code to use fractional powers too, like it gives answer for one
and doesn,t for some input, i'll keep working on it, so just for that in finding log i used pow, rest 
everything is up to date as up to my information.*/
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
double factorial(double x) 
{
    double f = 1.0;
    for (double i=1.0; i<=x; i++) {
        f *= i;
    }
    return f;
}

double exp( double a)
{
    return (pow(2.7182818285,a)) ;
}

double sine(double x)
{
    double term = x;
    double sum = term;
    for (int n = 1; n <= 10; n++) 
    {
        term *= -x * x / ((2 * n) * (2 * n + 1));
        sum += term;
    }
    return sum;
}

double cosine(double x)
{
    double term = 1;
    double sum = term;
    for (int n = 1; n <= 10; n++)
    {
        term *= -x * x / ((2 * n - 1) * (2 * n));
        sum += term;
    }
    return sum;
}

double tangent(double x)
{
   return sine(x) / cosine(x);
}
int main()
{
    string s="";

    do
    {
        cout<<"Enter your command"<<endl;
        cout<<"1. ADD"<<endl;
        cout<<"2. SUBTRACT"<<endl;
        cout<<"3. MULTIPLY"<<endl;
        cout<<"4. DIVIDE"<<endl;
        cout<<"5. SQRT"<<endl;
        cout<<"6. POWER"<<endl;
        cout<<"7. LOG10"<<endl;
        cout<<"8. NATURAL LOG"<<endl;
        cout<<"9. SINE"<<endl;
        cout<<"10. COSINE"<<endl;
        cout<<"11. TANGENT"<<endl;
        cout<<"12. EXPONENTIAL"<<endl;
        cout<<"13. EXIT"<<endl;
        cin>>s;
        if(s=="1")
        {
            int n,m,s;
            cout<<"ENTER THE TWO NUMBERS"<<endl;
            cin>>n>>m;
            s=n+m;
            cout<<"SUM = "<<s<<endl;
        }
        if(s=="2")
        {
            int n,m,s;
            cout<<"ENTER THE TWO NUMBERS"<<endl;
            cin>>n>>m;
            s=n-m;
            cout<<"SUB = "<<s<<endl;
        }
        if(s=="3")
        {
            int n,m,s;
            cout<<"ENTER THE TWO NUMBERS"<<endl;
            cin>>n>>m;
            s=n*m;
            cout<<"MUL = "<<s<<endl;
        }
        if(s=="4")
        {
            int n,m,s;
            cout<<"ENTER THE TWO NUMBERS"<<endl;
            cin>>n>>m;
            s=n/m;
            cout<<"DIV = "<<s<<endl;
        }
        if(s=="5")
        {
            double n,s;
            cout<<"ENTER THE ONE NUMBER"<<endl;
            cin>>n;
            for(double i=0.001; ; i=i+0.001)
            {
                if(n-(i*i)<=0.01)
                {
                    s=i;
                    break;
                }
            }
            cout<<"SQRT = "<<s<<endl;
        }
        if(s=="6")
        {
            double a,b,f=1.0;
            cout<<"ENTER TWO NUMBERS"<<endl;
            cin>>a>>b;
            double s1=1.0,t=0.0;
            for(int i=1; i<=15; i++)
            {
                f=1.0;
                t=s1;
                for(int j=0; j<i; j++)
                {
                    f=f*(b-j)*(a-1.0);  
                }
                s1=s1+(f/factorial(i));
                }
                cout<<s1<<endl;
            }
        if(s=="7")
        {
            double n,s,m;
            cout<<"ENTER THE ONE NUMBER"<<endl;
            cin>>n;
            for(double i=0.01; ; i=i+0.01)
            {
                m=pow(10,i);
                s=n-m;
                if(s<=0.01)
                {
                    cout<<i<<endl;
                    break;
                }
            }
        }
        if(s=="8")
        {
            double n,s,m,p;
            cout<<"ENTER THE ONE NUMBER"<<endl;
            cin>>n;
            for(double i=0.01; ; i=i+0.01)
            {
                m=pow(10,i);
                s=n-m;
                if(s<=0.01)
                {
                    p=i;
                    break;
                }
            }
            cout<<"NATURAL LOG = "<<(p/2.303)<<endl;
        }
        if(s=="9")
        {
            int a;
            cout<<"ENTER ANGLE";
            cin >> a;
            cout<<"SINE = "<<sine(a)<<endl;
        }
        if(s=="10")
        {
            int a;
            cout<<"ENTER ANGLE";
            cin>>a;
            cout<<"COSINE = "<<cosine(a)<<endl;
        }
        if(s=="11")
        {
            int a;
            cout<<"ENTER ANGLE";
            cin>>a;
            cout<<"TANGENT = "<<tangent(a)<<endl;
        }
        if(s=="12")
        {
            int a;
            cout<<"ENTER EXPONENTIAL VALUE = ";
            cin>>a;
            cout<<"e^"<<a<<" = "<<exp(a)<<endl;
        }
    }
    while(s!="13");
}

            