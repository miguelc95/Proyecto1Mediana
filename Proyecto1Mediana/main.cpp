//
//  main.cpp
//  Proyecto1Mediana
//
//  Created by Miguel Cuellar on 2/29/16.
//  Copyright © 2016 Miguel Cuellar. All rights reserved.
//Miguel cuéllar A01280736
//Carmelo Ramirez A01175987

#include <iostream>
#include<cstdio>
using namespace std;




float reducir(float arr[], int n)
{
   return n%2==0 ?  (arr[n/2] + arr[n/2-1])/2 :  arr[n/2];
}

float mediana(float ar1[], float ar2[], int n)
{
    int m1,m2;
    if (n <= 0)return -1;
    if (n==1)return (ar1[0] + ar2[0])/2;
    if (n==2)return (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1])) / 2;
    m1 = reducir(ar1, n);
    m2 = reducir(ar2, n);
    if (m1 == m2)return m1;
    
    if (m1 < m2)return (n%2==0) ? mediana(ar1 + n/2 - 1, ar2, n - n/2 +1) :mediana(ar1 + n/2, ar2, n - n/2);
    else
    {
        return (n % 2 == 0) ? mediana(ar2 + n/2 - 1, ar1, n - n/2 + 1):mediana(ar2 + n/2, ar1, n - n/2);
    }
}


int main() {
    int casos,size;
    float arr1[100], arr2[100];
    cin>>casos;
    for (int i=1; i<=casos; i++) {
        cin>>size;
     
    for (int ix=0; ix<size; ix++) {
        cin>>arr1[ix];
        }
    for (int iy=0; iy<size; iy++) {
        cin>>arr2[iy];
        }
      /*  for (int ix=0; ix<size; ix++) {
            cout<<arr1[ix]<<" ";
        }                                   //IMPRIMIR
        cout<<endl;
        for (int ix=0; ix<size; ix++) {
            cout<<arr2[ix]<<" ";
        }
        cout<<endl;
       */
        printf("Median case %d: %.2f\n", i, mediana(arr1, arr2, size));
        
        
    }

    
    return 0;
}
