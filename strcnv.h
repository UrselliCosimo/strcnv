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
