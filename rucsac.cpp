#include<fstream>
#include<iostream>
using namespace  std;

ifstream fin("greedy.in");
ofstream fout("greedy.out");

typedef struct {
                        float greutate;
                        float profit;
                        float eficienta;
                        } obiect;
obiect M[100];
float profit_total;
float G;
int n;

int read_data()
{
    fin>>n;
    fin>>G;
    for (int i=1;i<=n;i++)
        {
            fin>>M[i].greutate;
            fin>>M[i].profit;
            M[i].eficienta=M[i].profit/M[i].greutate;
        }
}

int sort_data()
{
    int i,schimbat,aux;
    do
    {
        schimbat = 0;
        for(i = 0; i < n-1; i++)
            if(M[i].eficienta < M[i+1].eficienta)
            {
                aux = M[i].eficienta;
                M[i].eficienta = M[i+1].eficienta;
                M[i+1].eficienta = aux;
                schimbat = 1;
            }
    }while(schimbat);
}

float sweet_greedy()
{
    float v[n+1], s=0;
    float G_actual=0, G_dif, benefit;
    for(int i=1;i<=n;i++)
    {
        if(M[i].greutate+G_actual<=G)
        {
            benefit=M[i].greutate*M[i].eficienta;
            v[i]=benefit;
            G_actual+=M[i].greutate;
        }
        else
        {
            G_dif=G-G_actual;
            benefit=G_dif*M[i].eficienta;
            v[i]=benefit;
            G_actual+=G_dif;
        }
        if(G_actual==G)
            {
                for(int i=1;i<=n;i++)
                {
                    s+=v[i];
                }
                return s;
            }
    }
}

int main()
{
    read_data();
    sort_data();
    profit_total=sweet_greedy();
    cout<<profit_total;
}
