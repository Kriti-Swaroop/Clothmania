#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
struct inup
{
    char user[50],pass[50],p[50];
};
struct men
{
    char brand[50],size[50],colour[50],type[50],desc[500],pcode[10];
    int cost;
};
struct women
{
    char brand[50],size[50],colour[50],type[50],desc[500],pcode[10];
    int cost;
};
int main()
{
    int i,n,no,flag=0;
    FILE *fp,*ptr;
    char cart[55],Name[50];
    t:
    printf("\t\tTo login press 1\n\t\tIf you don't have a shopping cart,press 2 to signup\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            {
                login:
                system("cls");
                struct inup log,l;
                fflush(stdin);
                printf("\nEnter username:\n");
                gets(log.user);
                fflush(stdin);
                printf("\nEnter password:\n");
                gets(log.pass);
                fflush(stdin);
                fp=fopen("logindetail.txt","rb");
                while(fread(&l,sizeof(l),1,fp)!=EOF)
                {
                    if(feof(fp))
                    {
                        break;
                    }
                    if(strcmp(l.user,log.user)==0 && strcmp(l.pass,log.pass)==0)
                    {
                        flag++;
                        printf("\n\t\t\t\t\t\tWelcome back to the world of Clothmania %s!\n\t\t\t\t\t\t\tPress any key to dive into our world\n",log.user);
                        _getch();
                        goto Gender;
                    }
                }
                fclose(fp);
                strcpy(Name,log.user);
                if(flag==0)
                {
                    printf("\nEither the username or password is wrong\nPress any key to try again\n");
                    _getch();
                    goto login;
                }
                break;
            }
        case 2:
            {
                system("cls");
                struct inup sign;
                Top:
                fflush(stdin);
                printf("\nEnter username:\n");
                gets(sign.user);
                fflush(stdin);
                printf("\nEnter password:\n");
                gets(sign.pass);
                fflush(stdin);
                printf("\nConfirm password:\n");
                gets(sign.p);
                fflush(stdin);
                if(strcmp(sign.pass,sign.p)==0)
                {
                    printf("\n\t\t\t\t\t\tWelcome to the world of Clothmania %s!\n\t\t\t\t\t\t\tPress any key to dive into our world",sign.user);
                    _getch();
                }
                else
                {
                    printf("\nPasswords don't match\n");
                    goto Top;
                }
                fp=fopen("logindetail.txt","ab");
                if(fp!=NULL)
                {
                    fwrite(&sign,sizeof(sign),1,fp);
                }
                fclose(fp);
                for(i=0;sign.user[i]!='\0';i++)
                    {
                        if(sign.user[i]==' ')
                        {
                            cart[i]='_';
                        }
                        else
                        {
                            cart[i]=sign.user[i];
                        }
                    }
                    cart[i]='.';
                    cart[i+1]='t';
                    cart[i+2]='x';
                    cart[i+3]='t';
                    cart[i+4]='\0';
                    strcpy(Name,sign.user);
            }break;
        default:
            {
                printf("You have pressed a wrong key.Press any key and try again\n");
                _getch();
                goto t;
            }break;
    }
    {
        char cc,cm,cw;
        Gender:
            system("cls");
            printf("Press   M or m for men,\n\tW or w for women,\n\tC or c for cart and\n\tE or e to exit Clothmania\n");
            fflush(stdin);
            scanf("%c", &cc);
            switch(cc)
            {
                case 'M':
                case 'm':
                    {
                        TypeM:
                            system("cls");
                            printf("\t\t\t\t\t\t**DISCLAIMER**\n\t\t\t\t\t'All the prices are in INR'\n\n");
                            printf("Enter   T or t for t-shirt,\n\tS or s for shirt,\n\tB or b for blazer, \n\tF or f for suits, \n\tJ or j for jeans, \n\tI or i for Indianwear or \n\t0 to go to home\n");
                            fflush(stdin);
                            scanf("%c",&cm);
                            if(cm=='0')
                            {
                                goto Gender;
                            }
                            switch(cm)
                            {
                                case 'T':
                                case 't':
                                {
                                    system("cls");
                                    struct men m;
                                    fp=fopen("men.txt", "rb");
                                    int num=1;
                                    while(fread(&m,sizeof(m),1,fp)!=EOF)
                                    {
                                        if(feof(fp))
                                        {
                                            break;
                                        }
                                        if(strcmp(m.type,"T-shirt")==0)
                                        {
                                            printf("%d\n",num);
                                            printf("Type: %s\nBrand: %s\nPrice: %d\nSize: %s\nColour: %s\nDescription: %s\n",m.type,m.brand,m.cost,m.size,m.colour,m.desc);
                                            printf("\n\n\n");
                                            num++;
                                        }
                                    }
                                    fclose(fp);
                                    printf("Enter the corresponding serial no of the item you wish to add to your cart or \nPress 0 to go to Men's section:\n");
                                    scanf("%d",&no);
                                    if(no==0)
                                    {
                                        goto TypeM;
                                    }
                                    fp=fopen("men.txt", "rb");
                                    num=1;
                                    while(fread(&m,sizeof(m),1,fp)!=EOF)
                                    {
                                        if(strcmp(m.type,"T-shirt")==0)
                                        {
                                            if(num==no)
                                            {
                                                ptr=fopen(cart,"ab");
                                                {
                                                    fflush(stdin);
                                                    printf("Enter the size of item:\n");
                                                    gets(m.size);
                                                    fflush(stdin);
                                                    fwrite(&m,sizeof(m),1,ptr);
                                                    fclose(ptr);
                                                    break;
                                                }
                                            }
                                            num++;
                                        }
                                    }
                                    fclose(fp);
                                    printf("Item number %d added to cart\nPress any key to proceed",no);
                                    _getch();
                                    goto Gender;
                                }break;
                                case 'S':
                                case 's':
                                {
                                    system("cls");
                                    struct men m;
                                    fp=fopen("men.txt", "rb");
                                    int num=1;
                                    while(fread(&m,sizeof(m),1,fp)!=EOF)
                                    {
                                        if(feof(fp))
                                        {
                                            break;
                                        }
                                        if(strcmp(m.type,"Shirt")==0)
                                        {
                                            printf("%d\n",num);
                                            printf("Type: %s\nBrand: %s\nPrice: %d\nSize: %s\nColour: %s\nDescription: %s\n",m.type,m.brand,m.cost,m.size,m.colour,m.desc);
                                            printf("\n\n\n");
                                            num++;
                                        }
                                    }
                                    fclose(fp);
                                    printf("Enter the corresponding serial no of the item you wish to add to your cart or \nPress 0 to go to Men's section:\n");
                                    scanf("%d",&no);
                                    if(no==0)
                                    {
                                        goto TypeM;
                                    }
                                    fp=fopen("men.txt", "rb");
                                    num=1;
                                    while(fread(&m,sizeof(m),1,fp)!=EOF)
                                    {
                                        if(strcmp(m.type,"Shirt")==0)
                                        {
                                            if(num==no)
                                            {
                                                ptr=fopen(cart,"ab");
                                                {
                                                    fflush(stdin);
                                                    printf("Enter the size of item:\n");
                                                    gets(m.size);
                                                    fflush(stdin);
                                                    fwrite(&m,sizeof(m),1,ptr);
                                                    fclose(ptr);
                                                    break;
                                                }
                                            }
                                            num++;
                                        }
                                    }
                                    fclose(fp);
                                    printf("Item number %d added to cart\nPress any key to proceed",no);
                                    _getch();
                                    goto Gender;
                                }break;
                                case 'B':
                                case 'b':
                                {
                                    system("cls");
                                    struct men m;
                                    fp=fopen("men.txt", "rb");
                                    int num=1;
                                    while(fread(&m,sizeof(m),1,fp)!=EOF)
                                    {
                                        if(feof(fp))
                                        {
                                            break;
                                        }
                                        if(strcmp(m.type,"Blazer")==0)
                                        {
                                            printf("%d\n",num);
                                            printf("Type: %s\nBrand: %s\nPrice: %d\nSize: %s\nColour: %s\nDescription: %s\n",m.type,m.brand,m.cost,m.size,m.colour,m.desc);
                                            printf("\n\n\n");
                                            num++;
                                        }
                                    }
                                    fclose(fp);
                                    printf("Enter the corresponding serial no of the item you wish to add to your cart or \nPress 0 to go to Men's section:\n");
                                    scanf("%d",&no);
                                    if(no==0)
                                    {
                                        goto TypeM;
                                    }
                                    fp=fopen("men.txt", "rb");
                                    num=1;
                                    while(fread(&m,sizeof(m),1,fp)!=EOF)
                                    {
                                        if(strcmp(m.type,"Blazer")==0)
                                        {
                                            if(num==no)
                                            {
                                                ptr=fopen(cart,"ab");
                                                {
                                                    fflush(stdin);
                                                    printf("Enter the size of item:\n");
                                                    gets(m.size);
                                                    fflush(stdin);
                                                    fwrite(&m,sizeof(m),1,ptr);
                                                    fclose(ptr);
                                                    break;
                                                }
                                            }
                                            num++;
                                        }
                                    }
                                    fclose(fp);
                                    printf("Item number %d added to cart\nPress any key to proceed",no);
                                    _getch();
                                    goto Gender;
                                }break;
                                case 'F':
                                case 'f':
                                {
                                    system("cls");
                                    struct men m;
                                    fp=fopen("men.txt", "rb");
                                    int num=1;
                                    while(fread(&m,sizeof(m),1,fp)!=EOF)
                                    {
                                        if(feof(fp))
                                        {
                                            break;
                                        }
                                        if(strcmp(m.type,"Suit")==0)
                                        {
                                            printf("%d\n",num);
                                            printf("Type: %s\nBrand: %s\nPrice: %d\nSize: %s\nColour: %s\nDescription: %s\n",m.type,m.brand,m.cost,m.size,m.colour,m.desc);
                                            printf("\n\n\n");
                                            num++;
                                        }
                                    }
                                    fclose(fp);
                                    printf("Enter the corresponding serial no of the item you wish to add to your cart or \nPress 0 to go to Men's section:\n");
                                    scanf("%d",&no);
                                    if(no==0)
                                    {
                                        goto TypeM;
                                    }
                                    fp=fopen("men.txt", "rb");
                                    num=1;
                                    while(fread(&m,sizeof(m),1,fp)!=EOF)
                                    {
                                        if(strcmp(m.type,"Suit")==0)
                                        {
                                            if(num==no)
                                            {
                                                ptr=fopen(cart,"ab");
                                                {
                                                    fflush(stdin);
                                                    printf("Enter the size of item:\n");
                                                    gets(m.size);
                                                    fflush(stdin);
                                                    fwrite(&m,sizeof(m),1,ptr);
                                                    fclose(ptr);
                                                    break;
                                                }
                                            }
                                            num++;
                                        }
                                    }
                                    fclose(fp);
                                    printf("Item number %d added to cart\nPress any key to proceed",no);
                                    _getch();
                                    goto Gender;
                                }break;
                                case 'J':
                                case 'j':
                                {
                                    system("cls");
                                    struct men m;
                                    fp=fopen("men.txt", "rb");
                                    int num=1;
                                    while(fread(&m,sizeof(m),1,fp)!=EOF)
                                    {
                                        if(feof(fp))
                                        {
                                            break;
                                        }
                                        if(strcmp(m.type,"Jeans")==0)
                                        {
                                            printf("%d\n",num);
                                            printf("Type: %s\nBrand: %s\nPrice: %d\nSize: %s\nColour: %s\nDescription: %s\n",m.type,m.brand,m.cost,m.size,m.colour,m.desc);
                                            printf("\n\n\n");
                                            num++;
                                        }
                                    }
                                    fclose(fp);
                                    printf("Enter the corresponding serial no of the item you wish to add to your cart or \nPress 0 to go to Men's section:\n");
                                    scanf("%d",&no);
                                    if(no==0)
                                    {
                                        goto TypeM;
                                    }
                                    fp=fopen("men.txt", "rb");
                                    num=1;
                                    while(fread(&m,sizeof(m),1,fp)!=EOF)
                                    {
                                        if(strcmp(m.type,"Jeans")==0)
                                        {
                                            if(num==no)
                                            {
                                                ptr=fopen(cart,"ab");
                                                {
                                                    fflush(stdin);
                                                    printf("Enter the size of item:\n");
                                                    gets(m.size);
                                                    fflush(stdin);
                                                    fwrite(&m,sizeof(m),1,ptr);
                                                    fclose(ptr);
                                                    break;
                                                }
                                            }
                                            num++;
                                        }
                                    }
                                    fclose(fp);
                                    printf("Item number %d added to cart\nPress any key to proceed",no);
                                    _getch();
                                    goto Gender;
                                }break;
                                case 'I':
                                case 'i':
                                {
                                    system("cls");
                                    struct men m;
                                    fp=fopen("men.txt", "rb");
                                    int num=1;
                                    while(fread(&m,sizeof(m),1,fp)!=EOF)
                                    {
                                        if(feof(fp))
                                        {
                                            break;
                                        }
                                        if(strcmp(m.type,"Indianwear")==0)
                                        {
                                            printf("%d\n",num);
                                            printf("Type: %s\nBrand: %s\nPrice: %d\nSize: %s\nColour: %s\nDescription: %s\n",m.type,m.brand,m.cost,m.size,m.colour,m.desc);
                                            printf("\n\n\n");
                                            num++;
                                        }
                                    }
                                    fclose(fp);
                                    printf("Enter the corresponding serial no of the item you wish to add to your cart or \nPress 0 to go to Men's section:\n");
                                    scanf("%d",&no);
                                    if(no==0)
                                    {
                                        goto TypeM;
                                    }
                                    fp=fopen("men.txt", "rb");
                                    num=1;
                                    while(fread(&m,sizeof(m),1,fp)!=EOF)
                                    {
                                        if(strcmp(m.type,"Indianwear")==0)
                                        {
                                            if(num==no)
                                            {
                                                ptr=fopen(cart,"ab");
                                                {
                                                    fflush(stdin);
                                                    printf("Enter the size of item:\n");
                                                    gets(m.size);
                                                    fflush(stdin);
                                                    fwrite(&m,sizeof(m),1,ptr);
                                                    fclose(ptr);
                                                    break;
                                                }
                                            }
                                            num++;
                                        }
                                    }
                                    fclose(fp);
                                    printf("Item number %d added to cart\nPress any key to proceed",no);
                                    _getch();
                                    goto Gender;
                                }break;
                                default:
                                {
                                    printf("You have pressed a wrong key.Press any key and try again\n");
                                    _getch();
                                    goto TypeM;
                                }break;
                            }
                    }
                    break;
                case 'W':
                case 'w':
                {
                    TypeW:
                        system("cls");
                        printf("\t\t\t\t\t\t**DISCLAIMER**\n\t\t\t\t\t'All the prices are in INR'\n\n");
                        printf("Enter   T or t for top, \n\tS or s for shirt, \n\tD or d for dresses, \n\tF or f for skirts, \n\tJ or j for jeans, \n\tI or i for Indianwear or \n\t0 to go to home\n");
                        fflush(stdin);
                        scanf("%c",&cw);
                        if(cw=='0')
                        {
                            goto Gender;
                        }
                        switch(cw)
                        {
                            case 'T':
                            case 't':
                            {
                                system("cls");
                                struct women w;
                                fp=fopen("women.txt", "rb");
                                int num=1;
                                while(fread(&w,sizeof(w),1,fp)!=EOF)
                                {
                                    if(feof(fp))
                                    {
                                        break;
                                    }
                                    if(strcmp(w.type,"Top")==0)
                                    {
                                        printf("%d\n",num);
                                        printf("Type: %s\nBrand: %s\nPrice: %d\nSize: %s\nColour: %s\nDescription: %s\n",w.type,w.brand,w.cost,w.size,w.colour,w.desc);
                                        printf("\n\n\n");
                                        num++;
                                    }
                                }
                                fclose(fp);
                                printf("Enter the corresponding serial no of the item you wish to add to your cart or \nPress 0 to go to Women's section:\n");
                                scanf("%d",&no);
                                if(no==0)
                                {
                                    goto TypeW;
                                }
                                fp=fopen("women.txt", "rb");
                                num=1;
                                while(fread(&w,sizeof(w),1,fp)!=EOF)
                                {
                                    if(strcmp(w.type,"Top")==0)
                                    {
                                        if(num==no)
                                        {
                                            ptr=fopen(cart,"ab");
                                            {
                                                fflush(stdin);
                                                printf("Enter the size of item:\n");
                                                gets(w.size);
                                                fflush(stdin);
                                                fwrite(&w,sizeof(w),1,ptr);
                                                fclose(ptr);
                                                break;
                                            }
                                        }
                                        num++;
                                    }
                                }
                                fclose(fp);
                                printf("Item number %d added to cart\nPress any key to proceed",no);
                                _getch();
                                goto Gender;
                            }break;
                            case 'S':
                            case 's':
                            {
                                system("cls");
                                struct women w;
                                fp=fopen("women.txt", "rb");
                                int num=1;
                                while(fread(&w,sizeof(w),1,fp)!=EOF)
                                {
                                    if(feof(fp))
                                    {
                                        break;
                                    }
                                    if(strcmp(w.type,"Shirt")==0)
                                    {
                                        printf("%d\n",num);
                                        printf("Type: %s\nBrand: %s\nPrice: %d\nSize: %s\nColour: %s\nDescription: %s\n",w.type,w.brand,w.cost,w.size,w.colour,w.desc);
                                        printf("\n\n\n");
                                        num++;
                                    }
                                }
                                fclose(fp);
                                printf("Enter the corresponding serial no of the item you wish to add to your cart or \nPress 0 to go to Women's section:\n");
                                scanf("%d",&no);
                                if(no==0)
                                {
                                    goto TypeW;
                                }
                                fp=fopen("women.txt", "rb");
                                num=1;
                                while(fread(&w,sizeof(w),1,fp)!=EOF)
                                {
                                    if(num==no)
                                    {
                                        ptr=fopen(cart,"ab");
                                        {
                                            fflush(stdin);
                                            printf("Enter the size of item:\n");
                                            gets(w.size);
                                            fflush(stdin);
                                            fwrite(&w,sizeof(w),1,ptr);
                                            fclose(ptr);
                                            break;
                                        }
                                    }
                                    num++;
                                }
                                fclose(fp);
                                printf("Item number %d added to cart\nPress any key to proceed",no);
                                _getch();
                                goto Gender;
                            }break;
                            case 'D':
                            case 'd':
                            {
                                system("cls");
                                struct women w;
                                fp=fopen("women.txt", "rb");
                                int num=1;
                                while(fread(&w,sizeof(w),1,fp)!=EOF)
                                {
                                    if(feof(fp))
                                    {
                                        break;
                                    }
                                    if(strcmp(w.type,"Dress")==0)
                                    {
                                        printf("%d\n",num);
                                        printf("Type: %s\nBrand: %s\nPrice: %d\nSize: %s\nColour: %s\nDescription: %s\n",w.type,w.brand,w.cost,w.size,w.colour,w.desc);
                                        printf("\n\n\n");
                                        num++;
                                    }
                                }
                                fclose(fp);
                                printf("Enter the corresponding serial no of the item you wish to add to your cart or \nPress 0 to go to Women's section:\n");
                                scanf("%d",&no);
                                if(no==0)
                                {
                                    goto TypeW;
                                }
                                fp=fopen("women.txt", "rb");
                                num=1;
                                while(fread(&w,sizeof(w),1,fp)!=EOF)
                                {
                                    if(strcmp(w.type,"Dress")==0)
                                    {
                                        if(num==no)
                                        {
                                            ptr=fopen(cart,"ab");
                                            {
                                                fflush(stdin);
                                                printf("Enter the size of item:\n");
                                                gets(w.size);
                                                fflush(stdin);
                                                fwrite(&w,sizeof(w),1,ptr);
                                                fclose(ptr);
                                                break;
                                            }
                                        }
                                        num++;
                                    }
                                }
                                fclose(fp);
                                printf("Item number %d added to cart\nPress any key to proceed",no);
                                _getch();
                                goto Gender;
                            }break;
                            case 'F':
                            case 'f':
                            {
                                system("cls");
                                struct women w;
                                fp=fopen("women.txt", "rb");
                                int num=1;
                                while(fread(&w,sizeof(w),1,fp)!=EOF)
                                {
                                    if(feof(fp))
                                    {
                                        break;
                                    }
                                    if(strcmp(w.type,"Skirt")==0)
                                    {
                                        printf("%d\n",num);
                                        printf("Type: %s\nBrand: %s\nPrice: %d\nSize: %s\nColour: %s\nDescription: %s\n",w.type,w.brand,w.cost,w.size,w.colour,w.desc);
                                        printf("\n\n\n");
                                        num++;
                                    }
                                }
                                fclose(fp);
                                printf("Enter the corresponding serial no of the item you wish to add to your cart or \nPress 0 to go to Women's section:\n");
                                scanf("%d",&no);
                                if(no==0)
                                {
                                    goto TypeW;
                                }
                                fp=fopen("women.txt", "rb");
                                num=1;
                                while(fread(&w,sizeof(w),1,fp)!=EOF)
                                {
                                    if(strcmp(w.type,"Skirt")==0)
                                    {
                                        if(num==no)
                                        {
                                            ptr=fopen(cart,"ab");
                                            {
                                                fflush(stdin);
                                                printf("Enter the size of item:\n");
                                                gets(w.size);
                                                fflush(stdin);
                                                fwrite(&w,sizeof(w),1,ptr);
                                                fclose(ptr);
                                                break;
                                            }
                                        }
                                        num++;
                                    }
                                }
                                fclose(fp);
                                printf("Item number %d added to cart\nPress any key to proceed",no);
                                _getch();
                                goto Gender;
                            }break;
                            case 'J':
                            case 'j':
                            {
                                system("cls");
                                struct women w;
                                fp=fopen("women.txt", "rb");
                                int num=1;
                                while(fread(&w,sizeof(w),1,fp)!=EOF)
                                {
                                    if(feof(fp))
                                    {
                                        break;
                                    }
                                    if(strcmp(w.type,"Jeans")==0)
                                    {
                                        printf("%d\n",num);
                                        printf("Type: %s\nBrand: %s\nPrice: %d\nSize: %s\nColour: %s\nDescription: %s\n",w.type,w.brand,w.cost,w.size,w.colour,w.desc);
                                        printf("\n\n\n");
                                        num++;
                                    }
                                }
                                fclose(fp);
                                printf("Enter the corresponding serial no of the item you wish to add to your cart or \nPress 0 to go to Women's section:\n");
                                scanf("%d",&no);
                                if(no==0)
                                {
                                    goto TypeW;
                                }
                                fp=fopen("women.txt", "rb");
                                num=1;
                                while(fread(&w,sizeof(w),1,fp)!=EOF)
                                {
                                    if(strcmp(w.type,"Jeans")==0)
                                    {
                                        if(num==no)
                                        {
                                            ptr=fopen(cart,"ab");
                                            {
                                                fflush(stdin);
                                                printf("Enter the size of item:\n");
                                                gets(w.size);
                                                fflush(stdin);
                                                fwrite(&w,sizeof(w),1,ptr);
                                                fclose(ptr);
                                                break;
                                            }
                                        }
                                        num++;
                                    }
                                }
                                fclose(fp);
                                printf("Item number %d added to cart\nPress any key to proceed",no);
                                _getch();
                                goto Gender;
                            }break;
                            case 'I':
                            case 'i':
                            {
                                system("cls");
                                struct women w;
                                fp=fopen("women.txt", "rb");
                                int num=1;
                                while(fread(&w,sizeof(w),1,fp)!=EOF)
                                {
                                    if(feof(fp))
                                    {
                                        break;
                                    }
                                    if(strcmp(w.type,"Indianwear")==0)
                                    {
                                        printf("%d\n",num);
                                        printf("Type: %s\nBrand: %s\nPrice: %d\nSize: %s\nColour: %s\nDescription: %s\n",w.type,w.brand,w.cost,w.size,w.colour,w.desc);
                                        printf("\n\n\n");
                                        num++;
                                    }
                                }
                                fclose(fp);
                                printf("Enter the corresponding serial no of the item you wish to add to your cart or \nPress 0 to go to Women's section:\n");
                                scanf("%d",&no);
                                if(no==0)
                                {
                                    goto TypeW;
                                }
                                fp=fopen("women.txt", "rb");
                                num=1;
                                while(fread(&w,sizeof(w),1,fp)!=EOF)
                                {
                                    if(strcmp(w.type,"Indianwear")==0)
                                    {
                                        if(num==no)
                                        {
                                            ptr=fopen(cart,"ab");
                                            {
                                                fflush(stdin);
                                                printf("Enter the size of item:\n");
                                                gets(w.size);
                                                fflush(stdin);
                                                fwrite(&w,sizeof(w),1,ptr);
                                                fclose(ptr);
                                                break;
                                            }
                                        }
                                        num++;
                                    }
                                }
                                fclose(fp);
                                printf("Item number %d added to cart\nPress any key to proceed",no);
                                _getch();
                                goto Gender;
                            }break;
                            default:
                            {
                                printf("You have pressed a wrong key.Press any key and try again\n");
                                _getch();
                                goto TypeW;
                            }break;
                        }
                }
                break;
                case 'C':
                case 'c':
                {
                    int num=1,sum=0,del;
                    system("cls");
                    printf("Cart of %s\n\n",Name);
                    fp=fopen(cart,"rb");
                    struct women w;
                    while(fread(&w,sizeof(w),1,fp)!=EOF)
                    {
                        if(feof(fp))
                        {
                            break;
                        }
                        printf("%d\n",num);
                        printf("Type: %s\nBrand: %s\nPrice: %d\nSize: %s\nColour: %s\nDescription: %s\n",w.type,w.brand,w.cost,w.size,w.colour,w.desc);
                        printf("\n\n\n");
                        num++;
                        sum+=w.cost;
                    }
                    printf("\n\n\nTotal cost= %d",sum);
                    fclose(fp);
                    printf("\nIf you wish to delete any item from the cart, enter it's corresponding serial number or \nPress 0 to go to home\n");
                    scanf("%d",&del);
                    if(del==0)
                    {
                        goto Gender;
                    }
                    fp=fopen(cart,"rb");
                    ptr=fopen("temp.txt","wb");
                    num=1;
                    while(fread(&w,sizeof(w),1,fp)!=EOF)
                    {
                        if(feof(fp))
                        {
                            break;
                        }
                        if(del!=num)
                        {
                            fwrite(&w,sizeof(w),1,ptr);
                        }
                        num++;
                    }
                    fclose(fp);
                    fclose(ptr);
                    char o[20]="temp.txt";
                    if(remove(cart)==0)
                    {
                        if(rename(o,cart)==0)
                        {
                            printf("Item removed from cart");
                            goto Gender;
                        }
                    }
                }break;
                case 'E':
                case 'e':
                    {
                        system("cls");
                        printf("\n\n\n\n\n\t\t\t\t\tHave a nice day! We hope to see you soon!!\n\n\n\n\n");
                        return 0;
                    }
                default:
                {
                    printf("You have pressed a wrong key.Press any key and try again\n");
                    _getch();
                    goto Gender;
                }break;
            }
    }
}
