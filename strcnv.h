#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

sminusc(char str[])
{
    int i=0;

    while (str[i]!='\0')
    {
        if((str[i]>=65)&&(str[i]<=90))
            str[i]+=32;
        i++;
    }
}

smaiusc(char str[])
{
    int i=0;

    while (str[i]!='\0')
    {
        if((str[i]>=97)&&(str[i]<=122))
            str[i]-=32;
        i++;
    }
}

// 0 stringa non trovata 1 stringa contenuta 2 stringa contenuta parzialmente 3 stringa uguale
short cerca(char sdt[],char in[])
{
    int m = strlen(sdt);
    int n = strlen(in);
    char input[50];
    int j, i,t;
    short cc = 0;
    int contatore = 0;

    copia_riga(input,in);
    sminusc(input);
    sminusc(sdt);

    if(n == m)
    {
        if(strcmp(input,sdt) == 0)
            return 1;
    }

    j = 0;
    i = 0;
    t = 0;
    while((j < m) && (i < n))
    {
        if (input[i] == sdt[j])
        {
            if (cc == 0)
                cc = 3;
            contatore++;
            i++;
            j++;
        }
        else
        {
            i = i - contatore + 1;
            j = t;
            contatore = 0;
        }

        if ((i == n) && (j < m) && (cc == 0))
        {
            j++;
            t = j;
            i = 0;
        }

        if (contatore == m)
        {
            return 2;
        }
    }

    return cc;
}

void copia_riga(char out[],char str[])
{
    int i=0;

    while((str[i]!='\n')&&(str[i]!='\0'))
    {
        out[i]=str[i];
        i++;
    }
    out[i]='\0';
}

void strunion(char str1[],char str2[],char c_end)
{
    int n=strlen(str1);
    int i=0;

    while(str2[i]!='\0')
    {
        str1[n]=str2[i];
        n++;
        i++;
    }
    str1[n]=c_end;
    str1[n+1]='\0';
}

void split(char out[],char inp[],char del)
{
    int j=0;
    int i=0;
    short c=0;

    while((inp[i]!='\0')&&(c==0))
    {
        if(inp[i]!=del)
        {
            out[i]=inp[i];
            i++;
        }
        else
        {
            out[i]='\0';
            c=1;
            i++;
        }
    }

    while(inp[i]!='\0')
    {
        inp[j]=inp[i];
        i++;
        j++;
    }
    inp[j]='\0';
}

double valc (char s[],short tipe)
{
    double v=0;
    short a=0;
    int l=0;
    int i=0;
    short tpr=7;
    short mz=0;

    switch (tipe)
    {
        case 1:
            if (strlen(s)>7)
            {
                printf("\nIl valore inserito è troppo grande per il tipo di variabie scelto!\nVerrà ritornato il valore 0!");
                return 0;
            }
            else
            {
                l=strlen(s);
            }
            break;
        case 2:
            if (strlen(s)>12)
            {
                printf("\nIl valore inserito è troppo grande per il tipo di variabie scelto!\nVerrà ritornato il valore 0!");
                return 0;
            }
            else
            {
                l=strlen(s);
            }
            break;
        case 3:
            l=strlen(s);
            tpr=7;
            break;
        case 4:
            l=strlen(s);
            tpr=14;
            break;
    }
    l=strlen(s);

    for(i=0;i<l;i++)
    {
        switch (s[i])
        {
            case '\n':
            break;
            case '-':
                if (i==0)
                {
                    mz=1;
                }
                else
                {
                    printf("\nIl dato inserito contiene valori non validi! (\"%c\")\nAnnullamento operazione!",s[i]);
                    return 0;
                }
                break;
            case '.':
                if ((a==0)&&(i!=0)&&(i!=l-1))
                {
                    a=1;
                }
                else
                {
                    printf("\nErrore: 2 o più punti o virgole presenti \no letti in una posizione non valida\nL'operazione verrà annullata!\n");
                    return 0;
                }
                break;
            case ',':
                if ((a==0)&&(i!=0)&&(i!=l-1))
                {
                    a=1;
                }
                else
                {
                    printf("\nErrore: 2 o più punti o virgole presenti \no letti in una posizione non valida\nL'operazione verrà annullata!\n");
                    return 0;
                }
                break;
            case '0':
                if (a==0)
                {
                    v=v*10;
                }
                else
                {
                    a++;
                }
                break;
            case '1':
                if (a==0)
                {
                    v=v*10+1;
                }
                else
                {
                    if (a>tpr)
                    {
                        printf("\nRaggiunto il limite di cifre decimali\nLe cifre successive verranno tagliate!\n");
                        return v;
                    }
                    v+=((float)1/(pow(10,a)));
                    a++;
                }
                break;
            case '2':
                if (a==0)
                {
                    v=v*10+2;
                }
                else
                {
                    if (a>tpr)
                    {
                        printf("\nRaggiunto il limite di cifre decimali\nLe cifre successive verranno tagliate!\n");
                        return v;
                    }
                    v+=((float)2/(pow(10,a)));
                    a++;
                }
                break;
            case '3':
                if (a==0)
                {
                    v=v*10+3;
                }
                else
                {
                    if (a>tpr)
                    {
                        printf("\nRaggiunto il limite di cifre decimali\nLe cifre successive verranno tagliate!\n");
                        return v;
                    }
                    v+=((float)3/(pow(10,a)));
                    a++;
                }
                break;
            case '4':
                if (a==0)
                {
                    v=v*10+4;
                }
                else
                {
                    if (a>tpr)
                    {
                        printf("\nRaggiunto il limite di cifre decimali\nLe cifre successive verranno tagliate!\n");
                        return v;
                    }
                    v+=((float)4/(pow(10,a)));
                    a++;
                }
                break;
            case '5':
                if (a==0)
                {
                    v=v*10+5;
                }
                else
                {
                    if (a>tpr)
                    {
                        printf("\nRaggiunto il limite di cifre decimali\nLe cifre successive verranno tagliate!\n");
                        return v;
                    }
                    v+=((float)5/(pow(10,a)));
                    a++;
                }
                break;
            case '6':
                if (a==0)
                {
                    v=v*10+6;
                }
                else
                {
                    if (a>tpr)
                    {
                        printf("\nRaggiunto il limite di cifre decimali\nLe cifre successive verranno tagliate!\n");
                        return v;
                    }
                    v+=((float)6/(pow(10,a)));
                    a++;
                }
                break;
            case '7':
                if (a==0)
                {
                    v=v*10+7;
                }
                else
                {
                    if (a>tpr)
                    {
                        printf("\nRaggiunto il limite di cifre decimali\nLe cifre successive verranno tagliate!\n");
                        return v;
                    }
                    v+=((float)7/(pow(10,a)));
                    a++;
                }
                break;
            case '8':
                if (a==0)
                {
                    v=v*10+8;
                }
                else
                {
                    if (a>tpr)
                    {
                        printf("\nRaggiunto il limite di cifre decimali\nLe cifre successive verranno tagliate!\n");
                        return v;
                    }
                    v+=((float)8/(pow(10,a)));
                    a++;
                }
                break;
            case '9':
                if (a==0)
                {
                    v=v*10+9;
                }
                else
                {
                    if (a>tpr)
                    {
                        printf("\nRaggiunto il limite di cifre decimali\nLe cifre successive verranno tagliate!\n");
                        return v;
                    }
                    v+=((float)9/(pow(10,a)));
                    a++;
                }
                break;
            default:
                printf("\nLa stringa contiene caratteri non validi! (\"%c\")\nL'operazione verrà arrestata!\n",s[i]);
                return 0;
        }
    }
    if(mz==1)
    {
        v=-1*v;
    }
    switch (tipe)
    {
        case 1:
            if ((v>=-32767)&&(v<=32767))
                return v;
            else
            {
                printf("\nIl valore inserito e' troppo grande o troppo piccolo per essere memorizzato!");
                return 0;
            }
            break;
        case 2:
            if ((v>=-2147483647)&&(v<=2147483647))
                return v;
            else
            {
                printf("\nIl valore inserito e' troppo grande o troppo piccolo per essere memorizzato!");
                return 0;
            }
            break;
        default:
            return v;
            break;
    }
    return v;
}

int lint ()
{
    char s[65];
    int v=0;

    fflush(stdin);
    scanf("%s",&s);
    v=valc(s,1);
    return v;
}

long llong ()
{
    char s[65];
    long v=0;

    fflush(stdin);
    scanf("%s",&s);
    v=valc(s,2);
    return v;
}

float lfloat ()
{
    char s[65];
    float v=0.0000000;

    fflush(stdin);
    scanf("%s",&s);
    v=valc(s,3);
    return v;
}

double ldouble ()
{
    char s[65];
    double v=0.00000000000000;

    fflush(stdin);
    scanf("%s",&s);
    v=valc(s,4);
    return v;
}
