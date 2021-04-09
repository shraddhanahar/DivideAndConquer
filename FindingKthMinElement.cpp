
#include<iostream>
using namespace std;

    int Partition(int a[],int start,int end);    // Partition function declaration
    void swap(int *a,int *b);
 
    void display(int a[],int i,int n)                     // display array function
    {
        for(i=1;i<=n;i++)
        {
        cout<<"\t"<<a[i];
        }
    }
    

    void FindingKthMinElement(int a[],int start,int end,int k)            //Definition 
    {   
        int m,p=start,q=end,i;      
        if(p<q) 
        {
            m=Partition(a,p,q);     
            if(m==k)
            return ;
            else if(m>k)                     // Meaningful divide
            FindingKthMinElement(a,p,m-1,k); // Conquer
            else                    
            FindingKthMinElement(a,m+1,q,k); // Conquer
        }
        
    }
    
    
   int Partition(int a[],int p,int q)
   {
    int i=p,j,x=a[p];
        for(j=p+1;j<=q;j++)
        {
           if(a[j]<=x)
            {
            i++;
            swap(&a[i],&a[j]);
            }
        }
        
        swap(&a[i],&a[p]);
        return i;
   }

   void swap(int *a,int *b)
   {
       int x;
        x=*a;
        *a=*b;
        *b=x;
   }
   
   
   
int main()
{
int a[100],n,i,k;

    cout<<"Enter size of array :\t";
    cin>>n;
        
                                /* #####AcceptArray##### */ 
    cout<<"Enter elements :\n";
    for(int i =1 ;i<=n;i++)
    {
    cin>>a[i];
    }
    cout<<"Enter which minimum (index) element you want ?\n";
    cin>>k;

                               /* #####DisplayArrayElements##### */                                     
    cout<<"Elements of array are :";    
    display(a,1,n);
                               /* #####Finding Kth min element in array##### */             
    FindingKthMinElement(a,1,n,k);
                               /* #####ReturningElement##### */ 
    cout<<endl<<"Kth min element is :";
    cout<<a[k];
}